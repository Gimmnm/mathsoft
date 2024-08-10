#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/cblas.h"

int main(int argc, char *argv[]) {  
    char dummy[128];    // 过滤垃圾字符
    int m = -1;         // 矩阵 A, m x k
    int n = -1;         // 矩阵 B, k x n
    int k = -1;         // 矩阵 C, m x n

// 不启用 alpha 和 beta 功能.
//    double alpha = 1.0;
//    double beta = 0.0;

    double *A;          // 矩阵 A
    double *B;          // 矩阵 B
    double *C;          // 矩阵 C

    clock_t start, end;
    int ret = scanf("row = %d, col = %d", &m, &k);
    if (ret != 2) {  
        fprintf(stderr, "Failed to read matrix size.\n");
        return -1; 
    }

    int lda = k;

    if ((A = (double*)malloc(m * k * sizeof(double))) == NULL) {
        fprintf(stderr, "malloc failed.\n");
        return -1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            ret = scanf("%lf", &A[i * lda + j]);
            if (ret != 1) {  
                fprintf(stderr, "Failed to read matrix elements.\n");  
                return -1;  
            }
        }
    }
    if (fgets(dummy, 128, stdin) == NULL) {
        fprintf(stderr, "Failed to grep dummy.\n");
        return -1;
    }
    ret = scanf("row = %d, col = %d", &k, &n);
    if (ret != 2) {  
        fprintf(stderr, "Failed to read matrix size.\n");  
        return -1;  
    }
    int ldb = n;
    int ldc = n;

    if ((B = (double*)malloc(k * n * sizeof(double))) == NULL || (C = (double*)malloc(m * n * sizeof(double))) == NULL) {
        printf("malloc failed\n");
        return -1;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            ret = scanf("%lf", &B[i * ldb + j]);
            if (ret != 1) {  
                fprintf(stderr, "Failed to read matrix elements.\n");  
                return -1;  
            }
        }
    }

    start = clock();
    // 调用 cblas_dgemm 函数进行矩阵乘法, 约定总是按行存储, 非转置, alpha = 1.0, beta = 0.0.
    // 即 C = A x B.
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1.0, A, lda, B, ldb, 0.0, C, ldc);
    // cblas_dgemm_block(CblasRowMajor, CblasNoTrans, CblasNoTrans,
    //             m, n, k, 1.0, A, lda, B, ldb, 0.0, C, ldc);
    end = clock();
    printf("time is: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
//    输出结果矩阵 C

    int iftest = atoi(argv[1]);
    if (iftest == 1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%f ", C[i * ldc + j]);
            }
            printf("\n");
        
        }
    }

    free(A);
    free(B);
    free(C);
    return 0;
}