#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack() {
}

Stack::~Stack() {
}

bool Stack::isEmpty() {
    if (Stack1.returnHead() == nullptr) {
        cout << "Rỗng" << endl;
        return false;
    } else {
        return true;
    }
}

void Stack::push(int item) {
    Stack1.pushFront(item);
}

int Stack::pop() {
    if (Stack1.returnHead() == nullptr) {
        cout << "Rỗng" << endl;
        return -36;
    } else {
        Stack1.popFront();
    }
}

int Stack::top() {
    return Stack1.get(0);
}

int Stack::size() const {
    return Stack1.getSize();
}
