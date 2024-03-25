//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "AuxKernel.h"

class VectorTimeDerivativeAux : public VectorAuxKernel
{
public:
  static InputParameters validParams();

  VectorTimeDerivativeAux(const InputParameters & parameters);

protected:
  virtual RealVectorValue computeValue() override;

  const VectorVariableValue & _v_old;
  const VectorVariableValue & _v_cur;
  const VectorVariableValue & _v_dot;

  /// scalar coefficient
  Real _coeff;
};