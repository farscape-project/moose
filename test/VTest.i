[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 2
  ny = 2
  elem_type = QUAD9
[]

[Variables]
  [A]
    family = NEDELEC_ONE
    order = FIRST
  []
[]

[AuxVariables]
  [P]
    family = NEDELEC_ONE
    order = FIRST
  []
[]

[Kernels]
  [curlcurlA]
    type = VectorFEWave
    variable = A
  []
[]

[Functions]
  [f]
    type = ParsedVectorFunction
    expression_x = y*y*y
  []
[]

[ICs]
  [vic]
    type = VectorFunctionIC
    variable = A
    function = f
  []
[]

[AuxKernels]
  [P]
    type = VectorTimeDerivativeAux
    variable = P
    coupled_vector_variable = A
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
