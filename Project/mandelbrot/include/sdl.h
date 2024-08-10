/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief sdl可视化mandelbort集函数库
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifdef SDL_H
//DO NOTHING.
#else
#define SDL_H

#include <SDL2/SDL.h>

#define WIDTH 1024
#define HEIGHT 768
#define MAX_ITER 1000

/**
 * @brief Viewport结构体维护
 * 
 */
typedef struct{
    double x_min, x_max, y_min, y_max;
} Viewport;

/**
 * @brief 点击或自动缩放画面
 * 
 * @param vp 界面
 * @param zoom_factor 缩放比例 
 * @param x_center 缩放中心x坐标
 * @param y_center 缩放中心y坐标
 * @param click 是否手动点击进行缩放
 */
void zoom_in(Viewport *vp, double zoom_factor, double x_center, double y_center, int click);

/**
 * @brief 计算点对应的颜色
 * 
 * @param hue 
 * @param sat 
 * @param val 
 * @param r 红色分量
 * @param g 绿色分量
 * @param b 蓝色分量
 */
void hsv_to_rgb(int hue, double sat, double val, int *r, int *g, int *b);

/**
 * @brief 绘制mandelbrot图像
 * 
 * @param renderer 
 * @param vp 界面
 */
void draw_mandelbrot(SDL_Renderer *renderer, Viewport *vp);

#endif