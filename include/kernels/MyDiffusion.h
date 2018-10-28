#ifndef MYDIFFUSION
#define MYDIFFUSION

#include "Diffusion.h"

// Forward Declarations
class MyDiffusion;

template <>
InputParameters validParams<MyDiffusion>();

class MyDiffusion : public Diffusion
{
public:
  MyDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  Real _diffusivity;
  Real _Uvd;
  const Real _kB;
  const Real _eV2J;
  Real _T;
  Real _Dv;
};

#endif // MYDIFFUSION
