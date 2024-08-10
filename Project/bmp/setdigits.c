/**
 * @file setdigits.c
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief 数字字体库函数实现
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "include/setdigits.h"

const int zerotonine[10][5][3] = {
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    }, {
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    }, {    
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
    }, {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }, {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1}
    }, {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }, {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    }, { 
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    }, {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    }, {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }
};

void get_digits_color(unsigned char *color, char *num, int h, int w) {
    int cnt = 0;
    for (char *i = num; *i != '\0'; i++) cnt += 1;
    int pixel_len = 50; 
    int start_h = 250;
    int start_w = (int)((1024 - 50 * (5 * cnt - 2)) / 2);
    if (h < start_h || h >= start_h + 5 * pixel_len || w < start_w || w > start_w + 5 * pixel_len * cnt) {
        return;
    } else {
        for (int i = 0; i < cnt; i++) {
            int now_start_h = start_h;
            int now_start_w = start_w + 5 * pixel_len * i;
            if (w >= now_start_w + pixel_len * 3 || w < now_start_w) {
                continue;
            } else {
                int now_h = (int)((h - now_start_h) / pixel_len);
                int now_w = (int)((w - now_start_w) / pixel_len);
                color[0] = zerotonine[(int)(num[i]-'0')][4 - now_h][now_w] ? 0 : 255;
                color[1] = zerotonine[(int)(num[i]-'0')][4 - now_h][now_w] ? 0 : 255;
            }
        }
    }
}