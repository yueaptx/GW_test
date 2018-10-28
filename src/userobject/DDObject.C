//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DDObject.h"

// MOOSE includes

registerMooseObject("greatWhiteApp", DDObject);

template <>
InputParameters validParams<DDObject>()

{
  InputParameters params = validParams<GeneralUserObject>();
  params.addParam<Real>("diffusivity", 1.18e-5, "[m^2/s], diffusion coefficient pre-exponential");
  params.addParam<Real>("Uvd", "[eV], vacancy migration energy");
  params.addParam<Real>("Uvf", "[eV], vacancy formation energy");
  params.addParam<Real>("kB", 1.3806e-23 ,"m^2kg/s^2/K], Boltzmann constant");
  params.addParam<Real>("eV2J", 1.60218e-19 ,"[J/eV], convert eV to Joules");
  params.addParam<Real>("Omega", "[m^3], atomic volume");
  params.addParam<Real>("T", "[K], temperature");
  params.addParam<Real>("burgers", "[m], burger's vector magnitude");
  /*
  // Since we are inheriting from a Postprocessor we override this to make sure
  // That MOOSE (and Peacock) know that this object is _actually_ a UserObject
  params.set<std::string>("built_by_action") = "add_user_object";
  */
  return params;
}

DDObject::DDObject(const InputParameters & parameters)
  : GeneralUserObject(parameters),
    //loop0({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}),
    _sys(NULL),
    _var_c(NULL),
    // Set our member scalar value from InputParameters (read from the input file)
    _diffusivity(getParam<Real>("diffusivity")),
    _Uvd(getParam<Real>("Uvd")),
    _Uvf(getParam<Real>("Uvf")),
    _kB(getParam<Real>("kB")),
    _eV2J(getParam<Real>("eV2J")),
    _Omega(getParam<Real>("Omega")),
    _T(getParam<Real>("T")),
    _Dv(_diffusivity * exp(- _Uvd * _eV2J / _kB / _T)),
    _burgers(getParam<Real>("burgers")),
    _c0(exp(- _Uvf * _eV2J / _kB / _T))
{
}


void
DDObject::initialSetup()
{
  /*
  Empty the node vectors
  */
  loopNodes = {};
  sortedLoopNodes = {};
  loop0 = {};

  using namespace model;
  // Create the nodes
  int nNodes = 20;
  for (int i=0; i<nNodes; ++i)
  {
    loop0.push_back(i);
    DN.insertDanglingNode();
  }

  DN.insertLoop(loop0,0.2);

  DN.clearDanglingNodes();

  //DN.printLoops();
  /*
  Read the vacancy concentration
  */
  _sys = &_fe_problem.getSystem("c_fromMaster");	// getSystem() is obtained from line 3809 in <FEProblemBase.C>
  _var_c = &_fe_problem.getStandardVariable(0, "c_fromMaster");

  /*
  Read the variable/auxvarible names
  */
  _stressCompName = _fe_problem.getVariableNames();

  /*
  insert the loop nodes
  */
  double loopRadius = 5e-7;
  for (int i = 0; i < nNodes; i++)
  {
  	Point temp(loopRadius * std::cos(2*PI/nNodes*i), loopRadius * -std::sin(2*PI/nNodes*i),0);
  	loopNodes.push_back(temp);
  }

  /*
  sort the nodes based on <loop> object
  */
  for (const auto& loop : DN.LoopObserverType::loops())
  {
    const Dloop * currentLoop = loop.second;
    for (const auto& link : currentLoop->linkSequence())
    {
       Point currentNode = loopNodes[link->source()->sID];
       sortedLoopNodes.push_back(currentNode);
    }
  }
}

void
DDObject::initialize()
{
//std::cout << "The DDObject is initialized!" << std::endl;
}

