#include "LinkedList.h"
#include <iostream>
#include <vector>
using namespace std;


LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}




LinkedList::~LinkedList() {
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int LinkedList::getSize() const {
    return size;
}

LinkedList::Node * LinkedList::returnHead() const {
    return head;
}

void LinkedList::pushFront(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    size++;
}


void LinkedList::pushBack(int value) {
    temp = head;
    if (head == NULL) {
        pushFront(value);
        return;
    }
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

void LinkedList::insertAt(int index, int value) {
    // TODO
    Node *newNode = new Node;
    newNode->data = value;
    if (index == 0) {
        pushFront(value);
        return;
    }
    temp = head;
    for (int i = 1; i < index; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    size++;
}

// Xóa phần tử đầu
void LinkedList::popFront() {
    temp = head;
    head = head->next;
    delete temp;
    size--;
}

// Xóa phần tử cuối
void LinkedList::popBack() {
    if (head == nullptr) return;
    if (size == 0) head = nullptr;

    temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    size--;
}

// Xóa phần tử tại vị trí index
void LinkedList::removeAt(int index) {
    if (index < 0 || index >= size) return;
    if (index == 0) popFront();
    temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    size--;
}

// Lấy giá trị tại index
int LinkedList::get(int index) {
    if (index < 0 || index >= size) return -1;
    temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}


void LinkedList::traverse() {
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


void LinkedList::traverseReverse() {
    vector<int> arr;
    temp = head;
    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}
