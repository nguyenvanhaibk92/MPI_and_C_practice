from mpi4py import MPI

# Initialize MPI
comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

# Print "Hello, World!" from each process
print(f"Hello, World! I'm process {rank} of {size}")

# Finalize MPI
MPI.Finalize()

