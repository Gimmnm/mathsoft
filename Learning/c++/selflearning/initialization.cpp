#include <iostream>

using String = std::string;

class Entity
{
private:
    String m_Name;
    int m_Age;
public:
    Entity() : m_Name("UnKnown"), m_Age(-1) {}
    Entity(const String& name) : m_Name(name), m_Age(-1) {}
    Entity(int age) : m_Name("UnKnown"), m_Age(age) {}

    const String& GetName() const { return m_Name; }  
};

int main() {

    // Entity entity = Entity("Gimait"); // into stack

    Entity* e; {
        Entity* entity = new Entity("Gimait"); // into Heap
        e = entity;
        std::cout << entity -> GetName() << std::endl;
    }

    delete e;


    // ------------- use new --------------

    int* b = new int[50];
    Entity* f = new Entity[50];
    Entity* c = new Entity(); // not only memory, but also constructor

    delete[] b;
    delete[] f;
    delete c;


    // -------------- another way ----------------

    Entity aa = String("Gimait");
    Entity bb = 22;


    std::cin.get();
}