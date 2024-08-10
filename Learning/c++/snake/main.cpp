#include "SnakeGame.hpp"
// g++ -o snake main.cpp SnakeGame.cpp -std=c++11

int main() {
    srand(static_cast<unsigned int>(time(0)));
    SnakeGame game;
    game.run();
    return 0;
}