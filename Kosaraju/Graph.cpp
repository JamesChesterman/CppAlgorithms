#include <iostream>
#include <vector>
#include <algorithm>

#include "Graph.hpp"

//Add edge from vertex 'from' to vertex 'to'
void Graph::addEdge(int from, int to){
    adjList[from].push_back(to);
}

//Set the adjacency list for a graph
//Maps from a vertex to a vector of vertices
void Graph::setAdjList(std::map<int, std::vector<int>> newAdjList){
    adjList = newAdjList;
}

//Goes through the graph and returns a new graph with all edges reversed
Graph Graph::edgeReversal(){
    std::map<int, std::vector<int>> newAdjList;
    for(const auto& vertexEntry : adjList){
        int from = vertexEntry.first;
        const std::vector<int>& verticesTo = vertexEntry.second;

        for(int vertexTo : verticesTo){
            newAdjList[vertexTo].push_back(from);
        }
    }
    Graph newGraph;
    newGraph.setAdjList(newAdjList);
    return newGraph;
}

//Prints the graph (unused currently - was used for debugging)
void Graph::printGraph(){
    for(const auto& vertexEntry : adjList){
        int from = vertexEntry.first;
        std::cout << "Vertex " << from << " goes to: ";
        const std::vector<int>& verticesTo = vertexEntry.second;
        for(int vertexTo : verticesTo){
            std::cout << vertexTo << " ";
        }
        std::cout << "\n";
    }
}

//Count the number of vertices in the graph using the adjacency list
int Graph::countVertices(){
    int count = 0;
    for(const auto& vertexEntry : adjList){
        if(!vertexEntry.second.empty()){
            count++;
        }
    }
    return count;
}

//Kosaraju's algorithm for getting the strongly connected components of a directed graph
//Does DFS searches for each vertex, appending these vertices to a stack too
//Then makes graph with all edges reversed (graph2)
//Does another set of DFS searches, this time in reverse order of the first set of searches
//Then prints out the sets of strongly connected components 
void Graph::Kosaraju(){
    k1();
    Graph graph2 = edgeReversal();
    graph2.k2(stack);

    for (size_t i = 0; i < graph2.connectedComponents.size(); i++) {
        std::cout << "Component " << i << ": ";
        for (size_t j = 0; j < graph2.connectedComponents[i].size(); j++) {
            std::cout << graph2.connectedComponents[i][j] << " ";
        }
        std::cout << "\n"; 
    }
}

//Goes through each vertex and does a DFS search
void Graph::k1(){
    while(markedVertices.size() < countVertices()){
        DFS1(0);
    }
}

//Does dfs search starting from a vertex, thus seeing which vertices are reachable from this vertex
void Graph::DFS1(int startFrom){
    markedVertices.push_back(startFrom);

    std::vector<int> children = adjList[startFrom];
    for(int i=0; i<children.size(); i++){
        if(std::find(markedVertices.begin(), markedVertices.end(), children[i]) == markedVertices.end()){
            //Vertex unmarked
            DFS1(children[i]);
        }
    }

    stack.push(startFrom);
}

//Goes through the stack and pops the top of it
//With each of these vertices, if it's unmarked then do a DFS search on it to see which components are reachable
void Graph::k2(std::stack<int>& stack1){
    while(!stack1.empty()){
        int vertex = stack1.top();
        stack1.pop();
        if(std::find(markedVertices.begin(), markedVertices.end(), vertex) == markedVertices.end()){
            std::vector<int> component;
            DFS2(vertex, component);
            connectedComponents.push_back(component);
        }
    }
}

//Does DFS search on graph to see which vertices are reachable from the 'startFrom' vertex
//Adds these to a component
void Graph::DFS2(int startFrom, std::vector<int>& component){
    markedVertices.push_back(startFrom);
    component.push_back(startFrom);
    std::vector<int> children = adjList[startFrom];
    for(int i=0; i<children.size(); i++){
        if(std::find(markedVertices.begin(), markedVertices.end(), children[i]) == markedVertices.end()){
            DFS2(children[i], component);
        }
    }
}
