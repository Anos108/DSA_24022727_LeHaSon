//
// Created by lehas on 10/16/2025.
//

#ifndef DSA_24022727_LEHASON_BINARYSEARCHTREE_H
#define DSA_24022727_LEHASON_BINARYSEARCHTREE_H

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node *left;
        Node *right;
    };

    Node *root;

    Node *insertRecursive(Node * &cur, int data);

public:
    void insert(int data);

    void preOrder(Node* cur);

    void inOrder(Node* cur);

    void postOrder(Node * cur);
};


#endif //DSA_24022727_LEHASON_BINARYSEARCHTREE_H
