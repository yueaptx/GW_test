#ifndef CoupledDiracSourceTest_H
#define CoupledDiracSourceTest_H

// Moose Includes
#include "FunctionDiracSource.h"

// Forward Declarations
class CoupledDiracSourceTest;
class Function;

template <>
InputParameters validParams<CoupledDiracSourceTest>();

class CoupledDiracSourceTest : public FunctionDiracSource
{
public:
  CoupledDiracSourceTest(const InputParameters & parameters);

  virtual void addPoints() override;

protected:
  virtual Real computeQpResidual() override;

  //Function & _function;
  //Point _p;

private:
  //FEProblemBase & _fe_problem;

  /// The MultiApp this Transfer is transferring data to or from
  int _counter;
  const Real _burgers;
  std::shared_ptr<MultiApp> _multi_app; // store the multiapp "Elasticity"
  std::vector<Point> src_pts{};
  std::vector<Number> src_vals{};
};

#endif // CoupledDiracSourceTest_H
