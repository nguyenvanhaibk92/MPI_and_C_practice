#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
    int npes, rank;
    MPI_Status status;

    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the number of processes and the rank of this process
    MPI_Comm_size(MPI_COMM_WORLD, &npes);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("test\n");
    printf("Number of processes: %d\n", npes);
    printf("Rank: %d\n", rank);

    if (rank == 0) {
        // Data to send
        int a = 7;
        double b = 3.14;
        MPI_Send(&a, 1, MPI_INT, 1, 11, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_DOUBLE, 1, 11, MPI_COMM_WORLD);
    } else if (rank == 1) {
        // Receive data
        int received_int;
        double received_double;

        MPI_Recv(&received_int, 1, MPI_INT, 0, 11, MPI_COMM_WORLD, &status);
        MPI_Recv(&received_double, 1, MPI_DOUBLE, 0, 11, MPI_COMM_WORLD, &status);

        printf("Received int: %d\n", received_int);
        printf("Received double: %f\n", received_double);
    }

    // Finalize MPI
    MPI_Finalize();

    return 0;
}
