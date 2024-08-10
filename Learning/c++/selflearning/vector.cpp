#include <iostream>
#include <string>
#include <vector>

struct Vertex {
    float x, y, z;
    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
};

int main() {

    std::vector<Vertex> vertices;
    vertices.reserve(3);
    // vertices.push_back({ 1, 2, 3 });
    // vertices.push_back({ 4, 5, 6 });
    // vertices.push_back({ 7, 8, 9 });
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 5, 6);
    vertices.emplace_back(7, 8, 9);
    

    std::cin.get();
}