void
DDObject::execute()
{
    // Empty the velocity vector
    nodalClimbVelocity = {};

    //bool lineTension = 0; // 1: use Eq.32 in [Gu, 2015] for _Fcl; 0: use (sigma*b)xksi*n
    //bool infinteMedium = 0; // 1: use Eq. 8 in [Bako, 2011] for vcl; 0: replace c_inf by c(x)
    TypeTensor<Real> stressTensor;
    //Real stress[] = {0,0,0,0,0,0,0,0,3e8};

    TypeVector<Real> Burgers;  // unit burgers vector * b
    Burgers(0) = _burgers / std::sqrt(3);
    Burgers(1) = _burgers / std::sqrt(3);
    Burgers(2) = _burgers / std::sqrt(3);

    using namespace model;
    for (const auto& loop : DN.LoopObserverType::loops())
    {
      const Dloop * currentLoop = loop.second;
      //currentLoop->printLoop();
      for (const auto& link : currentLoop->linkSequence())
      {
         Point currentNode = loopNodes[link->source()->sID];
         Point prevNode = loopNodes[link->prev->source()->sID];
         Point nextNode = loopNodes[link->sink()->sID];
         Real dl1 = (nextNode - currentNode).norm();
         Real dl2 = (currentNode - prevNode).norm();
         Real dl = (dl1 + dl2)/2;

         TypeVector<Real> dp1 = (nextNode - currentNode) / dl1;
         TypeVector<Real> dp2 = (currentNode - prevNode) / dl2;
         TypeVector<Real> dp = (dp1 + dp2) / 2;

         TypeVector<Real> ksi = dp / dp.norm(); // line direction

         TypeVector<Real> n = Burgers.cross(ksi) / _burgers;  // glide plane normal vector

         std::vector<Number> stressComp = {};
         for (int i = 1; i < _stressCompName.size(); i++)
         {
           System * _sysTem = &_fe_problem.getSystem(_stressCompName[i]);
           MooseVariable * _varTem = &_fe_problem.getStandardVariable(0, _stressCompName[i]);
           stressComp.push_back(_sysTem->point_value(_varTem->number(), currentNode, false));
         }

         //std::cout << "The stress components are " << std::endl;
         int index = 0;
         for (int i = 0; i < 3; i++)
         {
             for (int j = 0; j < 3; j++)
             {
                 stressTensor(i,j) = stressComp[index];
                 //std::cout << stressComp[index] << ", ";
                 index++;
             }
             //std::cout << std::endl;
         }

         Real Fcl = (stressTensor * Burgers).cross(ksi) * n;

         Real ceq = _c0 * std::exp(Fcl * _Omega / _kB / _T / _burgers);

         // Interpolate the concentration on loop nodes
         Number c_field = _sys->point_value(_var_c->number(), currentNode, false);
         // Compute the climb velocity from concentration field
         Number vc = 2 * PI * _Dv / _burgers / std::log(2e-6 / 8 / _burgers) * (ceq - c_field);

         nodalClimbVelocity.push_back(vc * dl);
         std::cout << "The value on the point " << currentNode << " is " << vc << std::endl;

         //std::cout << "The source is " << link->source()->sID << ", The sink is " << link->sink()->sID << std::endl;
      }
    }

    /*
    int i = 0;
    for (const auto & loop_node : loopNodes)
    {
    Real dl1 = (loopNodes[(i==loopNodes.size()-1 ? 0 : i+1)] - loopNodes[i]).norm();
    Real dl2 = (loopNodes[i] - loopNodes[(i==0 ? loopNodes.size()-1 : i-1)]).norm();
    Real dl = (dl1 + dl2)/2;

    TypeVector<Real> dp1 = (loopNodes[(i==loopNodes.size()-1 ? 0 : i+1)] - loopNodes[i]) / dl1;
    TypeVector<Real> dp2 = (loopNodes[i] - loopNodes[(i==0 ? loopNodes.size()-1 : i-1)]) / dl2;
    TypeVector<Real> dp = (dp1 + dp2) / 2;

    TypeVector<Real> ksi = dp / dp.norm(); // line direction

    TypeVector<Real> n = Burgers.cross(ksi) / _burgers;  // glide plane normal vector

    std::vector<Number> stressComp = {};
    for (int i = 1; i < _stressCompName.size(); i++)
    {
      System * _sysTem = &_fe_problem.getSystem(_stressCompName[i]);
      MooseVariable * _varTem = &_fe_problem.getStandardVariable(0, _stressCompName[i]);
      stressComp.push_back(_sysTem->point_value(_varTem->number(), loop_node, false));
    }

    std::cout << "The stress components are " << std::endl;
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            stressTensor(i,j) = stressComp[index];
            std::cout << stressComp[index] << ", ";
            index++;
        }
        std::cout << std::endl;
    }

    Real Fcl = (stressTensor * Burgers).cross(ksi) * n;

    Real ceq = _c0 * std::exp(Fcl * _Omega / _kB / _T / _burgers);

    // Interpolate the concentration on loop nodes
    Number c_field = _sys->point_value(_var_c->number(), loop_node, false);
    // Compute the climb velocity from concentration field
    Number vc = 2 * PI * _Dv / _burgers / std::log(2e-6 / 8 / _burgers) * (ceq - c_field);

    nodalClimbVelocity.push_back(vc * dl);
    std::cout << "The value on the point " << loop_node << " is " << vc << std::endl;

    i++;
    };
    */
    std::cout << "The DDObject is executed!" << std::endl;

}
