#include <iostream>

#include "graph.cpp"

int main() {
    Graph g;

    g.addVertex("Home");
    g.addVertex("Store");
    g.addVertex("School");
    g.addVertex("Gym");
    g.addVertex("Work");

    g.addEdge("Home", "Store", 30);
    g.addEdge("Home", "Gym", 10);
    g.addEdge("Gym", "Store", 20);
    g.addEdge("Store", "School", 10);
    g.addEdge("Work", "School", 40);

    g.print();

    return 0;
}