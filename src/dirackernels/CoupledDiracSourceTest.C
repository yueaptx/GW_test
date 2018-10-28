#include "CoupledDiracSourceTest.h"
#include "Function.h"
#include "MooseVariable.h"

#include "FEProblem.h"
#include "MultiApp.h"
#include "MooseMesh.h"
#include "DiracKernelInfo.h"

#include "DDObject.h"

registerMooseObject("greatWhiteApp", CoupledDiracSourceTest);

template <>
InputParameters
validParams<CoupledDiracSourceTest>()
{
  InputParameters params = validParams<FunctionDiracSource>();
  params.addParam<Real>("burgers", "[m], burger's vector magnitude");
  params.addRequiredParam<MultiAppName>("multi_app", "The name of the MultiApp to use.");
  return params;
}

CoupledDiracSourceTest::CoupledDiracSourceTest(const InputParameters & parameters)
  : FunctionDiracSource(parameters),
    _counter(0),
    _burgers(getParam<Real>("burgers")),
    //_fe_problem(*getCheckedPointerParam<FEProblemBase *>("_fe_problem_base")),
    //_fe_problem is copied from "Transfer.C"
    _multi_app(_c_fe_problem.getMultiApp(getParam<MultiAppName>("multi_app")))
{
}

void
CoupledDiracSourceTest::addPoints()
{
    //--------------------------------------------------------------------------
    // Intialization
    //std::cout<< "The number of number of nodes in each element * number of quadrature points = " << _counter << std::endl;
    src_pts = {};
    src_vals = {};
    _counter = 0;
    int n_points = 0;

    //--------------------------------------------------------------------------
    // Loop over SubApps
    for (int app_i = 0; app_i < 1; app_i ++)
    {
    //--------------------------------------------------------------------------
    // sub_App information
    FEProblemBase & from_problem = _multi_app->appProblemBase(app_i);   // FEProblemBase
    std::shared_ptr<MultiApp> sub_app = from_problem.getMultiApp("modelib"); // store the subApp for "elasticity"
    FEProblemBase & subApp_problem = sub_app->appProblemBase(0);   // FEProblemBase
    const DDObject & DDLoop = subApp_problem.getUserObject<DDObject>("dd");
    src_pts = DDLoop.getLoopNodes();
    src_vals = DDLoop.getNodalClimbVelocity();
    }

    //--------------------------------------------------------------------------
    // Add points
    /*
    for (const auto & src_val : src_vals)
    {
        std::cout << src_val << std::endl;
    }
    */
    for (const Point & src_pt : src_pts)
    {
        //std::cout << src_pt << std::endl;
        n_points++;
        addPoint(src_pt);
    }


}

Real
CoupledDiracSourceTest::computeQpResidual()
{
    _counter += 1;
    if (src_vals.empty())
    {
    return 0;
    }
    else
    {
    return - _test[_i][_qp] * _burgers * src_vals[(_counter-1)/8];
    }
}
