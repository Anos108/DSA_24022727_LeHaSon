#include "dijkstra_shortest_path.h"

#include <iostream>
#include <climits>
#include <queue>
using namespace std;

vector<int> dijkstra_shortest_path(vector<vector<pair<int, int>>> &adj, int source) {
    int vertex = adj.size();

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> distance (vertex, INT_MAX);
    distance[source] = 0;
    pq.emplace(0,source);
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int dist = top.first;
        int node = top.second;
        if (dist > distance[node]) continue;
        for (auto iterator : adj[node]) {
            int v = iterator.first;
            int w = iterator.second;
           if (distance[v] > distance[node] + w) {
               distance[v] = distance[node] + w;
               pq.emplace(distance[v],v);
           }
        }
    }
    return distance;
}

