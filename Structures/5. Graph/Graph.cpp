#include <iostream>
#include <vector>
#include "Graph.h"

// Add new edge
void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v); // Add edge u -> v
    if (!isDirected) {
        adjList[v].push_back(u); // Add a reverse edge v -> u if the graph is undirected
    }
}

// Remove vertex
void Graph::removeVertex(int vertex) {
    adjList.erase(vertex); // Remove the vertex and all its outgoing connections
    for (auto& pair : adjList) {
        pair.second.remove(vertex); // Remove incoming links to this vertex
    }
}

// Remove edge
void Graph::removeEdge(int u, int v) {
    adjList[u].remove(v); // Delete edge u -> v
    adjList[v].remove(u); // Remove edge v -> u (if graph is undirected)
}

// Print graph
void Graph::printGraph() const {
    for (const auto& pair : adjList) {
        std::cout << pair.first << " -> ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

// Check for existence of edge
bool Graph::hasEdge(int u, int v) const {
    if (adjList.find(u) == adjList.end()) return false;
    for (int neighbor : adjList.at(u)) {
        if (neighbor == v) return true;
    }
    return false;
}

// Depth First Search (DFS)
void Graph::DFS(int start, std::unordered_map<int, bool>& visited) {
    visited[start] = true;
    std::cout << start << " ";

    for (int neighbor : adjList[start]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited);
        }
    }
}

void Graph::startDFS(int start) {
    std::unordered_map<int, bool> visited;
    for (const auto& pair : adjList) {
        visited[pair.first] = false; // Initialize visits
    }
    std::cout << "DFS: ";
    DFS(start, visited);
    std::cout << std::endl;
}

// Breadth First Search (BFS)
void Graph::BFS(int start) {
    std::unordered_map<int, bool> visited;
    for (const auto& pair : adjList) {
        visited[pair.first] = false;
    }

    std::list<int> queue;
    visited[start] = true;
    queue.push_back(start);

    std::cout << "BFS: ";
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop_front();
        std::cout << current << " ";

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }
    std::cout << std::endl;
}
