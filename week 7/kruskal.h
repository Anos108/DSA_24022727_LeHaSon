

#ifndef DSA_24022727_LEHASON_KRUSKAL_H
#define DSA_24022727_LEHASON_KRUSKAL_H
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n);

    int find(int i);

    void unite(int x, int y);
};

bool comparator(vector<int> &a, vector<int> &b);

int mst(int V, vector<vector<int> > edges);


#endif //DSA_24022727_LEHASON_KRUSKAL_H
