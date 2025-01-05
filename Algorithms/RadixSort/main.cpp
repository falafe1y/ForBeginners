#include <iostream>
#include "RadixSort.h"

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}