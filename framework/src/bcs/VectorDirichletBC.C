//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "VectorDirichletBC.h"

registerMooseObject("MooseApp", VectorDirichletBC);
registerMooseObjectRenamed("MooseApp",
                           LagrangeVecDirichletBC,
                           "05/01/2019 00:01",
                           VectorDirichletBC);

InputParameters
VectorDirichletBC::validParams()
{
  InputParameters params = VectorNodalBC::validParams();
  params.addRequiredParam<RealVectorValue>("values",
                                           "The values the components must take on the boundary");
  params.declareControllable("values");
  params.addClassDescription(
      "Imposes the essential boundary condition $\\vec{u}=\\vec{g}$, where $\\vec{g}$ "
      "are constant, controllable values.");
  return params;
}

VectorDirichletBC::VectorDirichletBC(const InputParameters & parameters)
  : VectorNodalBC(parameters), _values(getParam<RealVectorValue>("values"))
{
}

RealVectorValue
VectorDirichletBC::computeQpResidual()
{
  unsigned int _qp;
  const QBase * const & _qrule(_assembly.qRuleFace());
  const MooseArray<Point> & _q_point(_assembly.qPointsFace());
  const MooseArray<Point> & _normals(_assembly.normals());

  std::cout << _assembly.elem() << " " << _assembly.side() << " " << _assembly.sideElem() << std::endl;

  return _u - _values;
}
