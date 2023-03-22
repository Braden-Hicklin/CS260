#include <bits/stdc++.h>

using namespace std;

#define V 5 // init vertices for matrix

class Graph {
    private:
        int min_key(int key[], bool mstSet[]); // finds vertex with min key value on dynamic list
    public:
        void min_span_tree(int graph[V][V]); // prim's algorithm
};

int Graph::min_key(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

void Graph::min_span_tree(int graph[V][V]) 
{
    int parent[V]; // init parent array for mst
    int key[V]; 
    bool mstSet[V];
 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
        
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        // get min_key vertex using mstSet
        int u = min_key(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    
    // print graph and parent graph showing mst
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

int main() {

    // set up graph
    int G[V][V] = {
                    {0, 9, 75, 0, 0},
                    {9, 0, 95, 19, 42},
                    {75, 95, 0, 51, 66},
                    {0, 19, 51, 0, 31},
                    {0, 42, 66, 31, 0}};

    Graph g;
    g.min_span_tree(G);
}