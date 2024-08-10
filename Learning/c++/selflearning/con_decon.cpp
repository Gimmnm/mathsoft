#include <iostream>

class Entity {
public:
    float X, Y;

    Entity() {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" << std::endl;
    }

    Entity(float x, float y) : X(x), Y(y) {}
    
    ~Entity() {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print() {
        std::cout << X << ", " << Y << std::endl;
    }
};

class Log {
private:
    Log() {}
public:
    static void Write() {

    }
};
  

int main() {

    Entity e;
    Entity e2(5.0f, 10.0f);

    // Log::Write(); allowed
    // Log l; not allowed for Log() {} is private   
    // Log() = deleta is the same
    std::cin.get();
}