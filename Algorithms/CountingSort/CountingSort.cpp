#include <iostream>
#include <vector>
#include <algorithm>
#include "CountingSort.h"

void CountingSort(std::vector<int> *arr) {
    // If array is empty exit from func
    if (arr->empty()) return;


    // Find the maximum element
    int maxElement = *max_element(arr->begin(), arr->end());

    // Create a vector of size maxElement + 1, 
    // where all elements are 0
    std::vector<int> count(maxElement + 1, 0);

    // Calculate the frequency of occurrence of each element
    for (int num : *arr) {
        count[num]++;
    }

    // Overwrite the original array taking into account the count
    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        std::cout << "Itteration №" << i+1 << ": ";
        while (count[i] > 0) {
            (*arr)[index++] = i;
            count[i]--;
        }
        for (int num : *arr) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
}