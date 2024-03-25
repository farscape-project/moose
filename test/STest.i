[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 2
  ny = 2
  elem_type = QUAD9
[]

[Variables]
  [A]
    family = MONOMIAL
    order = FIRST
  []
[]

[AuxVariables]
  [P]
    family = MONOMIAL
    order = FIRST
  []
[]

[Kernels]
  [laplA]
    type = Diffusion
    variable = A
  []
  [dAdt]
    type = TimeDerivative
    variable = A
  []
[]

[Functions]
  [f]
    type = ParsedFunction
    expression = y*y*y
  []
[]

[ICs]
  [ic]
    type = FunctionIC
    variable = A
    function = f
  []
[]

[AuxKernels]
  [Q]
    type = TimeDerivativeAux
    variable = P
    functor = A
    execute_on = timestep_end
  []
  [P]
    type = ScalarTimeDerivativeAux
    variable = P
    coupled_scalar_variable = A
    execute_on = timestep_end
  []
[]

[Executioner]
  type = Transient
  solve_type = Linear
  petsc_options_iname = -pc_type
  petsc_options_value = lu
  start_time = 0.0
  end_time = 0.1
  dt = 0.1
[]
