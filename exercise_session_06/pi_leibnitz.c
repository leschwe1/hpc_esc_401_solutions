// idea (Leibnitz): pi/4 1/1 - 1/3 + 1/5 ....
// --> 1 / (( -1*n) 1+(n*2)) (more or less)

// given N = 1000000000 terms to be summed


//a) Each process can take care of N/nproc terms and calculate a partial sum of the series.
//b) Each process will send the result back to the master process.
//c) The master process will add the partial sums and output the result

#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {

    //initialize MPI and get rank as before in ring_3
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // terms to be summed (as above)
    long long N = 1000000000LL;

    //------a) Each process can take care of N/nproc terms and calculate a partial sum of the series.

    //determine range for each process
    long long local_N = N / size;
    long long start = rank * local_N; //start index
    long long end = start + local_N; //end index

    double local_sum = 0.0;

    //compute partial sum
    for (long long i = start; i < end; i++) {
        double term = pow(-1.0, i) / (2.0 * i + 1.0); //with alternating sign
        local_sum += term;
    }

    //------b) Each process will send the result back to the master process.

    //combine the partial results to the global sum with collect
    double global_sum = 0.0;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    //------c) The master process will add the partial sums and output the result
    if (rank == 0) {
        double pi = 4.0 * global_sum;
        printf("Approximation of pi = %.15f\n", pi);
    }

    MPI_Finalize();
    return 0;
}


