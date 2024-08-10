#include <stdio.h>  
#include <mpi.h>  
  
int main(int argc, char* argv[]) {  
    int rank, size, N;  
    long long sum = 0, start, end, total_sum;  
  
    MPI_Init(&argc, &argv);   
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   
    MPI_Comm_size(MPI_COMM_WORLD, &size);   
  
    N = 1000000000;  // replace with your N  
  
    start = rank*(N/size) + 1;  
    end = (rank == size - 1) ? N : (rank + 1)*(N/size);

    //printf("rank %d, start %lld, end %lld\n", rank, start, end);  
  
    for (long long i = start; i <= end; i++) {  
        sum += i;  
    }  
  
    MPI_Reduce(&sum, &total_sum, 1, MPI_LONG_LONG_INT, MPI_SUM, 0, MPI_COMM_WORLD);  
  
    if (rank == 0) {  
        printf("Sum from 1 to %d is %lld\n", N, total_sum);  
    }  
  
    MPI_Finalize();  
  
    return 0;  
}  