#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

class Position {
private:
    int x;
    int y;
public:
    Position(int _x, int _y);
    Position() { x = 0; y = 0; };
    int get_position_x();
    int get_position_y();
    void set_position(int _x, int _y);
    void set_position(Position _p);
    ~Position() {};
};

Position::Position(int _x, int _y) {
    x = _x;
    y = _y;
}

int Position::get_position_x() {
    return x;
}

int Position::get_position_y() {
    return y;
}

void Position::set_position(int _x, int _y) {
    x = _x;
    y = _y;
}

void Position::set_position(Position _p) {
    x = _p.get_position_x();
    y = _p.get_position_y();
}

int main() {

    std::cin.get();
}
