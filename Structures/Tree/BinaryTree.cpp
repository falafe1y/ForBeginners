#include "BinaryTree.h"
#include <queue>

void BinaryTree::insertPrivate(Node* node, int value, const std::string& direction) {
    if (direction == "left") {
        if (node->left == nullptr) {
            node->left = new Node(value);
        } else {
            insertPrivate(node->left, value, direction);
        }
    } else if (direction == "right") {
        if (node->right == nullptr) {
            node->right = new Node(value);
        } else {
            insertPrivate(node->right, value, direction);
        }
    } else {
        return;
    }
}

void BinaryTree::inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void BinaryTree::postorder(Node* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}

void BinaryTree::preorder(Node* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BinaryTree::BFS(Node* node) {
    if (!root) return;
    std::queue<Node*> treeQueue;
    treeQueue.push(root);
    
    while (!treeQueue.empty()) {
        Node* node = treeQueue.front();
        treeQueue.pop();
        std::cout << node->data << " ";
        
        if (node->left) treeQueue.push(node->left);
        if (node->right) treeQueue.push(node->right);
    }
}

void BinaryTree::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroy(root);
}

void BinaryTree::insert(int value, const std::string& direction) {
    if (root == nullptr) {
        root = new Node(value);
    } else {
        insertPrivate(root, value, direction);
    }
}

void BinaryTree::inorder() {
    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;
}

void BinaryTree::postorder() {
    std::cout << "Postorder traversal: ";
    postorder(root);
    std::cout << std::endl;
}

void BinaryTree::preorder() {
    std::cout << "Preorder traversal: ";
    preorder(root);
    std::cout << std::endl;
}

void BinaryTree::BFS() {
    std::cout << "BFS: ";
    BFS(root);
    std::cout << '\n';
}