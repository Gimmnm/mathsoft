#include <stdio.h>
#include "include/mtwister.h"
#include "TinyMT-master/tinymt/tinymt64.h"

int main() {
    MTRand r = seedRand(1337);

    for(int i = 0; i < 1000; i++) {
        printf("%f\n", genRand(&r));
    }

    printf("\n");

    tinymt64_t tinymt;  
    tinymt.mat1 = 0xfa051f40;  
    tinymt.mat2 = 0xffd0fff4;  
    tinymt.tmat = 0x58d02ffeffbfffbc;  
    uint64_t seed = 1;  
    tinymt64_init(&tinymt, seed);  
  
    // 生成随机数  
    printf("Generated random numbers:\n");  
    printf("64-bit unsigned integer: %" PRIu64 "\n", tinymt64_generate_uint64(&tinymt));  
    printf("Double precision floating point number (0.0 to 1.0): %lf\n", tinymt64_generate_double(&tinymt));  
    printf("Double precision floating point number (1.0 to 2.0): %lf\n", tinymt64_generate_double12(&tinymt));  
    printf("Double precision floating point number (0.0 to 1.0, excluding 1.0): %lf\n", tinymt64_generate_doubleOC(&tinymt));  
    printf("Double precision floating point number (0.0 to 1.0, excluding 0.0 and 1.0): %lf\n", tinymt64_generate_doubleOO(&tinymt)); 
    return 0;
}