#include "../include/common.h"

int main() {
    char line[512];
    int N = 0;
    double temp = 0;
    double sum = 0;
    double average = 0;
    int count = 0;
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == 'N') {
            sscanf(line, "Number of tests: %d", &N);
        } else if (line[0] == 't') {
            sscanf(line, "time is: %lf", &temp);
            sum += temp;
            count += 1;
            if (count == N) break;
        }
    }   
    average = sum / (double)N;
    printf("Average time is %lf\n\n", average);
    return 0;
}