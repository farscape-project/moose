//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "VectorTimeDerivativeAux.h"

registerMooseObject("MooseTestApp", VectorTimeDerivativeAux);

InputParameters
VectorTimeDerivativeAux::validParams()
{
  InputParameters params = VectorAuxKernel::validParams();
  params.addClassDescription("The time derivative of the specified "
                             "vector variable as an auxiliary variable.");
  params.addRequiredCoupledVar("coupled_vector_variable", "The vector field");
  params.addParam<Real>("coeff", 1.0, "The constant coefficient");
  return params;
}

VectorTimeDerivativeAux::VectorTimeDerivativeAux(const InputParameters & parameters)
  : VectorAuxKernel(parameters),
    _v_old(coupledVectorValueOld("coupled_vector_variable")),
    _v_cur(coupledVectorValue("coupled_vector_variable")),
    _v_dot(coupledVectorDot("coupled_vector_variable")),
    _coeff(getParam<Real>("coeff"))
{
}

RealVectorValue
VectorTimeDerivativeAux::computeValue()
{
  std::cout << "_v_old " << _v_old[_qp] << " _v_cur " << _v_cur[_qp] << " _v_dot " << _v_dot[_qp] << std::endl;
  return _coeff * _v_dot[_qp];
}
