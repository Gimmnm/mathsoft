#include <iostream>
#include <string>

class Printable { // interface ?
public:
    virtual std::string GetClassName() = 0; // pure virtual function
};

class Entity : public Printable {
public:
    virtual std::string GetName() { return "Entity"; }    
    //virtual std::string GetName() = 0;

    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}
    
    std::string GetName() override { return m_Name; }

    std::string GetClassName() override { return "Player"; }
};

void Print(Printable* obj) {
    std::cout << obj->GetClassName() << std::endl;
}

int main() {
    Entity* e = new Entity();

    Player* p = new Player("Gimait");
    
    Print(e); // Entity
    Print(p); // Player  

    std::cin.get();
} 