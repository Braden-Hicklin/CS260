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
        bool edgeExists(string source, string destination);
        bool vertexExists(string name);
        void print();

        // shortest path algorithm based on the priority queue pseudo code found on https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
        void shortestPath(string source);
        
        // looking at Prim's algorithm right now, not sure if kruskals would work since the graph is directed
        void minSpanTree();
        
        // changed to public so it can be accessed in main
        // MOVE BACK TO PRIVATE
        vector<Edge*> edgeList; // stores the edges in a vector
        vector<Vertex*> vertexList; // stores the vertices in a vector

    private:
        // used for initialization of the graph's vertices 
        // attempting to dynamically set this value later in main... hopefully
        int V; 

        // sets up the adjacency list which will pair the destination id and the 
        // source id with their respective weight
        // used from GeeksforGeeks shortestPathAlgorithm and priority_queue guides
        list<pair<int, int>>* adj; 
};
