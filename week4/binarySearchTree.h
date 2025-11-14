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
        int height;
    };

    Node *root;

    static Node *insertRecursive(Node * &cur, int data);

public:
    BinarySearchTree();

    void insert(int data);

    static void preOrder(const Node *cur);

    static void inOrder(Node *cur);

    static void postOrder(Node *cur);

    Node *getRoot() const {
        return root;
    }

    static int getHeight(Node* node) {
        if (node) {
            return node->height;
        }
        else {
            return 0;
        }
    }
    static int getBalanceFactor(Node* node) {
        return node->left->height - node->right->height;
    }
    static Node* rotate_right(Node* y);

    static Node* rotate_left(Node*x);
};


#endif //DSA_24022727_LEHASON_BINARYSEARCHTREE_H
