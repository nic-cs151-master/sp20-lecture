#include <iostream>
#include "graph.h"

int main(int argc, char *argv[])
{
    const int NUM_VERTICES = 6;
    Graph graph(NUM_VERTICES);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 1);
    graph.addEdge(3, 2);
    graph.addEdge(4, 5);
    graph.addEdge(5, 4);
    
    graph.printGraph();

    return 0;
}
