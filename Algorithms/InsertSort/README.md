# Insertion Sort

**Big O** — O(n²) worst-case, O(n) best-case if array is already sorted

Insertion Sort is an algorithm that iterates through an array and gradually increases the sorted portion by inserting the current element into the correct place. The algorithm resembles the process of sorting playing cards in your hand: each new element is inserted into the already sorted portion of the array.
___
### Pros

- Efficient for small arrays.
- Simple to implement.
- Suitable for arrays that are almost sorted (running time is close to O(n)).

### Cons

- Inefficient for large arrays, since its worst-case complexity is O(n²).
- Is unstable in implementations where re-sorting changes the order of identical elements.

# Explanation
```cpp
void InsertSort(std::vector<int> *arr) {
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
```

The algorithm starts from index 1 (`currentIndex = 1`), i.e. from the second element, since the array of length 1 is already sorted.

The current element to be inserted into the sorted part is stored in the `temp` variable (`temp = (*arr)[currentIndex]`).

While the element from the sorted part is **greater** than `temp`, we shift it to the right.

When we find a suitable place, we insert `temp` back into the array.

### Example
Original array:
`[8, 4, 6, 2, 9]`

Algorithm steps:

1. `currentIndex = 1, temp = 4`
    - Sorted part: [8]
        - Compare 8 > 4, shift 8 to the right.
        - Insert 4.
        - Current state: [4, 8, 6, 2, 9].

2. `currentIndex = 2, temp = 6`
    - Sorted part: [4, 8]
        - Compare 8 > 6, shift 8 to the right.
        - Insert 6.
        - Current state: [4, 6, 8, 2, 9].

3. `currentIndex = 3, temp = 2`
    - Sorted part: [4, 6, 8]
        - Compare 8 > 2, shift 8 to the right.
        - Compare 6 > 2, shift 6 to the right.
        - Compare 4 > 2, shift 4 to the right.
        - Insert 2.
        - Current state: [2, 4, 6, 8, 9].

4. `currentIndex = 4, temp = 9`
    - Sorted part: [2, 4, 6, 8]
        - Compare 8 < 9. Element is already in its place.
        - Current state: [2, 4, 6, 8, 9].

Result:

Sorted array:
`[2, 4, 6, 8, 9]`