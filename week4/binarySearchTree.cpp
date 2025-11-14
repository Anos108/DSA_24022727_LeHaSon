#include "binarySearchTree.h"
#include <bits/stdc++.h>

using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::Node *BinarySearchTree::insertRecursive(Node *&cur, int data) {
    if (cur == nullptr) {
        cur = new Node{data, nullptr, nullptr};
        return cur;
    }
    if (data < cur->data) {
        insertRecursive(cur->left, data);
    } else if (data > cur->data) {
        insertRecursive(cur->right, data);
    }
    return cur;
}

void BinarySearchTree::insert(int data) {
    insertRecursive(root, data);
}

void BinarySearchTree::preOrder(const Node *cur) {
    if (cur != nullptr) {
        cout << cur->data << " ";
        preOrder(cur->left);
        preOrder(cur->right);
    }
}

void BinarySearchTree::inOrder(Node *cur) {
    if (cur != nullptr) {
        inOrder(cur->left);
        cout << cur->data << " ";
        inOrder(cur->right);
    }
}

void BinarySearchTree::postOrder(Node *cur) {
    if (cur != nullptr) {
        postOrder(cur->left);
        postOrder(cur->right);
        cout << cur->data << " ";
    }
}

BinarySearchTree::Node *BinarySearchTree::rotate_right(Node *y) {
    printf("Rotate right on node %c\n", y->data);
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

BinarySearchTree::Node *BinarySearchTree::rotate_left(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}
