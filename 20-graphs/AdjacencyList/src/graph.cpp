#include "graph.h"

// member intializatino list
Graph::Graph(int numVertices) : adjacencyList(numVertices)
{}

Graph::~Graph()
{}


void Graph::addEdge(int src, int dest)
{
    if (src < 0 || src >= adjacencyList.size() || dest < 0 || dest >= adjacencyList.size())
    {
        throw std::runtime_error("vertex does not exist!");
    }

    adjacencyList[src].push_back(dest);
}

void Graph::printGraph() const
{
    for (int i = 0; i < adjacencyList.size(); ++i)
    {
        // print the current vertex number
        std::cout << i << " ---> ";

        // print all adjacent vertices of the current vertex
        for (int adjacentVertex : adjacencyList[i])
        {
            std::cout << adjacentVertex << " ";
        }

        std::cout << '\n';
    }

}

void Graph::depthFirstSearch(int vertex) const
{
    vector<bool> visited(adjacencyList.size(), false);
    depthFirstSearch(vertex, visited);
}

void Graph::depthFirstSearch(int vertex, vector<bool> &visited) const
{
    visited[vertex] = true;

    std::cout << vertex << ' ';

    for (auto it = adjacencyList[vertex].begin(); it != adjacencyList[vertex].end(); ++it)
    {
        if (!visited[*it])
            depthFirstSearch(*it, visited);
    }
}

void Graph::breadthFirstSearch(int vertex) const
{
    vector<bool> visited(adjacencyList.size(), false);
    std::queue<int> bfsQueue;

    // mark current vertex as visited
    visited[vertex] = true;
    // add current vertex to the queue
    bfsQueue.push(vertex);

    while (!bfsQueue.empty())
    {
        // dequeue a vertex from the queue
        vertex = bfsQueue.front();
        std::cout << vertex << ' ';
        bfsQueue.pop();

        // go through all the adjacent vertices of the current vertex
        // and add them to the queue if needed
        for (auto it = adjacencyList[vertex].begin(); it != adjacencyList[vertex].end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                bfsQueue.push(*it);
            }
        }
    }
}