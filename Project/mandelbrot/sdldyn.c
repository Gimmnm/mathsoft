/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief sdl可视化mandelbort集函数点击自动放大实现
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "include/sdl.h"

Viewport viewport = {-2.0, 1.0, -1.0, 1.0};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s Ox Oy\n", argv[0]);
        return 1;
    }
    double x_center = SDL_atof(argv[1]);
    double y_center = SDL_atof(argv[2]);
    
    // sdl init
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Mandelbrot Set - Automatic Zoom", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_bool done = SDL_FALSE;
    double zoom_factor = 0.95;

    while (!done) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                done = SDL_TRUE;
            }
        }

        zoom_in(&viewport, zoom_factor, x_center, y_center, 0);  // Zoom into the Mandelbrot set
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        draw_mandelbrot(renderer, &viewport);  // Redraw the Mandelbrot set
        SDL_RenderPresent(renderer);

        SDL_Delay(20);  // 控制渲染速率
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
