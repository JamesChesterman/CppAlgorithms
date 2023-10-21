#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <stack>

class Graph{
    std::map<int, std::vector<int>> adjList;
    std::vector<int> markedVertices;
    std::stack<int> stack;
    std::vector<std::vector<int>> connectedComponents;

public:
    void addEdge(int from, int to);
    void setAdjList(std::map<int, std::vector<int>> newAdjList);
    Graph edgeReversal();
    void printGraph();
    int countVertices();
    void Kosaraju();
    void k1();
    void DFS1(int startFrom);
    void k2(std::stack<int>& stack1);
    void DFS2(int startFrom, std::vector<int>& component);
};

#endif