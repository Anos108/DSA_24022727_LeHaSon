#include "prim.h"

#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

using namespace std;

int findMST(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> adj[V];


    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


    vector<bool> visited(V, false);


    int res = 0;


    pq.push({0, 0});

    // Perform Prim's algorithm to find the Minimum Spanning Tree
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int wt = p.first;  // Weight of the edge
        int u = p.second;  // Vertex connected to the edge

        if(visited[u] == true){
            continue;  // Skip if the vertex is already visited
        }

        res += wt;  // Add the edge weight to the result
        visited[u] = true;  // Mark the vertex as visited

        // Explore the adjacent vertices
        for(auto v : adj[u]){
            // v[0] represents the vertex and v[1] represents the edge weight
            if(visited[v[0]] == false){
                pq.push({v[1], v[0]});  // Add the adjacent edge to the priority queue
            }
        }
    }

    return res;
}
