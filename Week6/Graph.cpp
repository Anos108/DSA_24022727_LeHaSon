#include "Graph.h"
#include <iostream>
#include <vector>

Graph::Graph(int num_vertices) {
    Number_Of_Verticles = num_vertices;
    adj.resize(num_vertices);
}

void Graph::addEdge(int v, int neighbor) {
    adj[v].push_back(neighbor);
}

void Graph::printAdjList(int a) const {
    for (int neighbor : adj[a]) {
        cout << neighbor << " ";
    }
}
