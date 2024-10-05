#include <iostream>
#include <algorithm>
#include "BubbleSort.h"

using namespace std;

void BubbleSort(vector<int> *arr) {
    int size = arr->size();
    for(int i=0; i < size-1; ++i) {
        for(int j=0; j < size-1-i; ++j) {       // the last element already sorted
            if((*arr)[j] > (*arr)[j + 1]) {     // If the current element is larger than the next one, then they are swapped
                swap((*arr)[j], (*arr)[j+1]);
            }

            // Debug =====================
            cout << "Iteration №" << j + 1 << '\n';
            for(int i=0; i < size; ++i) {
                cout << (*arr)[i] << ' ';
            }
            cout << '\n';
            // ===========================
        }
    }
}

void BubbleSort(int (*arr)[], int size) {
    for(int i=0; i < size-1; ++i) {
        for(int j=0; j < size-1-i; ++j) {       // the last element already sorted
            if((*arr)[j] > (*arr)[j + 1]) {     // If the current element is larger than the next one, then they are swapped
                swap((*arr)[j], (*arr)[j+1]);
            }

            // Debug =====================
            cout << "Iteration №" << j + 1 << '\n';
            for(int i=0; i < size; ++i) {
                cout << (*arr)[i] << ' ';
            }
            cout << '\n';
            // ===========================
        }
    }
}