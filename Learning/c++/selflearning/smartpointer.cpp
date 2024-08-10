#include <iostream>
#include <string>
#include <memory>

class Entity {
public:
    Entity() { std::cout << "Created Entity!" << std::endl; }
    ~Entity() { std::cout << "Destroyed Entity!" << std::endl; }
};

int main() {

    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();    
         // don't need delete
    }

    // --------- shared_ptr ----------
    // --------- weak_ptr ----------

    std::cin.get();
}