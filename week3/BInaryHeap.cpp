#include "BinaryHeap.h"
#include <bits/stdc++.h>

using namespace std;

void BinaryHeap::swim(int k) {
    while (k > 1 && heap[k / 2] < heap[k]) {
        swap(heap[k / 2], heap[k]);
        k = k / 2;
    }
}

void BinaryHeap::sink(int k)  {
    while (k * 2 + 1 < heap.size()) {
        int j = k * 2 + 1;
        //chọn con lớn hơn giữa trái và phải
        if (j + 1 < heap.size() && heap[j + 1] > heap[j])
            j++;
        if (heap[j] <= heap[k]) //cha lớn hơn bằng con thì dừng
            break;
        swap(heap[k], heap[j]);
        k = j;
    }
}

BinaryHeap::BinaryHeap() {
    heap.push_back(-1);
}


void BinaryHeap::insert(int data) {
    heap.push_back(data);
    swim(heap.size() - 1);
}

int BinaryHeap::delMax() {
    const int valMax = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    sink(0);
    return valMax;
}

bool BinaryHeap::isEmpty() const {
    return heap.empty();
}

int BinaryHeap::max() const {
    return heap[1];
}

int BinaryHeap::size() const {
    return heap.size() - 1;
}
