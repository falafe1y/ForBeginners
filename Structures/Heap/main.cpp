#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(6);
    maxHeap.insert(31);

    std::cout << "Max Heap: ";
    maxHeap.printHeap();

    std::cout << "Max Element: " << maxHeap.getMax() << std::endl;

    std::cout << "Extract Max: " << maxHeap.extractMax() << std::endl;

    std::cout << "Heap after extraction: ";
    maxHeap.printHeap();

    ////////////////////////////////////////////////////////////////

    MinHeap minHeap;

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);

    std::cout << "Max Heap: ";
    minHeap.printHeap();

    std::cout << "Max Element: " << minHeap.getMin() << std::endl;

    std::cout << "Extract Max: " << minHeap.extractMin() << std::endl;

    std::cout << "Heap after extraction: ";
    minHeap.printHeap();

    return 0;
}