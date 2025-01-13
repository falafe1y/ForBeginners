#include <iostream>
#include "Graph.h"

int main() {
    Graph graph;

    // Add vertices and edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    // Output the graph
    std::cout << "Graph structure:" << std::endl;
    graph.printGraph();

    // Perform DFS
    graph.startDFS(1);

    // Perform BFS
    graph.BFS(1);

    // Check for edge presence
    std::cout << "Has edge (1 -> 3): " << (graph.hasEdge(1, 3) ? "Yes" : "No") << std::endl;

    // Remove the vertex and output the updated graph
    graph.removeVertex(4);
    std::cout << "Graph after removing vertex 4:" << std::endl;
    graph.printGraph();

    return 0;
}
