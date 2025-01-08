#include <iostream>
#include <vector>
#include <stdexcept>

class MaxHeap {
    std::vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void insert(int value);
    int extractMax();
    int getMax() const;
    void printHeap() const;
};