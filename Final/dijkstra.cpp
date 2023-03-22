#include<bits/stdc++.h>

using namespace std;

# define INF 0x3f3f3f3f // inf set to int max

class Graph {
    private:
        int Vertex;
        list<pair<int, int>>*adj;
    
    public:
        Graph(int Vertex); // sets vertices and inits the graph
        void add_edge(int u, int v, int w); // adds edges to adjacency list
        void shortest_path(int src); // dijkstra's algorithm
};

Graph::Graph() {
    this->Vertex = Vertex;
    adj = new list<pair<int, int>>[Vertex];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src) {
    set<pair<int, int>> vSet;
    vector<int> dist(Vertex, INF);

    vSet.insert(make_pair(0, src));
    dist[src] = 0;

    while(!vSet.empty()) {
        pair<int, int> tmp = *(vSet.begin());
        vSet.erase(vSet.begin());

        int u = tmp.second;
        list<pair<int, int>>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = (*i).first;
            int weight = (*i).second;

            if(dist[v] > dist[u] + weight) {
                if(dist[v] != INF) 
                    vSet.erase(vSet.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                vSet.insert(make_pair(dist[v], v));
            }
        }
    }

    // prints shortest path
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < Vertex; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}