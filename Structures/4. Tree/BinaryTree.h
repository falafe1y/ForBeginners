#pragma once

#include <iostream>

class BinaryTree {
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    
    void insertPrivate(Node* node, int value, const std::string& direction);
    
    void inorder(Node* node);

    void postorder(Node* node);

    void preorder(Node* node);

    void BFS(Node* node);

    void destroy(Node* node);

public:
    BinaryTree();

    ~BinaryTree();

    void insert(int value, const std::string& direction);

    void inorder();

    void postorder();

    void preorder();

    void BFS();
};