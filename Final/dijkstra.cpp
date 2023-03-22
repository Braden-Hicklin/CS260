#include<bits/stdc++.h>

using namespace std;

# define INF 1000000000 // infinity

class Graph {
    private:
        int V; // vertices
        list<pair<int, int>>*adj; // init for adjacency list
    
    public:
        Graph(int V); // sets vertices and inits the graph
        void add_edge(int u, int v, int w); // adds edges to adjacency list
        void shortest_path(int src); // dijkstra's algorithm, takes src node (0)
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::add_edge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortest_path(int src) {
    set<pair<int, int>> vSet;
    vector<int> dist(V, INF);

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
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d \n", i, dist[i]);

}

int main()
{
    int V = 9; // sets vertices 
    Graph g(V); // init graph with vertices
 
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    
    g.shortest_path(0);
 
    return 0;
}