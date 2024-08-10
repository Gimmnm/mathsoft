#include "../include/common.h"

// Helper function to find the next power of 2 greater than or equal to n
int nextPowerOfTwo(int n) {
    return pow(2, ceil(log2(n)));
}

// Function to pad the matrix to the next power of two
double* padMatrix(double* A, int n, int new_n) {
    double* P = (double*)calloc(new_n * new_n, sizeof(double));  // Allocate and initialize to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            P[i * new_n + j] = A[i * n + j];
        }
    }
    return P;
}

void add(double* A, double* B, double* C, int n) {
    for (int i = 0; i < n * n; i++) {
        C[i] = A[i] + B[i];
    }
}

void subtract(double* A, double* B, double* C, int n) {
    for (int i = 0; i < n * n; i++) {
        C[i] = A[i] - B[i];
    }
}

void strassen(double* A, double* B, double* C, int n, double* tempStorage) {
    if (n == 1) {
        C[0] = A[0] * B[0];
    } else {
        int newSize = n / 2;
        int len = newSize * newSize;

        double *A11 = tempStorage;
        double *A12 = tempStorage + len;
        double *A21 = tempStorage + 2 * len;
        double *A22 = tempStorage + 3 * len;
        double *B11 = tempStorage + 4 * len;
        double *B12 = tempStorage + 5 * len;
        double *B21 = tempStorage + 6 * len;
        double *B22 = tempStorage + 7 * len;
        double *P1 = tempStorage + 8 * len;
        double *P2 = tempStorage + 9 * len;
        double *P3 = tempStorage + 10 * len;
        double *P4 = tempStorage + 11 * len;
        double *P5 = tempStorage + 12 * len;
        double *P6 = tempStorage + 13 * len;
        double *P7 = tempStorage + 14 * len;
        double *tempA = tempStorage + 15 * len;
        double *tempB = tempStorage + 16 * len;

        // Divide matrices into 4 sub-matrices
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                int idx = i * newSize + j;
                A11[idx] = A[i * n + j];
                A12[idx] = A[i * n + j + newSize];
                A21[idx] = A[(i + newSize) * n + j];
                A22[idx] = A[(i + newSize) * n + j + newSize];
                B11[idx] = B[i * n + j];
                B12[idx] = B[i * n + j + newSize];
                B21[idx] = B[(i + newSize) * n + j];
                B22[idx] = B[(i + newSize) * n + j + newSize];
            }
        }

        // Perform the necessary matrix additions and subtractions for Strassen's algorithm
        add(A11, A22, tempA, newSize);
        add(B11, B22, tempB, newSize);
        strassen(tempA, tempB, P1, newSize, tempStorage + 17 * len);

        add(A21, A22, tempA, newSize);
        strassen(tempA, B11, P2, newSize, tempStorage + 17 * len);

        subtract(B12, B22, tempB, newSize);
        strassen(A11, tempB, P3, newSize, tempStorage + 17 * len);

        subtract(B21, B11, tempB, newSize);
        strassen(A22, tempB, P4, newSize, tempStorage + 17 * len);

        add(A11, A12, tempA, newSize);
        strassen(tempA, B22, P5, newSize, tempStorage + 17 * len);

        subtract(A21, A11, tempA, newSize);
        add(B11, B12, tempB, newSize);
        strassen(tempA, tempB, P6, newSize, tempStorage + 17 * len);

        subtract(A12, A22, tempA, newSize);
        add(B21, B22, tempB, newSize);
        strassen(tempA, tempB, P7, newSize, tempStorage + 17 * len);

        // Combine the results to get the final matrix C
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                int idx = i * newSize + j;
                C[i * n + j] = P1[idx] + P4[idx] - P5[idx] + P7[idx];
                C[i * n + j + newSize] = P3[idx] + P5[idx];
                C[(i + newSize) * n + j] = P2[idx] + P4[idx];
                C[(i + newSize) * n + j + newSize] = P1[idx] - P2[idx] + P3[idx] + P6[idx];
            }
        }
    }
}

int main(int argc, char *argv[]) {  
    char dummy[128];    // 过滤垃圾字符
    int m = -1;         // 矩阵 A, m x k
    int n = -1;         // 矩阵 B, k x n
    int k = -1;         // 矩阵 C, m x n

    double *A;          // 矩阵 A
    double *B;          // 矩阵 B

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

    if ((B = (double*)malloc(k * n * sizeof(double))) == NULL) {
        printf("malloc failed\n");
        return -1;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            ret = scanf("%lf", &B[i * n + j]);
            if (ret != 1) {  
                fprintf(stderr, "Failed to read matrix elements.\n");  
                return -1;  
            }
        }
    }

    start = clock();
    // 调用 cblas_dgemm 函数进行矩阵乘法, 约定总是按行存储, 非转置, alpha = 1.0, beta = 0.0.    
    int new_n = nextPowerOfTwo(n);
    double* APadded = padMatrix(A, n, new_n);
    double* BPadded = padMatrix(B, n, new_n);
    double* CPadded = (double*)calloc(new_n * new_n, sizeof(double));  // Allocate and initialize to zero
    double* tempStorage = (double*)malloc(17 * new_n * new_n * sizeof(double));
    
    // 即 C = A x B.
    strassen(APadded, BPadded, CPadded, new_n, tempStorage);

    end = clock();
    printf("time is: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    int iftest = atoi(argv[1]);
    if (iftest == 1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%f ", CPadded[i * m + j]);
            }
            printf("\n");
        
        }
    }


    free(A); free(B);
    free(APadded); free(BPadded); free(CPadded);
    return 0;
}