#include <iostream>
#include <string>

void PrintString(const std::string& string) {
    std::cout << string << std::endl;
}

int main() {

    const char* name = "Gimait";
    
    std::cout << name << std::endl; // Gimait

    char name2[7] = { 'G', 'i', 'm', 'a', 'i', 't', '\0'};

    std::cout << name2 << std::endl; // Gimait

    std::string na = "Gimait";
    std::cout << na << std::endl;
    std::cout << na.size() << std::endl;
    bool contains = na.find("ma") != std::string::npos;

    std::cin.get();
}