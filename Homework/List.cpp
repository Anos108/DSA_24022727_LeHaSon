#include "List.h"
#include <iostream>

using namespace std;

// Constructor
List::List() {
    size = 0;
    capacity = 10;
    arr = new int[capacity];
}

// Destructor
List::~List() {
    delete[] arr;
}

void List::resize() {
    //O(n)
    int newCapacity = capacity + 1;
    int *newArr = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

void List::pushFront(int value) {
    //O(n)
    if (size == capacity) {
        resize();
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}

void List::pushBack(int value) {
    //O(1)

    if (size == capacity) {
        resize();
    }
    arr[size] = value;
    size++;
}


void List::insertAt(int index, int value) {
    //O(n)
    // TODO
    if (index >= 0 && index <= size) {
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }
}


void List::popFront() {
    //O(n)
    if (size > 0) {
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}


void List::popBack() {
    //O(1)
    if (size > 0) {
        size--;
    }
}


void List::removeAt(int index) {
    //O(n)
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}


int List::get(int index) const {
    //O(1)

    if (index >= 0 && index < size) {
        return arr[index];
    }
    return 0;
}


void List::traverse() const {
    //O(n)

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void List::traverseReverse() const {
    //O(n)
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

int List::getSize() const {
    return size;
}

struct Stack {
    List list;

    bool isEmptyList() const {
        if (list.getSize() == 0) {
            cout << "Empty List" << endl;
            return true;
        }
        return false;
    }

    void pushList(int item) {
        list.pushFront(item);
    }

    int popList() {
        int temp = list.get(0);
        list.popBack();
        return temp;
    }

    int topList() const {
        return list.get(0);
    }

    int sizeList() const {
        return list.getSize();
    }
};

struct Queue {
    List list;

    bool isEmptyList() const {
        if (list.getSize() == 0) {
            cout << "Empty List" << endl;
            return true;
        }
        return false;
    }

    void enqueueList(int item) {
        list.pushBack(item);
    }

    int dequeueList() {
        int temp = list.get(0);
        list.popFront();
        return temp;
    }

    int frontList() const {
        return list.get(0);
    }

    int sizeList() const {
        return list.getSize();
    }
};
