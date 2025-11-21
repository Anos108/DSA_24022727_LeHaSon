#include "prim.h"

#include <queue>
#include <vector>

using namespace std;

int findMST(vector<vector<int>> edges,int V, int E) {
    //tạo danh sách kề
    vector<vector<int>> adj[V];
    for (int i = 0; i < E;i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt= edges[i][2];
        adj[u].push_back({wt,v});
        adj[v].push_back({wt,u});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    vector visited (V, false);
    int res = 0;
    pq.emplace(0,0);
    while (!pq.empty()) {
        auto top = pq.top();
        int wt = top.first;
        int u = top.second;
        pq.pop();

        // kiểm tra chu trình
        if (visited[u] == true) continue;
        res += wt;
        visited[u] = true;
        for (auto v : adj[u]) {
            // v[1] đỉnh v[0] trọng số
            if (visited[v[1]] == false) {
                pq.emplace(v[0],v[1]);
            }
        }
    }
    return res;
}
