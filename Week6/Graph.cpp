#include "Graph.h"
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

Graph::Graph(int num_vertices) {
    Number_Of_Verticles = num_vertices;
    adj.resize(num_vertices);
}

void Graph::addEdge(int v, int neighbor) {
    adj[v].push_back(neighbor);
}

void Graph::printAdjList(int a) const {
    for (int neighbor: adj[a]) {
        cout << neighbor << " ";
    }
}

void Graph::DFS(int u, vector<bool> visited, vector<int> parent) {
    visited[u] = true;
    for (int neighbor: adj[u]) {
        if (!visited[neighbor]) {
            parent[neighbor] = u;
            DFS(neighbor, visited, parent);
        }
    }
}

void Graph::BFS(int start) {
    queue<int> q;
    vector visited(start, false);
    vector<int> dist(start,INFINITY);
    vector<int> parent;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}
