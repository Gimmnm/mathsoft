/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief Mandelbrot集计算函数实现
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "include/mandelbrot.h"

int mandelbrot (double c_re, double c_im, int max_iteration) {
    double x = 0.0;
    double y = 0.0;
    int iteration = 0;
    while (x * x + y * y < 4 && iteration < max_iteration) {
        double x_temp = x * x - y * y + c_re;
        y = 2 * x * y + c_im;
        x = x_temp;
        iteration++;
    }
    return iteration;
}