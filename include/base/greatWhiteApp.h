//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef GREAT_WHITEAPP_H
#define GREAT_WHITEAPP_H

#include "MooseApp.h"

class greatWhiteApp;

template <>
InputParameters validParams<greatWhiteApp>();

class greatWhiteApp : public MooseApp
{
public:
  greatWhiteApp(InputParameters parameters);
  virtual ~greatWhiteApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);

  static void printLogo();
};

#endif /* GREAT_WHITEAPP_H */
