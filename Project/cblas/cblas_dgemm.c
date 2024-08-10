#include "../include/common.h"
#include "include/cblas.h"
#include <pthread.h>

// void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc) {
//     int i, j, k;
//     double temp;
//     for (i = 0; i < M; i++) {
//         for (j = 0; j < N; j++) {
//             temp = 0;
//             for (k = 0; k < K; k++) {
//                 temp += A[i * lda + k] * B[k * ldb + j];
//             }
//             C[i * ldc + j] = alpha * temp + beta * C[i * ldc + j];
//         }
//     }
// }

#define BLOCK_SIZE 64  // 块的大小，适当选择以匹配缓存行大小

// 矩阵B的转置函数
void transposeMatrix(const double *B, double *B_transposed, int K, int N) {
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            B_transposed[j * K + i] = B[i * N + j];
        }
    }
}

// 用于多线程的矩阵乘法的结构体
typedef struct {
    const double *A;
    const double *B_transposed;  // 转置后的B矩阵
    double *C;
    int start_row;
    int end_row;
    int K, N;
    double alpha, beta;
    int lda, ldb, ldc;
} MatrixMultiplyArgs;

// 多线程的矩阵乘法核心函数
void *matrixMultiplyThread(void *arg) {
    MatrixMultiplyArgs *args = (MatrixMultiplyArgs *)arg;
    double temp;
    for (int i = args->start_row; i < args->end_row; i++) {
        for (int j = 0; j < args->N; j++) {
            temp = 0;
            for (int k = 0; k < args->K; k++) {
                temp += args->A[i * args->lda + k] * args->B_transposed[j * args->K + k];
            }
            args->C[i * args->ldc + j] = args->alpha * temp + args->beta * args->C[i * args->ldc + j];
        }
    }
    return NULL;
}

// 矩阵 A, m x k
// 矩阵 B, k x n
// 矩阵 C, m x n

// 改进的矩阵乘法函数
void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc) {
    // 先假设矩阵都是非转置的，即TransA和TransB为CblasNoTrans
    double *B_transposed = (double *)malloc(K * N * sizeof(double));
    transposeMatrix(B, B_transposed, K, N);  // 转置B矩阵以优化内存访问

    int num_threads = 8;  // 可根据实际CPU核心数调整
    pthread_t threads[num_threads];
    MatrixMultiplyArgs args[num_threads];

    int rows_per_thread = M / num_threads;
    int remainder_rows = M % num_threads;

    for (int i = 0; i < num_threads; i++) {
        args[i].A = A;
        args[i].B_transposed = B_transposed;
        args[i].C = C;
        args[i].start_row = i * rows_per_thread;
        args[i].end_row = (i + 1) * rows_per_thread;
        args[i].K = K;
        args[i].N = N;
        args[i].alpha = alpha;
        args[i].beta = beta;
        args[i].lda = lda;
        args[i].ldb = K;  // 由于B已经转置，其'ldb'现在等于K
        args[i].ldc = ldc;
        pthread_create(&threads[i], NULL, matrixMultiplyThread, &args[i]);
    }

    // 处理剩余的行
    if (remainder_rows > 0) {
        MatrixMultiplyArgs remainder_args;
        remainder_args.A = A;
        remainder_args.B_transposed = B_transposed;
        remainder_args.C = C;
        remainder_args.start_row = num_threads * rows_per_thread;
        remainder_args.end_row = M;
        remainder_args.K = K;
        remainder_args.N = N;
        remainder_args.alpha = alpha;
        remainder_args.beta = beta;
        remainder_args.lda = lda;
        remainder_args.ldb = K;
        remainder_args.ldc = ldc;
        matrixMultiplyThread(&remainder_args);
    }

    // 等待所有线程完成
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(B_transposed);
}
