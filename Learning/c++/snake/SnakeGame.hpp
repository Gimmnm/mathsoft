#ifndef SNAKEGAME_HPP
#define SNAKEGAME_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

enum Direction { UP, DOWN, LEFT, RIGHT };

class SnakeGame {
private:
    int width, height;
    int score;
    bool gameOver;
    std::pair<int, int> fruit;
    Direction dir;
    std::vector<std::pair<int, int>> snake;

    void generateFruit();
    void draw();
    int kbhit();
    char getch();

public:
    SnakeGame();
    void input();
    void logic();
    void run();
};

#endif