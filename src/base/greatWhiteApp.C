#include "greatWhiteApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<greatWhiteApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

greatWhiteApp::greatWhiteApp(InputParameters parameters) : MooseApp(parameters)
{
  greatWhiteApp::registerAll(_factory, _action_factory, _syntax);
}

greatWhiteApp::~greatWhiteApp() {}

void
greatWhiteApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"greatWhiteApp"});
  Registry::registerActionsTo(af, {"greatWhiteApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
greatWhiteApp::registerApps()
{
  registerApp(greatWhiteApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
greatWhiteApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  greatWhiteApp::registerAll(f, af, s);
}
extern "C" void
greatWhiteApp__registerApps()
{
  greatWhiteApp::registerApps();
}
