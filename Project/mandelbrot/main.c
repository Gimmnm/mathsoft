/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief mandelbort集可视化静态绘图
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "../bmp/include/draw.h"
#include "include/mandelbrot.h"

int main(int argc, char *argv[]) {

    double start_x = atof(argv[1]);
    double start_y = atof(argv[2]);
    const int width = atoi(argv[3]);
    const int height = atoi(argv[4]);
    int max_iteration = atoi(argv[5]);
    double square = atof(argv[6]);
    const int pixel_size = 3;
    int padding = (4 - (width * pixel_size % 4)) % 4;
    FILE* file = fopen("mandelbrot.bmp", "wb");
    unsigned char header[54];
    initBMPHeader(header, width, height);
    fwrite(header, sizeof(unsigned char), 54, file);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char color[3] = {255, 255, 255};
            double c_re = ((j - width / 2.0) / width * 2.0) * square + start_x;
            double c_im = ((i - height / 2.0) / height * 2.0) * square + start_y;
            // printf("%f %f  ", c_re, c_im);
            int iteration = mandelbrot(c_re, c_im, max_iteration);
            color[0] = iteration * 255 / max_iteration;
            color[1] = 255 - iteration * 255 / max_iteration;
            color[2] = 255 - iteration * 255 / max_iteration;
            fwrite(color, 1, 3, file);
        }
        // printf("\n");
        for (int p = 0; p < padding; p++) fputc(0, file);
    }
    fclose(file);
    return 0;
}