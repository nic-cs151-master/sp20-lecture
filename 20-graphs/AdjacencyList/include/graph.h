#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <queue>
using std::vector;

class Graph
{
public:
    Graph(int numVertices);
    ~Graph();

    void addEdge(int src, int dest);
    void printGraph() const;

    void depthFirstSearch(int vertex) const;
    void breadthFirstSearch(int vertex) const;

private:
    vector<vector<int>> adjacencyList;

    void depthFirstSearch(int vertex, vector<bool> &visited) const;

};


#endif