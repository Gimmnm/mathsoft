#include <iostream>
#include <string>

class String {
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    String(const String& other) : m_Size(other.m_Size) { // deep copy
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String() {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

void PrintString(const String& string) { // it's a good way!!!
    std::cout << string << std::endl;
}

int main() {

    String string = "Gimait";
    String second = string; // deep copy (if no String(const String& other)... functoin then is not deep copy)

    second[2] = 'a';

    PrintString(string);
    PrintString(second);
 
    std::cin.get();
}