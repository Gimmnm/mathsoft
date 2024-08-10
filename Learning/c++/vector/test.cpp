#include "Vector.h"
// g++ -o test test.cpp Vector.cpp -std=c++11
void run() {    
    Vector v1{1, 2, 3};
    Vector v2(3);

    for (int i = 0; i < 3; i++)
        v2[i] = i + 1;

    std::cout << "v1: " << v1 << '\n';
    std::cout << "v2: " << v2 << '\n';
    std::cout << "v1 + v2: " << v1 + v2 << '\n';
    std::cout << "v1 - v2: " << v1 - v2 << '\n';
    v1 *= 3;
    std::cout << "v1 * 3: " << v1 << '\n';
}    
      
int main() {    
    try {    
        run();    
    } catch (const std::exception& e) {    
        std::cerr << "An error occurred: "   
                  << e.what() << '\n';    
        return 1;    
    }    
    return 0;    
} 