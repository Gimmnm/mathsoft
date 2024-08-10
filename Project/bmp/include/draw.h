/**
 * @file draw.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief 生成BMP文件的函数库.
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifdef DRAW_H
//DO NOTHING.
#else
#define DRAW_H

/**
 * @brief BMP 文件头初始化
 * 
 * @param header 文件头
 * @param width BMP文件宽度
 * @param height BMP文件长度
 */
void initBMPHeader(unsigned char* header, int width, int height);
#pragma pack(push, 1)
typedef struct {
    unsigned char b;
    unsigned char g;
    unsigned char r;
} RGB;
#pragma pack(pop)

#endif