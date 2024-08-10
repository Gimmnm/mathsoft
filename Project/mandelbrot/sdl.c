/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief sdl可视化mandelbort集函数实现
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "include/sdl.h"

void zoom_in(Viewport *vp, double zoom_factor, double x_center, double y_center, int click) {
    double x_range = (vp->x_max - vp->x_min) * zoom_factor;
    double y_range = (vp->y_max - vp->y_min) * zoom_factor;

    double xx_center = x_center;
    double yy_center = y_center;

    if (click == 1) {
        xx_center = vp->x_min + (x_center / (double)WIDTH) * (vp->x_max - vp->x_min);
        yy_center = vp->y_min + (y_center/ (double)HEIGHT) * (vp->y_max - vp->y_min);    
    }    

    vp->x_min = xx_center - x_range / 2.0;
    vp->x_max = xx_center + x_range / 2.0;
    vp->y_min = yy_center - y_range / 2.0;
    vp->y_max = yy_center + y_range / 2.0;
}

void hsv_to_rgb(int hue, double sat, double val, int *r, int *g, int *b) {
    double c = val * sat;
    double x = c * (1 - fabs(fmod(hue / 60.0, 2) - 1));
    double m = val - c;
    double r1, g1, b1;

    if (hue >= 0 && hue < 60) {
        r1 = c, g1 = x, b1 = 0;
    } else if (hue < 120) {
        r1 = x, g1 = c, b1 = 0;
    } else if (hue < 180) {
        r1 = 0, g1 = c, b1 = x;
    } else if (hue < 240) {
        r1 = 0, g1 = x, b1 = c;
    } else if (hue < 300) {
        r1 = x, g1 = 0, b1 = c;
    } else {
        r1 = c, g1 = 0, b1 = x;
    }

    *r = (r1 + m) * 255;
    *g = (g1 + m) * 255;
    *b = (b1 + m) * 255;
}


void draw_mandelbrot(SDL_Renderer *renderer, Viewport *vp) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double pr = vp->x_min + (x / (double)WIDTH) * (vp->x_max - vp->x_min);
            double pi = vp->y_min + (y / (double)HEIGHT) * (vp->y_max - vp->y_min);
            double newRe = 0, newIm = 0, oldRe, oldIm;
            int i;
            for (i = 0; i < MAX_ITER; i++) {
                oldRe = newRe;
                oldIm = newIm;
                newRe = oldRe * oldRe - oldIm * oldIm + pr;
                newIm = 2 * oldRe * oldIm + pi;
                if ((newRe * newRe + newIm * newIm) > 4) break;
            }

            int hue = i % 360;
            int r, g, b;
            hsv_to_rgb(hue, 1.0, 0.5, &r, &g, &b);
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}