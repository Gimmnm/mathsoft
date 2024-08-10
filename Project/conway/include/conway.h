/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief 实现Conway游戏的函数库
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifdef CONWAY_H
//DO NOTHING.
#else
#define CONWAY_H

/**
 * @brief 游戏世界信息维护
 * 
 */
struct World{
    int conway_w; int conway_h;
    int *grid;
};

extern struct World world;
extern int boundary;

/**
 * @brief 初始化世界为无细胞世界
 * 
 * @param conway_w 世界宽度
 * @param conway_h 世界长度
 */
void initializeGrid(int conway_w, int conway_h);

/**
 * @brief 读如特定conway游戏模式
 * 
 * @param start_x 录入模式的初始位置x坐标
 * @param start_y 录入模式的初始位置y坐标
 * @param rle_file 录入模式的rle文件
 */
void load_pattern(int start_x, int start_y, char *rle_file);

/**
 * @brief Get the Live Neighbors object
 * 
 * @param x 细胞位置x
 * @param y 细胞位置y
 * @return int 返回是否存活
 */
int getLiveNeighbors(int x, int y);

/**
 * @brief 更新世界中的存活的细胞
 * 
 */
void updateGrid();

/**
 * @brief 游戏的输出
 * 
 */
void printGrid();

/**
 * @brief 清空内存空间
 * 
 */
void free_grid();

/**
 * @brief 截屏功能实现
 * 
 */
void snap_shoot();

#endif