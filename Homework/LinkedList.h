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
	Node* temp;
    int size;
public:
    LinkedList();
    ~LinkedList();
    void pushFront(int value);
    void pushBack(int value);
    int get(int index);
    
	void insertAt(int index, int value);
    void popFront();
    void popBack();
    void removeAt(int index);
    void traverse();
    void traverseReverse();
};

#endif // !LinkedList_H

