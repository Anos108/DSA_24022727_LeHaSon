#include <vector>
#include <iostream>
#include "kruskal.h"
#include <algorithm>
using namespace std;

DSU::DSU(int n) {
    rank.resize(n);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}

int DSU::find(int i) {
    return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
}

void DSU::unite(int x, int y) {
    int s1 = find(x), s2 = find(y);
    if (s1 != s2) {
        if (rank[s1] < rank[s2]) parent[s1] = s2;
        else if (rank[s1] > rank[s2]) parent[s2] = s1;
        else parent[s2] = s1, rank[s1]++;
    }
}

bool comparator(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int mst(int V, vector<vector<int> > edges) {
    sort(edges.begin(), edges.end(), comparator); //sort the tree by the weight

    // Traverse edges in sorted order
    DSU dsu(V);
    int cost = 0, count = 0;

    for (auto &e: edges) {
        int x = e[0], y = e[1], w = e[2];
        if (dsu.find(x) != dsu.find(y)) {
            dsu.unite(x, y);
            cost += w;
            count++;
            if (count == V - 1) break;
        }
    }
    return cost;
}

int main() {
    // An edge contains a source, destination and weight
    vector<vector<int> > edges = {
        {1, 4, 1}, {1, 2, 2}, {2, 3, 3}, {2, 4, 3}, {1, 5, 4}, {3, 4, 5}, {2, 6, 7}, {3, 6, 8}, {4, 5, 9}
    };

    cout << mst(9, edges);

    return 0;
}
