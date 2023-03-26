#pragma once

#include <list>

#include "edge.h"
#include "vertex.h"

class Graph {
    public:
        void addEdge(string source, string destination, int weight);
        void addVertex(string name);
        bool edgeExists(string source, string destination);
        bool vertexExists(string name);
        void print();

        void shortestPath(string source);
        void minSpanTree();

    private:
        list<Edge> edgeList;
        list<Vertex> vertexList;

};