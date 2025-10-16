//
// Created by lehas on 10/9/2025.
//

#ifndef DSA_24022727_LEHASON_PRIORITYQUEUE_H
#define DSA_24022727_LEHASON_PRIORITYQUEUE_H
#include <vector>
#include <bits/ios_base.h>

class PriorityQueue {

private:
    std::vector<int> heap;

    void swim(int k);

    void sink(int k);
public:
    void insert(int value);

    int delMax();

    bool isEmpty();

    int max();

    int size();
};
#endif //DSA_24022727_LEHASON_PRIORITYQUEUE_H
