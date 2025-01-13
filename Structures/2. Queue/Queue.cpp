#include "Queue.h"
#include <stdexcept>

using namespace std;

// Add element in queue
void Queue::enqueue(int value) {
    if (isFull()) {
        return;
    }
    rear = (rear + 1) % capacity;
    data[rear] = value;
    ++size;
}

// Delete element from queue
int Queue::dequeue() {
    if (isEmpty()) {
        throw invalid_argument("The queue is empty!");
    }
    int value = data[front];
    front = (front + 1) % capacity;
    --size;
    return value;
}

// Get first element without deleting
int Queue::peek() const {
    if (isEmpty()) {
        throw invalid_argument("The queue is empty!");
    }
    return data[front];
}

int Queue::getSize() const {
    return size;
}

int Queue::getCapacity() const {
    return capacity;
}

vector<int> Queue::getQueue() const{
    vector<int> returnData = {};
    for (int i = 0; i < capacity; ++i) {
        returnData.push_back(data[i]);
    }
    return returnData;
}

// Is the element contained in the queue
bool Queue::contains(int value) const {
    for (int i = 0; i < size; ++i) {
        int index = (front + i) % capacity;
        if (data[index] == value) return true;
    }
    return false;
}

bool Queue::isEmpty() const {
    return size == 0;
}

bool Queue::isFull() const {
    return size == capacity;
}