#include <iostream>
#include "InsertSort.h"

using namespace std;

void InsertSort(vector<int> *arr) {
    // Insert sorting
    for (int currentIndex = 1; currentIndex < arr->size(); ++currentIndex) { 
        int temp = (*arr)[currentIndex];        // The current element
        int sortedIndex = currentIndex - 1;     // Start from the end of the sorted part

        while (sortedIndex >= 0 && (*arr)[sortedIndex] > temp) {
            (*arr)[sortedIndex + 1] = (*arr)[sortedIndex];      // If sortedIndex > temp to, we move sortedIndex to the right
            sortedIndex--;
        }
        (*arr)[sortedIndex + 1] = temp;
    }
}
