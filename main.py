from mpi4py import MPI
import socket

print('test')

# Initialize MPI
comm = MPI.COMM_WORLD
npes = comm.Get_size()
rank = comm.Get_rank()

print(npes)
print(rank)

if rank == 0:
    data = {'a': 7, 'b': 3.14}
    comm.send(data, dest=1, tag=11)
elif rank == 1:
    data = comm.recv(source=0, tag=11)

# Finalize MPI
# MPI.Finalize()

