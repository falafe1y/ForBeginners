#include <algorithm>
#include <cmath>
#include "RadixSort.h"

// Auxiliary sorting

// exp is a variable used in Radix sort to determine the current digit to sort by.
// It denotes the "multiplier" to extract a specific digit of a number.
void countingSortByDigit(std::vector<int>& arr, int exp) {

    if (arr.empty()) return;

    int arr_size = arr.size();
    std::vector<int> sorted(arr_size); // Array for sorted elements
    int count[10] = {0};       // Array for values form 0 to 9

    // Count the number of elements for each value of the current digit
    for (int i = 0; i < arr_size; i++) {
        int digit = (arr[i] / exp) % 10; // Extract the current digit
        count[digit]++;
    }

    // Modify count[i] so that it contains the index to place the number
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Sort by current rank (go from the end for stability)
    for (int i = arr_size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        sorted[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // copy sorted array back to source
    for (int i = 0; i < arr_size; i++) {
        arr[i] = sorted[i];
    }
}

// Main Radix sort function
void radixSort(std::vector<int>& arr) {
    // Find the maximum number to determine the number of digits
    int maxVal = *std::max_element(arr.begin(), arr.end());

    // Sort by each digit, starting with ones
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}