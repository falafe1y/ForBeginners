#include <iostream>
#include <vector>
#include <stdexcept>
#include "MinHeap.h"

void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void MinHeap::heapifyDown(int index) {
    int size = heap.size();
    while (index < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void MinHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int MinHeap::extractMin() {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    int minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return minValue;
}

int MinHeap::getMin() const {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}

void MinHeap::printHeap() const {
    for (int val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}