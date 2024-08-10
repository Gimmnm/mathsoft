#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main() {
    void* ptr = 0; // == nullptr / NULL

    int var = 10;
    int* ptr_var = &var;
    LOG(ptr_var);
    *ptr_var = 8;
    LOG(var);
    LOG(*ptr_var);

    char* buffer = new char[8];
    memset(buffer, 0, 8);
    char** ptr_buffer = &buffer; // double pointer
    delete[] buffer;

    std::cin.get();
    return 0;
}