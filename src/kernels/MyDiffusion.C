//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "MyDiffusion.h"

registerMooseObject("greatWhiteApp", MyDiffusion);

template <>
InputParameters validParams<MyDiffusion>()
{
  InputParameters params = validParams<Diffusion>();
  // Here we will look for a parameter from the input file
  params.addParam<Real>("diffusivity", 1.0, "Diffusivity Coefficient");
  params.addParam<Real>("Uvd", "[eV], vacancy migration energy");
  params.addParam<Real>("kB", 1.3806e-23 ,"m^2kg/s^2/K], Boltzmann constant");
  params.addParam<Real>("eV2J", 1.60218e-19 ,"[J/eV], convert eV to Joules");
  params.addParam<Real>("T", "[K], temperature");
  return params;
}

MyDiffusion::MyDiffusion(const InputParameters & parameters):
    Diffusion(parameters),
    // Initialize our member variable based on a default or input file
    _diffusivity(getParam<Real>("diffusivity")),
    _Uvd(getParam<Real>("Uvd")),
    _kB(getParam<Real>("kB")),
    _eV2J(getParam<Real>("eV2J")),
    _T(getParam<Real>("T")),
    _Dv(_diffusivity * exp(- _Uvd * _eV2J / _kB / _T))
{
}

Real
MyDiffusion::computeQpResidual()
{
  return _Dv * Diffusion::computeQpResidual();
}

Real
MyDiffusion::computeQpJacobian()
{
  //std::cout << "Dv0 = " << _diffusivity << "; Uvd = " << _Uvd << "; kB = " << _kB << "; e2VJ = " << _eV2J << "; Dv = " << _Dv << std::endl;
  return _diffusivity * Diffusion::computeQpJacobian();
}
