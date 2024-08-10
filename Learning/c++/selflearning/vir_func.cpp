#include <iostream>
#include <string>

class Entity {
public:
    //std::string GetName() { return "Entity"; }    
    virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity {
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}
    
    std::string GetName() override { return m_Name; }
};


int main() {
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl; // Entity
    
    Player* p = new Player("Gimait");
    std::cout << p->GetName() << std::endl; // Gimait

    Entity* entity = p;
    std::cout << entity->GetName() << std::endl;  // Gimait

    std::cin.get();
}