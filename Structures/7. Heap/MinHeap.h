#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
    std::vector<int> heap;

    void heapifyUp(int index);

    void heapifyDown(int index);

public:

    void insert(int value);

    int extractMin();

    int getMin() const;

    void printHeap() const;
};