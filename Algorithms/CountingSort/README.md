# Counting Sort
**Big O** — O(n + k)

The **counting sort** algorithm works by counting the number of occurrences of each unique element in the array. To do this, an auxiliary array is created in which the index corresponds to the element from the original array, and the value at this index is the number of occurrences of this element. The elements of the original array are then restored in sorted order using this auxiliary array. The running time of the algorithm depends on the size of the array and the value of the maximum element (k), which makes it linear for a limited range of values.
___
### Pros

- Works quickly for a limited range of element values.
- The algorithm has linear complexity O(n + k), which makes it efficient for large data sets with small values.
- Does not require additional memory for recursion, as, for example, in merge algorithms.

### Cons
- Doesn't work with data containing negative numbers or floating point values ​​(although it can be adapted for these cases).
- Requires a significant amount of additional memory to store counters, especially for large element values.
- Not suitable for general cases where elements have a wide range of values.

# Explanation
```cpp
void CountingSort(std::vector<int> *arr) {
    if (arr->empty()) return;
    int maxElement = *max_element(arr->begin(), arr->end());

    // Create a vector of size maxElement + 1, 
    // where all elements are 0
    std::vector<int> count(maxElement + 1, 0);

    for (int num : *arr) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        std::cout << "Itteration №" << i+1 << ": ";
        while (count[i] > 0) {
            (*arr)[index++] = i;
            count[i]--;
        }
    }
}
```
Checking if an array is empty `(if (arr->empty()) return;)` — if the array is empty, the function will terminate immediately, since there is nothing to sort.

Finding the maximum element of an array `(int maxElement = *max_element(arr->begin(), arr->end());)` — to determine the size of the auxiliary array count, we need to find the maximum element in the original array, since the range of values ​​that we need to consider is limited by this element.

Creating an array to count the frequency of elements `(std::vector<int> count(maxElement + 1, 0);)` — an auxiliary array count is created, in which each index corresponds to an element from the arr array, and the value at this index is the number of occurrences of this element in the array.

Counting the frequency of each element `(for (int num : *arr) { count[num]++; })` — each element of the arr array increments the corresponding index in the count array, thus creating a frequency distribution of elements.

Restoring a sorted array `(for (int i = 0; i <= maxElement; ++i) {...})` — starting from index zero, we go through the count array and restore the elements of the original array, filling them in ascending order. For each index value (which is an element of the `arr` array), we add it to the final array as many times as it occurs (as per the value in `count[i]`).
___
### Example
Suppose we have an array:
`[5, 2, 9, 1, 5, 6]`

1. Step 1: Find the maximum element

    The maximum element of the array = 9.

2. Step 2: Create the counting array

    The counting array:
    [0, 1, 1, 0, 0, 2, 1, 0, 0, 1]

    - Index 0: 0 elements.
    - Index 1: 1 element (1 occurs 1 time).
    - Index 2: 1 element (2 occurs 1 time).
    - Index 5: 2 elements (5 occurs 2 times).
    - Index 6: 1 element (6 occurs 1 time).
    - Index 9: 1 element (9 occurs 1 time).

3. Step 3: Restore the sorted array

    1. First iteration (i = 0): the array is not changed, since there are no zeros in the array.
    2. Second iteration (i = 1): insert 1 → [1, 2, 9, 1, 5, 6]
    3. Third iteration (i = 2): insert 2 → [1, 2, 9, 1, 5, 6]
    4. Fourth iteration (i = 5): insert 5 twice → [1, 2, 5, 5, 6, 9]
    5. Fifth iteration (i = 6): insert 6 → [1, 2, 5, 5, 6, 9]
    6. Sixth iteration (i = 9): insert 9 → [1, 2, 5, 5, 6, 9]

Result:

Sorted array: `[1, 2, 5, 5, 6, 9]`