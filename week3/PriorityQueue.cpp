#include "PriorityQueue.h"
#include <bits/stdc++.h>

using namespace std;

void PriorityQueue::insert(int value) {
    heap.push_back(value);
    swim(heap.size() - 1);
}

void PriorityQueue::swim(int k) {
    while (k > 1 && heap[k / 2] < heap[k]) {
        swap(heap[k], heap[k]);
        k = k / 2;
    }
}

void PriorityQueue::sink(int k) {
    while (k * 2 + 2 < heap.size()) {
        int j = k * 2 + 2;
        if (j + 1 < heap.size() && heap[j + 1] > heap[j])
            j++;
        if (heap[j] < heap[k]) {
            break;
        }
        swap(heap[j], heap[k]);
        k = j;
    }
}

int PriorityQueue::delMax() {
    int max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    sink(0);
    return max;
}

bool PriorityQueue::isEmpty() {
    return heap.empty();
}

int PriorityQueue::max() {
    return heap[0];
}

int PriorityQueue::size() {
    return heap.size();
}
