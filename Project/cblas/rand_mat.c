#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../Learning/rng/include/mtwister.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <row> <col>\n", argv[0]);
        return 1;
    }
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    MTRand r = seedRand(1337);
    printf("row = %d, col = %d\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f ", (double)genRand(&r));
        }
        printf("\n");
    }

    return 0;
};