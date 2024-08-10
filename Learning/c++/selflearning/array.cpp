#include <iostream>

class Entity {
public:
    static const int exampleSize = 5; // maintain the size yourself!
    int example[exampleSize];

    Entity() {
        for (int i = 0; i < exampleSize; i++) {
            example[i] = 2;
        }
    }
};

int main() {

    int example[5];
    int* another = new int[5];

    for (int i = 0; i < 5; i++) {
        another[i] = 2;  
    }

    delete[] another;

    std::cin.get();
}