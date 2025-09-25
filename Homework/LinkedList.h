#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
public:
    LinkedList();
    ~LinkedList();
    void pushFront(int value);
    void pushBack(int value);
    void popFront();
    void popBack();
    void removeAt(int index);
    void traverse() const;
    void traverseReverse() const;
};

#endif // !LinkedList_H

