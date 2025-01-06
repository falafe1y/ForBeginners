#include <iostream>
#include "RadixSort.h"

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "source array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}