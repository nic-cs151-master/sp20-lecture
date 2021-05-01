#include "graph.h"

// member intializatino list
Graph::Graph(int numVertices) : adjacencyMatrix(numVertices, vector<int>(numVertices, 0))
{}

Graph::~Graph()
{}


void Graph::addEdge(int src, int dest)
{
    if (src < 0 || src >= adjacencyMatrix.size() || dest < 0 || dest >= adjacencyMatrix.size())
    {
        throw std::runtime_error("vertex does not exist!");
    }

    adjacencyMatrix[src][dest] = 1;
}

void Graph::printGraph() const
{
    for (int i = 0; i < adjacencyMatrix.size(); ++i)
    {
        // print the current vertex number
        std::cout << i << " ---> ";

        // print all adjacent vertices of the current vertex
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
        {
            if (adjacencyMatrix[i][j] == 1)
                std::cout << j << " ";
        }

        std::cout << '\n';
    }

}
