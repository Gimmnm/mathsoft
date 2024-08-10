#include <iostream>  
#include <stdexcept>  
#include <complex>
#include <string>
#include "Vector.h"

    
void run() {    
    Vector<double> v1{1.1, 2.1, 3.1};
    Vector<double> v2(3);

    for (int i = 0; i < 3; i++)
    {
        v2[i] = i + 1.1;
    }

    std::cout << "v1: " << v1 << '\n';
    std::cout << "v2: " << v2 << '\n';
    std::cout << "v1 + v2: " << v1 + v2 << '\n';
    std::cout << "v1 - v2: " << v1 - v2 << '\n';
    v1 *= 3;
    std::cout << "v1 * 3: " << v1 << '\n';

    Vector<int> i1{1, 2, 3};
    Vector<int> i2(3);

    for (int i = 0; i < 3; i++)
    {
        i2[i] = i + 1;
    }

    std::cout << "i1: " << i1 << '\n';
    std::cout << "i2: " << i2 << '\n';
    std::cout << "i1 + i2: " << i1 + i2 << '\n';
    std::cout << "i1 - i2: " << i1 - i2 << '\n';
    i1 *= 3;
    std::cout << "i1 * 3: " << i1 << '\n';

    Vector<std::complex<double>> c1{{1.1, 2.1}, {3.1, 4.1}, {5.1, 6.1}};
    Vector<std::complex<double>> c2(3);

    for (int i = 0; i < 3; i++)
    {
        c2[i] = {i + 1.1, i + 2.1};
    }

    std::cout << "c1: " << c1 << '\n';
    std::cout << "c2: " << c2 << '\n';
    std::cout << "c1 + c2: " << c1 + c2 << '\n';

    Vector<std::string> s1{"a", "b", "c"};
    Vector<std::string> s2(3);

    for (int i = 0; i < 3; i++)
    {
        s2[i] = std::string(1, 'a' + i);
    }

    std::cout << "s1: " << s1 << '\n';
    std::cout << "s2: " << s2 << '\n';
    std::cout << "s1 + s2: " << s1 + s2 << '\n';
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