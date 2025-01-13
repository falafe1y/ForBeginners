#pragma once

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head; // Pointer to begin of list
    size_t size; // Size of list

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    // Print list
    void print() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    size_t get_size() const {
        return size;
    }

    bool is_empty() const {
        return head == nullptr;
    }
};