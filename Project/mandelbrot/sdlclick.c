/**
 * @file conway.h
 * @author Gao Zhuohang (3230104543@zju.edu.cn)
 * @brief sdl可视化mandelbort集函数点击缩放实现
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h"
#include "include/sdl.h"

Viewport viewport = {-2.0, 1.0, -1.0, 1.0};

int main(int argc, char* args[]) {

    // sdl init
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Mandelbrot Set - Click to Zoom", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_bool done = SDL_FALSE;
    double zoom_factor = 0.5;

    while (!done) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                done = SDL_TRUE;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                zoom_in(&viewport, zoom_factor, e.button.x, e.button.y, 1);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        draw_mandelbrot(renderer, &viewport);  // Call new render function

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
