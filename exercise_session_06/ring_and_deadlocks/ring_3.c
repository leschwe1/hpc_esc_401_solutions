#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes and rank of the process
    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // create the topology with the periodic boundary
    int dims[1] = {size};
    int periods[1] = {1}; 
    MPI_Comm comm_cart;
    MPI_Cart_create(MPI_COMM_WORLD, 1, dims, periods, 1, &comm_cart);
    MPI_Comm_rank(comm_cart, &my_rank);

    int my_sum = 0;

    int send_rank = my_rank;  // Send    buffer
    int recv_rank = 0;        // Receive buffer


    // adapted ranks
    int left_rank, right_rank;
    MPI_Cart_shift(comm_cart, 0, 1, &left_rank, &right_rank);


    // set this to 2 as we have two operations per iterations (receive and send)
    MPI_Request requests[2];


    // Loop over the number of processes
    //     send to right, receive from left
    //     update the send buffer
    //     update the local sum
    for (int i = 0; i < size; i++) {
        MPI_Irecv(&recv_rank, 1, MPI_INT, left_rank, 0, comm_cart, &requests[0]);
        MPI_Isend(&send_rank, 1, MPI_INT, right_rank, 0, comm_cart, &requests[1]);
        MPI_Waitall(2, requests, MPI_STATUSES_IGNORE);
        my_sum += recv_rank;
        send_rank = recv_rank;
    }

    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    // Finalize the MPI environment.
    MPI_Finalize();
}
