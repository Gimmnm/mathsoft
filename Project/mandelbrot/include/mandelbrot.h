/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief Mandelbrot集计算函数库
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"

#ifdef MANDELBROT_H
//DO NOTHING.
#else
#define MANDELBROT_H

/**
 * @brief Mandelbrot集计算
 * 
 * @param c_re 复数的实部
 * @param c_im 复数的虚部
 * @param max_iteration 最大迭代次数
 * @return int 返回迭代次数
 */
int mandelbrot (double c_re, double c_im, int max_iteration);

#endif