#pragma once

#include <list>
#include <vector>
#include <queue>

#include "edge.h"
#include "vertex.h"

#define INF 999

class Graph {
    public:
        Graph(int V);
        void addEdge(string source, string destination, int weight);
        void addVertex(string name);
        void print();

        // could be private utility functions, but user might benefit from seeing if a vertex/edge exists
        bool edgeExists(string source, string destination);
        bool vertexExists(string name);
        


        // shortest path algorithm based on the priority queue pseudo code found on https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
        // void shortestPath(string source); no longer in use
        void shortestPathSelected(string source, string destination);
        void minSpanTree();

    private:
        // utility functions
        int getIDByString(string vertexName);
        void printPath(int currentVertex, int targetVertex, vector<int> root);
        
        // used for initialization of the graph
        // this is done dynamically based on the size of the vertexList vector
        int V; 

        // used from GeeksforGeeks priority_queue (min and max heap) guide
        // most important, stores the id's of vertices adjacent to each other
        vector<pair<int, int>>* adj; 
        
        // stores pointer to edges in a vector
        // used to call locationNames of source and destination vertices, and weight
        vector<Edge*> edgeList; 
        vector<Vertex*> vertexList; // stores the vertices in a vector
};