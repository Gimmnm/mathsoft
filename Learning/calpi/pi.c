#include <stdio.h>
#include <gmp.h>
#include <mpfr.h>

#define PRECISION 1000 // 设定精度为 10000 位

void bbp(int n, mpfr_t pi)
{
    mpfr_t term, sum, factor, base, temp;
    // 初始化 term, sum, base, temp, 和 factor，精度为 PRECISION 位
    mpfr_inits2(PRECISION, term, sum, factor, base, temp, NULL);

    mpfr_set_ui(base, 16, MPFR_RNDD); // 设置 base 为 16
    mpfr_set_ui(sum, 0, MPFR_RNDD);   // 设置 sum 为 0

    mpfr_t temp1, temp2;
    mpfr_inits2(PRECISION, temp1, temp2, NULL);

    // 用 Bailey–Borwein–Plouffe (BBP) 公式计算 pi
    for (int k = 0; k <= n; k++)
    {
        mpfr_pow_ui(factor, base, k, MPFR_RNDD);   // 计算 factor
        mpfr_ui_div(factor, 1, factor, MPFR_RNDD); // 计算 factor 的倒数

        mpfr_set_ui(temp1, 8 * k + 1, MPFR_RNDD);
        mpfr_ui_div(term, 4, temp1, MPFR_RNDD); // 计算 term

        mpfr_set_ui(temp1, 8 * k + 4, MPFR_RNDD);
        mpfr_ui_div(temp2, 2, temp1, MPFR_RNDD);
        mpfr_sub(term, term, temp2, MPFR_RNDD); // 从 term 中减去数值

        mpfr_set_ui(temp1, 8 * k + 5, MPFR_RNDD);
        mpfr_ui_div(temp2, 1, temp1, MPFR_RNDD);
        mpfr_sub(term, term, temp2, MPFR_RNDD); // 从 term 中减去数值

        mpfr_set_ui(temp1, 8 * k + 6, MPFR_RNDD);
        mpfr_ui_div(temp2, 1, temp1, MPFR_RNDD);
        mpfr_sub(term, term, temp2, MPFR_RNDD); // 从 term 中减去数值

        // mpfr_set_d(term, 4.0 / (8 * k + 1), MPFR_RNDD);       // 计算 term
        // mpfr_sub_d(term, term, 2.0 / (8 * k + 4), MPFR_RNDD); // 从 sum 中减去 term
        // mpfr_sub_d(term, term, 1.0 / (8 * k + 5), MPFR_RNDD); // 从 sum 中减去 term
        // mpfr_sub_d(term, term, 1.0 / (8 * k + 6), MPFR_RNDD); // 从 sum 中减去 term

        mpfr_mul(temp, term, factor, MPFR_RNDD); // 将 term 乘以 factor
        mpfr_add(sum, sum, temp, MPFR_RNDD);     // 将 temp 加到 sum
    }

    mpfr_set(pi, sum, MPFR_RNDD); // 将 sum 的值赋给 pi

    mpfr_clears(term, sum, factor, base, temp, NULL); // 释放 term, sum, factor, base, 和 temp 的内存
    mpfr_clears(temp1, temp2, NULL);
}

int main()
{
    mpfr_t pi;
    // 初始化 pi，精度为 PRECISION 位
    mpfr_init2(pi, PRECISION);

    // 使用 BBP 公式计算 pi
    // bbp(PRECISION, pi);
    bbp(PRECISION, pi);

    // 打印 pi
    mpfr_out_str(stdout, 10, 0, pi, MPFR_RNDD);
    printf("\n");

    mpfr_clear(pi); // 释放 pi 的内存

    mpfr_t real;
    mpfr_init2(real, 200); // 设置精度为 200 位

    // 计算 pi
    mpfr_const_pi(real, MPFR_RNDN); // 计算 pi，舍入模式为最接近

    // 打印结果
    // printf("Pi is approximately: ");
    mpfr_out_str(stdout, 10, 0, real, MPFR_RNDN); // 输出 pi，基数为 10，舍入模式为最接近
    printf("\n");

    // 清理
    mpfr_clear(real);

    return 0;
}