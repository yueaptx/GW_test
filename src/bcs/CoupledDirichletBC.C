//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "CoupledDirichletBC.h"

registerMooseObject("greatWhiteApp", CoupledDirichletBC);

template <>
InputParameters
validParams<CoupledDirichletBC>()
{
  InputParameters params = validParams<NodalBC>();
  //p.addRequiredParam<Real>("value", "Value of the BC");
  params.addParam<Real>("Uvf", "[eV], vacancy formation energy");
  params.addParam<Real>("kB", 1.3806e-23 ,"m^2kg/s^2/K], Boltzmann constant");
  params.addParam<Real>("eV2J", 1.60218e-19 ,"[J/eV], convert eV to Joules");
  params.addParam<Real>("Omega", 16.3e-30 ,"[m^3], atomic volume");
  params.addParam<Real>("T", "[K], temperature");
  params.addParam<Real>("sigN", "[Pa], applied normal stress");
  //p.declareControllable("value");
  params.addClassDescription("Imposes the essential boundary condition $u=g$, where $g$ "
                        "is a constant, controllable value.");
  return params;
}

CoupledDirichletBC::CoupledDirichletBC(const InputParameters & parameters)
  : NodalBC(parameters),
  //_value(getParam<Real>("value")),
  _Uvf(getParam<Real>("Uvf")),
  _kB(getParam<Real>("kB")),
  _eV2J(getParam<Real>("eV2J")),
  _Omega(getParam<Real>("Omega")),
  _T(getParam<Real>("T")),
  _sigN(getParam<Real>("sigN")),
  _c0(exp(- _Uvf * _eV2J / _kB / _T)),
  _cVal(_c0 * exp(_sigN * _Omega / _kB / _T))
{
}

Real
CoupledDirichletBC::computeQpResidual()
{
  //std::cout << _cVal << std::endl;
  return _u[_qp] - _cVal;
}
