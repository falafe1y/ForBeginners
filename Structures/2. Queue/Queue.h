#pragma once
#include <vector>

class Queue {
private:
    int* data;       // Array for storing elements
    int capacity;    // Queue capacity
    int front;       // Queue start index
    int rear;        // Queue end index
    int size;        // Current size of queue

public:
    explicit Queue(int capacity) : capacity(capacity), front(0), rear(-1), size(0) {
        data = new int[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    // Add element in queue
    void enqueue(int value);

    // Delete element from queue
    int dequeue();

    // Get first element without deleting
    int peek() const;

    int getSize() const;

    int getCapacity() const;

    std::vector<int> getQueue() const; 

    // Is the element contained in the queue
    bool contains(int value) const;

    bool isEmpty() const;
    
    bool isFull() const;
};