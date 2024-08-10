/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief 实现Conway游戏的函数库实现
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "../bmp/include/draw.h"
#include "include/conway.h"

struct World world;
int boundary = 1;

void initializeGrid(int conway_w, int conway_h) {
    world.conway_w = conway_w;
    world.conway_h = conway_h;
    world.grid = (int *)malloc(conway_h * conway_w * sizeof(int));
    int *grid = world.grid;
    
    for (int i = 0; i < conway_h; ++i) {
        for (int j = 0; j < conway_w; ++j) {
            //grid[i * conway_w + j] = rand() % 2; // 对于每个细胞，随机决定是活(1)还是死(0)
            grid[i * conway_w + j] = 0;
        }
    }
}

void load_pattern(int start_x, int start_y, char *rle_file) {
    FILE *file = fopen(rle_file, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[512];
    int pattern_weight = 0, pattern_height = 0;

    // 跳过文件头部直到读取到数据行
    while (fgets(line, sizeof(line), file)) {
        //if (line[0] == '#') { continue; }
        if (line[0] == 'x') { // 这是头部信息行
            sscanf(line, "x = %d, y = %d", &pattern_weight, &pattern_height);
            break;
        }
    }

    int conway_w = world.conway_w;
    //int conway_h = world.conway_h;
    int *grid = world.grid;
    int row = start_x, col = start_y;
    int count; char c;

    while ((c = fgetc(file)) != EOF) {
        if (c >= '0' && c <= '9') {
            ungetc(c, file);
            fscanf(file, "%d%c", &count, &c);
            for (int i = 0; i < count; i++) {
                if (c == 'o') {
                    grid[row * conway_w + (col++)] = 1; // 活细胞
                } else if (c == 'b') {
                    col++; // 死细胞，数组已初始化为0，所以这里只移动列指针
                } else if (c == '$') {
                    row++;
                    col = start_y;
                }
            }
        } else if (c == 'o') {
            grid[row * conway_w + (col++)] = 1;
        } else if (c == 'b') {
            col++;
        } else if (c == '$') {
            row++;
            col = start_y;
        } else if (c == '!') {
            break; // 结束模式数据
        }
    }
    fclose(file);
}

int getLiveNeighbors(int x, int y) {
    int conway_w = world.conway_w;
    int conway_h = world.conway_h;
    int *grid = world.grid;

    int liveNeighbors = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (boundary == 0) {
                if (i == 0 && j == 0) continue;
                if (x + i < 0 || x + i >= conway_w || y + j < 0 || y + j >= conway_h) { continue; }
                int row = x + i;
                int col = y + j;
                liveNeighbors += grid[row * conway_w + col];        
            } else if (boundary == 1) {
                if (i == 0 && j == 0) continue;
                int row = (x + i + conway_h) % conway_h;
                int col = (y + j + conway_w) % conway_w;
                liveNeighbors += grid[row * conway_w + col];
            }
            
        }
    }
    return liveNeighbors;
}

void updateGrid() {
    int conway_w = world.conway_w;
    int conway_h = world.conway_h;
    int *grid = world.grid;

    int *newGrid = (int *)malloc(conway_h * conway_w * sizeof(int));

    for (int i = 0; i < conway_h; ++i) {
        for (int j = 0; j < conway_w; ++j) {
            int liveNeighbors = getLiveNeighbors(i, j);

            if (grid[i * conway_w + j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                newGrid[i * conway_w + j] = 0;
            } else if (grid[i * conway_w + j] == 0 && liveNeighbors == 3) {
                newGrid[i * conway_w + j] = 1;
            } else {
                newGrid[i * conway_w + j] = grid[i * conway_w + j];
            }
        }
    }

    for (int i = 0; i < conway_h; ++i) {
        for (int j = 0; j < conway_w; ++j) {
            grid[i * conway_w + j] = newGrid[i * conway_w + j];
        }
    }
    free(newGrid);
}

void printGrid() {
    int conway_w = world.conway_w;
    int conway_h = world.conway_h;
    int *grid = world.grid;

    for (int i = 0; i < conway_h; ++i) {
        for (int j = 0; j < conway_w; ++j) {
            mvaddch(i, j, grid[i * conway_w + j] ? '*' : ' ');
        }
    }
    refresh();
}

void free_grid() {
    free(world.grid);
}

void snap_shoot() {
    const int width = world.conway_h;                            // 图像宽度
    const int height = world.conway_w;                            // 图像高度
    const int pixel_size = 3;                          // 每个像素的字节数
    int padding = (4 - (width * pixel_size % 4)) % 4; // 每行的字节数需要是4的倍数
    FILE* file = fopen("conway.bmp", "wb");
    unsigned char header[54];
    initBMPHeader(header, width, height);
    fwrite(header, sizeof(unsigned char), 54, file);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char color[3] = {255, 255, 255};
            color[0] = world.grid[(height - 1 - i) * width + j] == 1 ? 0 : 255;
            color[1] = world.grid[(height - 1 - i) * width + j] == 1 ? 0 : 255;
            color[2] = world.grid[(height - 1 - i) * width + j] == 1 ? 0 : 255;
            fwrite(color, 1, 3, file);
        }
        for (int p = 0; p < padding; p++) fputc(0, file);
    }
    fclose(file);
}