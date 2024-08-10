#include <stdio.h>  
#include <omp.h>  
  
int main() {  
    long long N = 1000000000;  
    long long sum = 0;  
  
    #pragma omp parallel for reduction(+:sum)  
    for (long long i = 1; i <= N; i++) {  
        sum += i;  
    }  
  
    printf("Sum = %lld\n", sum);  
    return 0;  
}  
