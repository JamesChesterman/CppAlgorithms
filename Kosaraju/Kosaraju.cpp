#include <iostream>
#include "Graph.hpp"

//g++ Kosaraju.cpp Graph.cpp -o Kosaraju

int main(){
    Graph graph;

    graph.addEdge(0, 1);
    graph.addEdge(0, 8);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 0);
    graph.addEdge(3, 4);
    graph.addEdge(3, 7);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);
    graph.addEdge(5, 3);
    graph.addEdge(7, 6);

    /*
    graph.printGraph();
    std::cout << "------------------ new ----------------------";
    Graph newGraph = graph.edgeReversal();
    newGraph.printGraph();
    */

    graph.Kosaraju();
}