# Purpose
The purpose of this project is to show the some application and usage of graph algorithms. The project uses two different algorithms: Dijkstra's algorithm for shortest
path, and Prim's algorithm for the minimum spanning tree. The Dijkstra's class uses an adjacency list, and Prim's uses an adjacency matrix, both are initialized in main.

# Implementation
The project consists of two files, prim.cpp and dijkstra.cpp. The file containing the mst is prim.cpp and the file containing the shortest path function is dijkstra.cpp.
Both files have a single class named Graph that contains their primary functions, and a main function that drives the code. 
prim.cpp uses two functions within the class: min_key, and min_span_tree. min_key is a private utility function designed to help the mst function by finding the minimum key value in the matrix of vertices. The min_span_tree function performs the mst and stores the result in a parent array. 
dijkstra.cpp uses three functions and contains two private variables. The first private variable is an int for vertices used throughout the class, and the second is a list that pairs two ints for use in the adjacency list. The three functions are a Graph funcition, an add_edge function, and a shortest_path funciton. The Graph function initializes the vertices by taking an int, the add_edge function allows you to add edges based on the vertices you initialized in the previous Graph function. And lastly, the shortest_path function uses a source node (0) to find the distance between each edge using priority queue. 

# Tests
## dijkstra.cpp
Graph Tests:
inputing 9 vertices --> init 9 vertices
inputting 0 vertices --> init 0 vertices 
      doesn't allow the rest of the code to function, because the graph cannot be initialized

add_edge Tests:
adding two of the same edges -->   
    g.add_edge(0, 1, 4);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 2, 4);  -->  0 - 0: 1 - 4: 2 - 8
      
adding only two components instead of three --> error

shortest_path Tests:
shortest path when there are 9 vertices --> 
                        distance from source
                        0       0
                        1       4
                        2       12
                        3       19
                        4       26
                        5       16
                        6       16
                        7       15
                        8       14
shortest path when there are duplicate edges --> 
    g.add_edge(0, 1, 4);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 2, 4);  -->  0 - 0: 1 - 4: 2 - 8

## prim.cpp
min_key Tests:
can't really test it as its only a utility function

min_span_tree Tests:
Matrix with 5 vertices (5x5) -->     
      int G[V][V] = {
                    {0, 9, 75, 0, 0},
                    {9, 0, 95, 19, 42},
                    {75, 95, 0, 51, 66},
                    {0, 19, 51, 0, 31},
                    {0, 42, 66, 31, 0}}; -->
                    
                    Edge    Weight
                    0 - 1   9
                    3 - 2   51
                    1 - 3   19
                    3 - 4   31
Matrix with 3 vertices (3x3) -->
    int G[V][V] = {
                    {0, 9, 75},
                    {9, 0, 95}, 
                    {75, 95, 0}}; -->

                    Edge    Weight
                    0 - 1   9
                    0 - 2   75

## Assignment Satisfaction
Design --> When I think of graphs I think of towns in a video game that are seperated by roads of arbitrary distances. In said game you want to find the shortest possible distance that it would take to get from town 0 to town 5, this is where things like minimum spanning trees and shortest path algorithms can come into play because they allow things like the ingame map to help guide the player along said shortest path.
Two Tests for each function --> There are two tests for all functions except the utility function min_key in prim.cpp mainly because I'm not sure how to test variably, considering it has a very specific job.
Graph Implementation --> there isn't really a function that lets the user create more vertices dynamically, but in dijkstra.cpp you can update the vertices as you please in main. In dijkstra.cpp there is an add_edge function that allows the user or developer to create edges for the adjacency list. In dijkstra.cpp there is a shortest path function that uses Dijkstra's algorithm. And lastly, in prim.cpp there is a minimum spanning tree function that uses Prim's algorithm.
Complexity analysis --> Because I used Dijkstra's algorithm the complexity should be O(Edges log(Vertices)) for time and O(Vertices), for the mst I used Prim's algorithm so the complexity should be  O(Edges log(Vertices)
