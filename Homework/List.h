#ifndef LIST_H
#define LIST_H

class List {
private:
    int *arr;
    int size;
    int capacity;

public:
    List();

    ~List();

    void resize();

    void pushFront(int value);

    void pushBack(int value);

    void insertAt(int index, int value);

    void popFront();

    void popBack();

    void removeAt(int index);

    int get(int index) const;

    void traverse() const;

    void traverseReverse() const;

    int getSize() const;
};

#endif
