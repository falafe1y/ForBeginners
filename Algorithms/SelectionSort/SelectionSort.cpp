#include "SelectioSort.h"
#include <iostream>

using namespace std;

void SelectionSort(vector<int> *arr) {
    for (int first = 0; first < arr->size()-1; ++first) {
        int min = first;
        for (int currentElmnt = first+1; currentElmnt < arr->size(); ++currentElmnt)
        if ((*arr)[currentElmnt] < (*arr)[min]) {       // if the current element is less than the minimum, then minimum = current element
            min = currentElmnt;
        }
        swap((*arr)[min], (*arr)[first]);       // the first element in this iteration is swapped with the minimum               

        // Debug =====================
        cout << "Iteration №" << first+1 << '\n';
        for (int i = 0; i < arr->size(); ++i) {
            cout << (*arr)[i] << ' ';
        }
        cout << '\n';
        // Debug =====================
    }
}

void SelectionSort(int (*arr)[], int size) {
    for (int first = 0; first < size-1; ++first) {
        int min = first;
        for (int currentElmnt = first+1; currentElmnt < size; ++currentElmnt)
        if ((*arr)[currentElmnt] < (*arr)[min]) {       // if the current element is less than the minimum, then minimum = current element
            min = currentElmnt;
        }
        swap((*arr)[min], (*arr)[first]);       // the first element in this iteration is swapped with the minimum               

        // Debug =====================
        cout << "Iteration №" << first+1 << '\n';
        for (int i = 0; i < size; ++i) {
            cout << (*arr)[i] << ' ';
        }
        cout << '\n';
        // Debug =====================
    }
}