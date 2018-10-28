[GlobalParams]
  #displacements = 'disp_x disp_y'
  Uvd=0.61   # [eV], vacancy migration energy
  Uvf=0.67  # [eV], vacancy formation energy
  kB=1.3806e-23  # [m^2kg/s^2/K], Boltzmann constant
  eV2J=1.60218e-19   # [J/eV], convert eV to Joules
  Omega=16.3e-30  # [m^3], atomic volume
  T=600     # [K], temperature
  burgers = 0.28567e-9 # [m], burger's vector magnitude
[]

[Mesh]
  # optionsl Type
  # type=<FileMesh | GeneratedMesh>
  # FileMesh
#  type = GeneratedMesh     # import mesh from file
#  dim = 3
#  xmin = -1e-6
#  xmax = 1e-6
#  ymin = -1e-6
#  ymax = 1e-6
#  zmin = -1e-6
#  zmax = 1e-6
#  nx = 8
#  ny = 8
#  nz = 8
#  elem_type = HEX8

  type = FileMesh
  file = './mesh/block.msh'
  # The MultiAppInterpolationTransfer object only works with ReplicatedMesh
  parallel_type = replicated
  #second_order = true
[]

[Variables]
  [./c]
  order = FIRST
  family = LAGRANGE    #Adds a Linear Lagrange variable by default
  [../]
[]

[Kernels]
  [./diff]
    type = MyDiffusion # A Laplacian operator
    variable = c # Operate on the "pressure" variable from above
    diffusivity = 1.18e-5 # [m^2/s], diffusion coefficient pre-exponential
  [../]

  [./timeDerivative]
    type = TimeDerivative
    variable = c
  #  use_displaced_mesh = true
  [../]
[]

[DiracKernels]
  [./sinkVector]
      type = CoupledDiracSourceTest
      function = 1  # save for future use
      point = '0 0 0' # save for future use
      variable = c
      multi_app = sub
      drop_duplicate_points = false
  [../]
[]

[BCs]
  #[./BC1]
  #  type = CoupledDirichletBC # Simple u=value BC
  #  variable = c
  #  boundary = 5 # Name of a sideset in the mesh, for 3D, top = 3, front = 5
  #  sigN = 3e8 # [Pa], applied normal stress
    #value = 1e-2
#    function = 0.1e-5*1e5
  #[../]
  #[./BC2]
  #  type = CoupledDirichletBC # Simple u=value BC
  #  variable = c
  #  boundary = 0 # Name of a sideset in the mesh, for 3D, bottom = 1, back = 0
#    value = 0
  #  sigN = 3e8
  #[../]
  [./left]
    type = DirichletBC
    variable = c
    boundary = front
    value = 0
  [../]

  [./right]
    type = DirichletBC
    variable = c
    boundary = back
    value = 1e-6
  [../]
[]

[Problem]
   type = FEProblem # This is the "normal" type of Finite Element Problem in MOOSE
  # coord_type = RZ # Axisymmetric RZ
  # rz_coord_axis = X # Which axis the symmetry is around
[]

[Executioner]
  type = Transient # Transient problem
  #type = Steady # Steady state problem
  solve_type = PJFNK #Preconditioned Jacobian Free Newton Krylov
  num_steps = 3
  dt = 1e-3
  petsc_options_iname = '-pc_type -pc_hypre_type' #Matches with the values below
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  execute_on = 'timestep_end'
  exodus = true # Output Exodus format
  # xda = true  #XDA writes out the perfect internal state of all variables, allowing SolutionUserObject to read back in higher order solutions and adapted meshes
[]

[MultiApps]
  [./sub]
    type = TransientMultiApp
    execute_on = timestep_end
    #positions = '0 0 0'
    input_files = 'elasticity_MultiApp1.i'
    sub_cycling = true
    output_sub_cycles = true
    output_in_position = true
  [../]
[]

[Transfers]
  [./tosub]
    type =MultiAppCopyTransfer
    direction = to_multiapp
    multi_app = sub
    source_variable = c
    variable = c_fromMaster
    execute_on = SAME_AS_MULTIAPP
  [../]
[]
