# Selection sort
- [ ] Done?
## Theory
**Big O** — execution time O(n2), memory O(1)

What is the idea of ​​selection sort?

- A local maximum (minimum) is searched for in an unsorted subarray.
- The maximum (minimum) found is swapped with the last (first) element in the subarray.
- If there are unsorted subarrays left in the array — see point 1.

An interesting feature of selection sort is that its speed is independent of the nature of the data being sorted.

For example, if the array is almost sorted, then, as is known, insertion sort will process it much faster (even faster than quicksort). And a reverse-ordered array for insertion sort is a degenerate case, it will sort it for the longest possible time.

And for selection sort, partial or reverse ordering of the array does not matter - it will process it at about the same speed as regular random. Also, for classic selection sort, it does not matter whether the array consists of unique or repeating elements - this has practically no effect on speed.

### Pros

- Easy to implement.
- Does not require additional memory.

### Cons

- Inefficient for large arrays, since its complexity in the worst case is O(n2)O(n2).
- It is not stable (it can break the order of identical elements).

# Explanation
```cpp
void SelectionSort(vector<int> *arr) {
    for (int first = 0; first < arr->size()-1; ++first) {
        int min = first;
        for (int currentElmnt = first+1; currentElmnt < arr->size(); ++currentElmnt)
        if ((*arr)[currentElmnt] < (*arr)[min]) {       // if the current element is less than the minimum, then minimum = current element
            min = currentElmnt;
        }
        swap((*arr)[min], (*arr)[first]);       // the first element in this iteration is swapped with the minimum               
    }
}
```

### Example

Source array:
`[29, 10, 14, 37, 13]`

1. Iteration 1:
    - Look at the array [29, 10, 14, 37, 13].
    - Minimum element is 10.
    - Swap 29 and 10.
    - Result: [10, 29, 14, 37, 13].

2. Iteration 2:
    - Look at the array [29, 14, 37, 13].
    - Minimum element is 13.
    - Swap 29 and 13.
    - Result: [10, 13, 14, 37, 29].

3. Iteration 3:
    - Look at the array [14, 37, 29].
    - Minimum element is 14 (it is already in place).
    - Result: [10, 13, 14, 37, 29].

4. Iteration 4:
    - Look at the array [37, 29].
    - Minimum element is 29.
    - Swap 37 and 29.
    - Result: [10, 13, 14, 29, 37].

Sorted array:
`[10, 13, 14, 29, 37]`