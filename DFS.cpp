#include <iostream>
#include "Graph.hpp"

//To compile and run:
//g++ DFS.cpp Graph.cpp -o DFS
// ./DFS

int main(){
    std::cout << "----------Graph 1---------\n";
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 2);
    graph.DFS(0);


}