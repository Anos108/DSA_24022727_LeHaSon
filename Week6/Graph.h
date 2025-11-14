//
// Created by lehas on 11/14/2025.
//

#ifndef DSA_24022727_LEHASON_GRAPH_H
#define DSA_24022727_LEHASON_GRAPH_H
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int Number_Of_Verticles;
    vector<vector<int> > adj;

public:
    Graph(int num_vertices);

    void addEdge(int v, int neighbor);

    void printAdjList(int adjacency_list) const;
};


#endif //DSA_24022727_LEHASON_GRAPH_H
