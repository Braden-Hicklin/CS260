#include <iostream>

#include "graph.h"

using namespace std;

void Graph::addVertex(string name){
    Vertex *newVertex = new Vertex;
    
    newVertex->cityName = name;

    bool checkVertex = vertexExists(name);
    if(checkVertex == true) {
        cout << "That Vertex already exists" << endl;

    } else {
        vertexList.push_back(newVertex);
    }
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
                if(vertexList.at(i)->cityName == source)
                    newEdge->source = vertexList.at(i);
                if(vertexList.at(i)->cityName == destination)
                    newEdge->destination = vertexList.at(i);
            }
            newEdge->weight = weight;
            edgeList.push_back(newEdge);
        }
    } else {
        cout << "The source vertex " << source << " and destination vertex " << destination << " do not exist." << endl;
    }
}

bool Graph::edgeExists(string source, string destination) {
    for(int i = 0; i < edgeList.size(); i++) {
        if(edgeList.at(i)->source->cityName == source) {
            if(edgeList.at(i)->destination->cityName == destination) {
                return true;
            }
        }
    }
    return false;
}

bool Graph::vertexExists(string name) {
    for(int i = 0; i < vertexList.size(); i++) {
        if(vertexList.at(i)->cityName == name) {
            return true;
        }
    }

    return false;
}

void Graph::print() {

    cout << "Printing Vertices..." << endl;
    for(int v = 0; v < vertexList.size(); v++)
        cout << vertexList.at(v)->cityName << endl;

    cout << "\nPrinting Edges..." << "\nSrc\tDest\tWeight" << endl;
    for(int e = 0; e < edgeList.size(); e++)
        cout << edgeList.at(e)->source->cityName << " -> " << edgeList.at(e)->destination->cityName << "\t" << edgeList.at(e)->weight << endl;
}
