#include <iostream>
#include "InsertSort.h"

using namespace std;

void InsertSort(vector<int> *arr) {

    // Debug =====================
    cout << "Source vector:" << '\n';
    for (int i = 0; i < arr->size(); ++i) {
            cout << (*arr)[i] << ' ';
        }
    cout << "\n\n";
    // Debug =====================

    // Insert sorting
    for (int currentIndex = 1; currentIndex < arr->size(); ++currentIndex) { 
        int temp = (*arr)[currentIndex];        // The current element
        int sortedIndex = currentIndex - 1;     // Start from the end of the sorted part

        // Debug =====================
        cout << "temp = " << temp << '\n';
        cout << "Sorted num = " << (*arr)[sortedIndex] << '\n';
        // Debug =====================

        while (sortedIndex >= 0 && (*arr)[sortedIndex] > temp) {
            (*arr)[sortedIndex + 1] = (*arr)[sortedIndex];      // If sortedIndex > temp to, we move sortedIndex to the right
            sortedIndex--;
        }
        (*arr)[sortedIndex + 1] = temp;

        // Debug =====================
        cout << "Iteration №" << currentIndex << '\n';
        for (int i = 0; i < arr->size(); ++i) {
            cout << (*arr)[i] << ' ';
        } 
        cout << "\n\n";
        // Debug =====================
    }
}
