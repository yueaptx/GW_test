//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "greatWhiteTestApp.h"
#include "greatWhiteApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<greatWhiteTestApp>()
{
  InputParameters params = validParams<greatWhiteApp>();
  return params;
}

greatWhiteTestApp::greatWhiteTestApp(InputParameters parameters) : MooseApp(parameters)
{
  greatWhiteTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

greatWhiteTestApp::~greatWhiteTestApp() {}

void
greatWhiteTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  greatWhiteApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"greatWhiteTestApp"});
    Registry::registerActionsTo(af, {"greatWhiteTestApp"});
  }
}

void
greatWhiteTestApp::registerApps()
{
  registerApp(greatWhiteApp);
  registerApp(greatWhiteTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
greatWhiteTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  greatWhiteTestApp::registerAll(f, af, s);
}
extern "C" void
greatWhiteTestApp__registerApps()
{
  greatWhiteTestApp::registerApps();
}
