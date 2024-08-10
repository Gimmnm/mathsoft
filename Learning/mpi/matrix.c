#include <stdio.h>    
#include <mpi.h>    
  
#define N 4  // 矩阵的行数和列数    
  
// 从文件中读取矩阵和向量  
void read_data(double matrix[N][N], double vector[N]) {  
    FILE *file = fopen("data.txt", "r");  
    if (file == NULL) {  
        printf("Error opening file!\n");  
        return;  
    }  
  
    for (int i = 0; i < N; i++) {  
        for (int j = 0; j < N; j++) {  
            fscanf(file, "%lf", &matrix[i][j]);  
        }  
        fscanf(file, "%lf", &vector[i]);  
    }  
  
    fclose(file);  
}  
  
int main(int argc, char* argv[]) {    
    int rank, size;    
    double matrix[N][N], vector[N], result[N], local_result[N / size];    
  
    MPI_Init(&argc, &argv);    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);    
    MPI_Comm_size(MPI_COMM_WORLD, &size);    
  
    // 在根进程中从文件中读取矩阵和向量  
    if (rank == 0) {    
        read_data(matrix, vector);  
    }    
  
    // 将向量广播到所有进程  
    MPI_Bcast(vector, N, MPI_DOUBLE, 0, MPI_COMM_WORLD);    
  
    // 将矩阵的行分散到所有进程  
    MPI_Scatter(matrix, N * N / size, MPI_DOUBLE, matrix[rank], N * N / size, MPI_DOUBLE, 0, MPI_COMM_WORLD);    
  
    // 每个进程计算其行与向量的点积  
    for (int i = 0; i < N / size; i++) {    
        local_result[i] = 0;    
        for (int j = 0; j < N; j++) {    
            local_result[i] += matrix[rank][j] * vector[j];    
        }    
    }    
  
    // 将局部结果收集到结果向量中  
    MPI_Gather(local_result, N / size, MPI_DOUBLE, result, N / size, MPI_DOUBLE, 0, MPI_COMM_WORLD);    
  
    // 在根进程中打印结果向量  
    if (rank == 0) {    
        printf("Result vector:\n");    
        for (int i = 0; i < N; i++) {    
            printf("%f\n", result[i]);    
        }    
    }    
  
    MPI_Finalize();    
  
    return 0;    
}    