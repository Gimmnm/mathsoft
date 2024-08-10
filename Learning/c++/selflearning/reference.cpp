#include <iostream>

#define LOG(x) std::cout << x << std::endl

void Increment(int value) {
    value ++;
}
void Increment_pointer(int* value) {
    (*value) ++;
}
void Increment_reference(int& value) {
    value ++;
}

int main() {

    int a = 5;
    int* ptr = &a;
    int& ref = a; // ref is a
    
    ref = 2;

    LOG(a); // 2

    int var = 5;
    Increment(var);
    LOG(var); // 5

    Increment_pointer(&var);
    LOG(var); // 6

    Increment_reference(var);
    LOG(var); // 7

    std::cin.get();
    return 0;
}