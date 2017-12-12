import numpy as np
from petsc4py import PETSc

USE_MONITORS = True
N = 2

def residual_function(snes, x, residual):
    '''
    :param petsc4py.PETSc.SNES snes:
    :param petsc4py.PETSc.Vec x:
    :param petsc4py.PETSc.Vec f:
        Residual vector
    '''
    # Get X array information
    x = np.array(x)
    # Compute the problem
    y = np.array([
        x[1] - np.log10(x[0]),
        x[0] + x[1] - 1.0,
    ])
    # Copy the solution back to the PETSc' residual vector
    residual[:] = y

snes = PETSc.SNES().create()
r = PETSc.Vec().createSeq(N)  # residual vector
x = PETSc.Vec().createSeq(N)  # solution vector
b = PETSc.Vec().createSeq(N)  # right-hand side
snes.setFunction(residual_function, r)

if USE_MONITORS:
    def _solver_monitor(snes, its, fnorm):
        print('[NonLinear Solver] %s Residual function norm %s' % (its, fnorm,))
    snes.setMonitor(_solver_monitor)
    def _linear_solver_monitor(snes, its, fnorm):
        print('[Linear Solver] %s Residual function norm %s' % (its, fnorm,))
    snes.ksp.setMonitor(_linear_solver_monitor)

# Setup the Jacobian structure using DMShell
# from scipy.sparse.csr import csr_matrix
# dm = PETSc.DMShell().create()
# j_structure = csr_matrix(np.ones(shape=(N,N)))
# csr = (j_structure.indptr, j_structure.indices, j_structure.data)
# jac = PETSc.Mat().createAIJWithArrays(j_structure.shape, csr)
# dm.setMatrix(jac)
# snes.setDM(dm)

# Setup the Jacobian structure using DMDA
dmda = PETSc.DMDA().create([N], dof=1, stencil_width=2, stencil_type='star')
snes.setDM(dmda)

# Setup the initial guess
initial_guess = 7.0 * np.ones(shape=(N))
x.setArray(initial_guess)
# Setup the B vector
b.set(0)
snes.solve(b, x)
solution = np.array(x)

assert np.allclose(solution, [1.0, 0.0], atol=1e-6)
