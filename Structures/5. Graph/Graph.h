#pragma once

#include <unordered_map>
#include <list>

class Graph {
private:
    // Store adjacency list: vertex -> neighbor list
    std::unordered_map<int, std::list<int>> adjList;

public:
    // Add new edge
    void addEdge(int u, int v, bool isDirected = false);

    // Remove vertex
    void removeVertex(int vertex);

    // Remove edge
    void removeEdge(int u, int v);

    // Print graph
    void printGraph() const;

    // Check for existence of edge
    bool hasEdge(int u, int v) const;

    // Depth First Search (DFS)
    void DFS(int start, std::unordered_map<int, bool>& visited);

    void startDFS(int start);

    // Breadth First Search (BFS)
    void BFS(int start);
};
