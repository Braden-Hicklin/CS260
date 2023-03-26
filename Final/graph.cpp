#include <iostream>
#include <bits/stdc++.h>

#include "graph.h"

using namespace std;

void Graph::addVertex(string name){
    Vertex *newVertex = new Vertex;

    bool checkVertex = vertexExists(name);
    if(checkVertex == true) {
        cout << "That Vertex already exists" << endl;

    } else {    
        newVertex->locationName = name;
        newVertex->id = vertexList.size();

        vertexList.push_back(newVertex);
        cout << "Vertex " << newVertex->locationName << " successfully created with the id of " << newVertex->id << endl;
    }
}

Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(string source, string destination, int weight) {
    Edge *newEdge = new Edge;

    bool checkDest = vertexExists(destination);
    bool checkSrc = vertexExists(source);

    bool checkEdge = edgeExists(source, destination);

    if(checkDest && checkSrc == true) {
        if(checkEdge == true) {
            cout << "That edge already exists." << endl;

        } else {
            for(int i = 0; i < vertexList.size(); i++) {
                if(vertexList.at(i)->locationName == source)
                    newEdge->source = vertexList.at(i);
                if(vertexList.at(i)->locationName == destination)
                    newEdge->destination = vertexList.at(i);
            }
            newEdge->weight = weight;
            edgeList.push_back(newEdge);
            adj[newEdge->source->id].push_back(make_pair(
                newEdge->destination->id, newEdge->weight));
            adj[newEdge->destination->id].push_back(make_pair(
                newEdge->source->id, newEdge->weight));
            cout << "Edge successfully created between " << newEdge->source->locationName << " and " << newEdge->destination->locationName << endl;
        }
    } else {
        cout << "The source vertex " << source << " and destination vertex " << destination << " do not exist." << endl;
    }
}

bool Graph::edgeExists(string source, string destination) {
    for(int i = 0; i < edgeList.size(); i++) {
        if(edgeList.at(i)->source->locationName == source) {
            if(edgeList.at(i)->destination->locationName == destination) {
                return true;
            }
        }
    }
    return false;
}

bool Graph::vertexExists(string name) {
    for(int i = 0; i < vertexList.size(); i++) {
        if(vertexList.at(i)->locationName == name) {
            return true;
        }
    }

    return false;
}

void Graph::print() {

    cout << "Printing Vertices..." << endl;
    for(int v = 0; v < vertexList.size(); v++)
        
        // add below code after 'locationName' to see ids along with their respective locationName
        /*<< "\t" << vertexList.at(v)->id */ 
        
        cout << vertexList.at(v)->locationName << endl;

    cout << "\nPrinting Edges..." << "\nSrc\tDest\tWeight" << endl;
    for(int e = 0; e < edgeList.size(); e++)
        cout << edgeList.at(e)->source->locationName << " -> " << edgeList.at(e)->destination->locationName << "\t" << edgeList.at(e)->weight << endl;
}

/* Dijkstra's Pseudo Code
   HEAVILY INSPIRED BY THE PRIORITY QUEUE DESIGN FOUND ON https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

    potentially add in new list in graph.h like ## list<pair<string, int>>* adjList;
    
    void shortestPath(Graph ??how do I plan on pulling the graph??, source vertex ??use string and iterate through
        vertex list to find matching string, how will I use it as a source vertex??) {
        dist[source] = 0                           // 

        create priority queue ?? priority_queue<pair<id, weight>, vector<pair<id, weight>>, greater<pair<id,weight>>> Q?? ---> min heap priority queue

        for each vertex v in Graph.Vertices:
            if v != source
                dist[v] ← INF       ?? make this a list, list<int> dist(v, INF);
                Q.push(v, dist[v]) 

        while (!Q.empty()):                      
            u ← Q.top().second --> list operator
            Q.pop(); 

            for loop ?? would iterator be more efficient ?? call pointer ?? use first/second operators                    
            for each neighbor v of u:   ?? could use pair instead of neighbors since you struggle implementing the neighbors --sigh--           
                alt ← dist[u] + adj(u, v)
                if alt < dist[v]:
                    dist[v] ← alt
                    prev[v] ← u
                    Q.decrease_priority(v, alt)

     return dist, prev
}

*/

void Graph::shortestPath(string source){
    int location;
    int V = vertexList.size();

    bool checkVertex = vertexExists(source); // checks if the input source vertex even exists
    if(checkVertex != false) {
        for(int v = 0; v < V; v++) {
            if(vertexList.at(v)->locationName == source) {
                location = vertexList.at(v)->id;
            }
        } 
    } else {
        cout << "Invalid source vertex selected, cannot run SSSP algorithm." << endl;
        return;
    }

    // creates a min heap for priority queue based on the adjlist design (pair<source/dest, weight>)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q; 
    vector<int> dist(V, INF); // creates a vector for distances

    Q.push(make_pair(0, location));
    dist[location] = 0;

    while(!Q.empty()) {
        int u = Q.top().second;
        Q.pop();

        list<pair<int, int> >::iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            int w = (*it).second;
            
        // cout << "printing dist[u]..." << dist[u] << endl; debug printing

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                Q.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "vertex distance from source" << endl;
    for(int i = 0; i < V; i++) {
        cout << vertexList.at(i)->locationName << "\t\t" << dist[i] << endl;
    }
}

// UNFINISHED
// Looking at prim's algo rn
void Graph::minSpanTree(string root) {
    int location;
    int V = vertexList.size();

    bool checkVertex = vertexExists(root);
    if(checkVertex != false) {
        for(int v = 0; v < V; v++) {
            if(vertexList.at(v)->locationName == source) {
                location = vertexList.at(v)->id;
            }
        } 
    } else {
        cout << "Invalid source vertex selected, cannot run prim's algorithm." << endl;
        return;
    }

    vector<int> parent;

}
