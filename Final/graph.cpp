#include <iostream>
#include <iterator>

#include "graph.h"

using namespace std;

void Graph::addVertex(string name){
    Vertex *newVertex = new Vertex;
    
    newVertex->cityName = name;

    bool checkVertex = vertexExists(name);
    if(checkVertex == true) {
        cout << "That Vertex already exists" << endl;

    } else {
        vertexList.push_back(*newVertex);
    }
}

void Graph::addEdge(string source, string destination, int weight) {
    Edge *newEdge = new Edge;
    
    newEdge->destination = destination;
    newEdge->source = source;

    newEdge->weight = weight;

    bool checkDest = vertexExists(destination);
    bool checkSrc = vertexExists(source);

    bool checkEdge = edgeExists(source, destination);

    if(checkDest && checkSrc == true) {
        if(checkEdge == true) {
            cout << "That edge already exists." << endl;

        } else {
            edgeList.push_back(*newEdge);
        }
    } else {
        cout << "The source vertex " << source << " and destination vertex " << destination << " do not exist." << endl;
    }
}

bool Graph::edgeExists(string source, string destination) {
    list<Edge>::iterator it;
    for(it = edgeList.begin(); it != edgeList.end(); ++it){
        if(it->destination == destination) {
            if(it->source == source)
                return true;
        }
    } 
    return false;
}

bool Graph::vertexExists(string name) {
    list<Vertex>::iterator it;
    for(it = vertexList.begin(); it != vertexList.end(); ++it) {
        if(it->cityName == name) 
            return true;
    }
    return false;
}

void Graph::print() {
    list<Vertex>::iterator v;
    list<Edge>::iterator e;

    cout << "Printing Vertices..." << endl;
    for(v = vertexList.begin(); v != vertexList.end(); ++v)
        cout << v->cityName << endl;
    cout << "\nPrinting Edges..." << "\nSrc\tDest\tWeight" << endl;
    for(e = edgeList.begin(); e != edgeList.end(); ++e)
        cout << e->source << " -> " << e->destination << "\t" << e->weight << endl;
}