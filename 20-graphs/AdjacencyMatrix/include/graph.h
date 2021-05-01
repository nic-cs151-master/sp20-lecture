#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept>
#include <iostream>
using std::vector;

class Graph
{
public:
    Graph(int numVertices);
    ~Graph();

    void addEdge(int src, int dest);
    void printGraph() const;

private:
    vector<vector<int>> adjacencyMatrix;
};

#endif