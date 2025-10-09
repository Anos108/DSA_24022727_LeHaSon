#ifndef DSA_24022727_LEHASON_BINARYHEAP_H
#define DSA_24022727_LEHASON_BINARYHEAP_H
#include <vector>
using namespace std;

class BinaryHeap {
private:
    vector<int> heap;

    void swim(int k);


    void sink(int k);

public:
    BinaryHeap();

    void insert(int data);

    int delMax();

    bool isEmpty() const;

    int max() const;

    int size() const;


};
#endif //DSA_24022727_LEHASON_BINARYHEAP_H
