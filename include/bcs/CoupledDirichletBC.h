//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef COUPLEDDIRICHLETBC_H
#define COUPLEDDIRICHLETBC_H

#include "NodalBC.h"

class CoupledDirichletBC;

template <>
InputParameters validParams<CoupledDirichletBC>();

/**
 * Boundary condition of a Dirichlet type
 *
 * Sets the value in the node
 */
class CoupledDirichletBC : public NodalBC
{
public:
  CoupledDirichletBC(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  /// The parameters for this BC
  Real _Uvf; //[eV], vacancy formation energy
  const Real _kB; // [m^2kg/s^2/K], Boltzmann constant
  const Real _eV2J; // [J/eV], convert eV to Joules
  const Real _Omega; //[m^3], atomic volume
  Real _T; // [K], temperature
  Real _sigN; // [Pa], applied normal stress
  Real _c0; // equilibrium concentation in defect-free crystal
  Real _cVal; // the concentration for Dirichlet BC
  //const Real & _value;
};

#endif /* COUPLEDDIRICHLETBC_H */
