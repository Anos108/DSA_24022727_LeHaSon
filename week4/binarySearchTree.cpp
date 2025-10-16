#include "binarySearchTree.h"
#include <bits/stdc++.h>

using namespace std;

BinarySearchTree::Node *BinarySearchTree::insertRecursive(Node *&cur, int data) {
    if (cur == nullptr) {
        cur = new Node{data, nullptr, nullptr};
        return cur;
    }
    if (data < cur->data) {
        insertRecursive(cur->left, data);
    } else if (data > cur->data){
        insertRecursive(cur->right, data);
    }
    return cur;
}

void BinarySearchTree::insert(int data) {
    insertRecursive(root, data);
}

void BinarySearchTree::preOrder(Node *cur) {
    if (cur != nullptr) {
        cout << cur->data << " ";
        preOrder(cur->left);
        preOrder(cur->right);
    } else {
        return;
    }
}

void BinarySearchTree::inOrder(Node *cur) {
    if (cur != nullptr) {
        inOrder(cur->left);
        cout << cur->data << " ";
        inOrder(cur->right);
    } else {
        return;
    }
}

void BinarySearchTree::postOrder(Node *cur) {
    if (cur != nullptr) {
        postOrder(cur->left);
        postOrder(cur->right);
        cout << cur->data << " ";
    }
}
