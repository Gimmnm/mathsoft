#include <iostream>
#include <string>

class Entity {
private:
    int m_X, m_Y;
    int *m_Z;
public:
    int GetX() const { // can't change any member vaible
        // m_X = 2 not allowed
        return m_X;
    }
    int GetY() {
        return m_Y;
    }
    void SetX(int x) {
        m_X = x;
    }
    const int* const GetZ() const { // hhhhhhhh
        return m_Z;
    }

};

void PrintEntity(const Entity& e) { // 
    std::cout << e.GetX() << std::endl;
    // std::cout << e.GetY() << std::endl; not allowed
}

void test() {
    Entity e;

    PrintEntity(e);

}

int main() {

    const int a = 10;
    // a = 3 not allowed

    int* b = new int;

    *b = 2;
    std::cout << *b << std::endl;

    const int* c = new int;

    // *c = 2 not allowed
    c = (int*)&a; // allowed

    int* const d = new int;

    *d = 2; // allowed
    // d = (int*)&a not allowed

    const int* const e = new int;


    test();

    std::cin.get();
}