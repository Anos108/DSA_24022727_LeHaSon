#include <iostream>
#include <vector>

#include "List.h"
#include "LinkedList.h"
#include "sort.h"
using namespace std;

int main() {

    List myList;
    myList.pushBack(2);
    myList.pushBack(8);
    myList.pushFront(5);
    myList.insertAt(0, 13);
    myList.traverse();
    myList.popBack();
    myList.traverse();
    myList.popFront();
    myList.traverse();
    cout << myList.get(0) << endl;
    myList.traverseReverse();
    cout << endl << endl;

    LinkedList myLinkedList;
    myLinkedList.pushBack(10);
    myLinkedList.pushFront(20);
    myLinkedList.traverse();
    myLinkedList.popBack();
    myLinkedList.traverse();
    myLinkedList.popFront();
    myLinkedList.traverse();
    cout << myLinkedList.get(0);
    myLinkedList.traverseReverse();

    vector arr = {1,3,8,2,6,4};
    insertionSort(arr);
    for (int x : arr) {
        cout << x << " ";
    }

}
