#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>

class Graph {
    std::map<int, std::vector<int>> adjList;
    std::vector<int> visitedNodes;

public:
    void addEdge(int from, int to);
    void DFS(int v);
};

#endif