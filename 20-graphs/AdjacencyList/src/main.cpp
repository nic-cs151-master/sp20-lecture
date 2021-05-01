#include <iostream>
#include "graph.h"

int main(int argc, char *argv[])
{
    const int NUM_VERTICES = 6;
    Graph graph(NUM_VERTICES);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(0, 5);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 2);
    graph.addEdge(3, 4);
    graph.addEdge(2, 1);
    
    graph.printGraph();
    std::cout << "\n";
    graph.depthFirstSearch(3);
    std::cout << "\n";
    graph.breadthFirstSearch(3);
    std::cout << "\n";

    return 0;
}
