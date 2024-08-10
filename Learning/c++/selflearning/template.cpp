#include <iostream>
#include <string>

template<typename T>
void Print(T value) {
    std::cout << value << std::endl;
}

template<typename T, int N>
class Array {
private:
    T m_Array[N];
public:
    int GetSize() const { return N; }
};

int main() {

    Print(10);
    Print("Hello");
    Print<int>(20);

    Array<int, 10> array;
    std::cout << array.GetSize() << std::endl;

    std::cin.get();
}