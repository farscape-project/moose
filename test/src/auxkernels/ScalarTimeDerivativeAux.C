//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ScalarTimeDerivativeAux.h"

registerMooseObject("MooseTestApp", ScalarTimeDerivativeAux);

InputParameters
ScalarTimeDerivativeAux::validParams()
{
  InputParameters params = AuxKernel::validParams();
  params.addClassDescription("The time derivative of the specified "
                             "scalar variable as an auxiliary variable.");
  params.addRequiredCoupledVar("coupled_scalar_variable", "The scalar field");
  params.addParam<Real>("coeff", 1.0, "The constant coefficient");
  return params;
}

ScalarTimeDerivativeAux::ScalarTimeDerivativeAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _v_old(coupledValueOld("coupled_scalar_variable")),
    _v_cur(coupledValue("coupled_scalar_variable")),
    _v_dot(coupledDot("coupled_scalar_variable")),
    _coeff(getParam<Real>("coeff"))
{
}

Real
ScalarTimeDerivativeAux::computeValue()
{
  std::cout << _q_point[_qp] << " _v_old " << _v_old[_qp] << " _v_cur " << _v_cur[_qp] << " _v_dot " << _v_dot[_qp] << std::endl;
  return _coeff * _v_dot[_qp];
}
