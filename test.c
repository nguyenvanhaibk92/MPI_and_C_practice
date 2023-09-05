#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    int rank, size, i, sum;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    sum = 0;
    for (i = 0; i < argc; i++)
    {
        sum += atoi(argv[i]);
    }

    MPI_Reduce(&sum, NULL, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Sum: %d\n", sum);
    }

    MPI_Finalize();

    return 0;
}