#pragma once

#include <list>
#include <vector>
#include <queue>

#include "edge.h"
#include "vertex.h"

#define INF 999

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
        vector<Edge*> edgeList;
        vector<Vertex*> vertexList;
};
