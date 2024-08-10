#include<stdio.h>
#include<limits.h>

int main(int argc, char **argv) {
    int imax = INT_MAX;
    long long llmax = LLONG_MAX;
    printf("The max of int is %d, and the max of long long is %lld\n", imax, llmax);
    return 0;
}