/**
 * @file draw.c
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief 生成BMP文件的函数库实现
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "include/draw.h"

void initBMPHeader(unsigned char* header, int width, int height) {
    int fileSize = 54 + 3 * width * height; // 文件的总大小
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = fileSize;
    header[10] = 54; // 数据偏移量
    header[14] = 40; // 信息头的大小
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    header[26] = 1; // 平面数
    header[28] = 24; // 每个像素点24位颜色
}

