/**
 * @file main.c
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief 绘制数字图像
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "include/draw.h"
#include "include/setdigits.h"

int main() {

    printf("Input your number!(It should be a positive natral number and less than 10000)!\n");
    char *num = malloc(6);
    scanf("%s", num);

    const int width = 1024;                            // 图像宽度
    const int height = 768;                            // 图像高度
    const int pixel_size = 3;                          // 每个像素的字节数
    int padding = (4 - (width * pixel_size % 4)) % 4; // 每行的字节数需要是4的倍数
    FILE* file = fopen("test.bmp", "wb");
    unsigned char header[54];

    initBMPHeader(header, width, height);
    fwrite(header, sizeof(unsigned char), 54, file);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char color[3] = {255, 255, 255};
            get_digits_color(color, num, i, j);
            fwrite(color, 1, 3, file);
        }
        for (int p = 0; p < padding; p++)
        {
            fputc(0, file);
        }
    }
    fclose(file);

    free(num);
    return 0;
}
