#include <algorithm>
#include <iostream>

#include "Graph.hpp"
/*
 std::map<int, std::list<int>> adjList;
    std::list<int> visitedNodes;
*/

void Graph::addEdge(int from, int to){
    adjList[from].push_back(to);
}

void Graph::DFS(int startFrom){
    visitedNodes.push_back(startFrom);
    std::cout << startFrom << " has been visited\n";

    std::vector<int> children = adjList[startFrom];
    //std::cout << children.size();
    for(int i=0; i<children.size(); i++){
        if(std::find(visitedNodes.begin(), visitedNodes.end(), children[i]) == visitedNodes.end()){
            //Vertex unmarked
            DFS(children[i]);
        }
    }
}

