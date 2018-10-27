//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef GREAT_WHITETESTAPP_H
#define GREAT_WHITETESTAPP_H

#include "MooseApp.h"

class greatWhiteTestApp;

template <>
InputParameters validParams<greatWhiteTestApp>();

class greatWhiteTestApp : public MooseApp
{
public:
  greatWhiteTestApp(InputParameters parameters);
  virtual ~greatWhiteTestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs = false);
};

#endif /* GREAT_WHITETESTAPP_H */
