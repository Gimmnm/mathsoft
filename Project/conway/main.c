/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief 实现Conway游戏
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "include/conway.h"

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s width height rle_file boundary\n", argv[0]);
        return 1;
    }
    boundary = argv[4][0] - '0'; // (boundary == 0) means we have boundary

    initscr();              
    nodelay(stdscr, TRUE);
    curs_set(0);            
    noecho();               
    cbreak();               

    initializeGrid(atoi(argv[1]), atoi(argv[2]));
    load_pattern(10, 10, argv[3]);

    while (1) {
        clear();            
        printGrid();    
        usleep(40000);
        char ch = getch();
        if (ch == 'q') break;
        if (ch == 's') { usleep(1000000); snap_shoot(); }
        updateGrid();   
    }
    endwin();      
    free_grid();       
    return 0;
}