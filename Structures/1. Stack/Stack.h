#pragma once

// Template class (a class whose methods can operate with any data type).
template<typename T>
class Stack {
private:
    struct Node {
        T data;          // Node's data
        Node* next;      // Last top of the stack

        Node(const T &value, Node* nextNode = nullptr) {
            data = value;
            next = nextNode;
            std::cout << "New node created!\n";
        }
    };

    Node* topNode;  // Pointer to the top of the stack
    size_t size;    // Current stack size

public:
    Stack() : topNode(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        topNode = new Node(value, topNode);
        ++size;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        --size;
    }

    // Get the element from the top
    T& top() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
        }
        return topNode->data;
    }

    // Get the element from the top of the stack (constant method).
    const T& top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
        }
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    size_t getSize() const {
        return size;
    }
};