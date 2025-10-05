
#ifndef DSA_24022727_LEHASON_STACK_H
#define DSA_24022727_LEHASON_STACK_H
#include "LinkedList.h"
class Stack {
private:
    LinkedList Stack1;

public:
    Stack();

    ~Stack();

    bool isEmpty();

    void push(int item);

    int pop();

    int top();

    int size() const;
};

#endif //DSA_24022727_LEHASON_STACK_H
