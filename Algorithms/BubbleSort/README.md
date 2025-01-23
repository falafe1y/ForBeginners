# Bubble Sort
**Big O** — O(n²)

The **bubble sort** algorithm works by repeatedly going through an array and comparing adjacent elements. If the elements are out of order, they are swapped. The process is repeated until the array is sorted. In the worst and average cases, the algorithm has quadratic complexity of O(n²), which makes it inefficient for large data sets. However, for small arrays or already partially sorted data, bubble sort can work quite well.
___
### Pros

- Simple and intuitive algorithm.
- Easy to implement.
- Can be useful for learning the basics of sorting.

### Cons

- Has quadratic complexity (O(n²)), which makes it **inefficient for large data sets**.
- **Not stable** in the case of an array with identical elements (although it can be made stable with some improvements).
- Takes a long time to run for large amounts of data compared to other sorting algorithms such as *quick* or *merge*.
___
# Explanation
```cpp
void BubbleSort(vector<int> *arr) {
    int size = arr->size();
    for(int i = 0; i < size - 1; ++i) {
        for(int j = 0; j < size - 1 - i; ++j) {       // the last element already sorted
            if((*arr)[j] > (*arr)[j + 1]) {     // If the current element is larger than the next one, then they are swapped
                swap((*arr)[j], (*arr)[j + 1]);
            }
        }
    }
}
```
The first loop `(for(int i = 0; i < size - 1; ++i))` is responsible for passing through the array. We will make several passes, and each pass will sort one element, starting from the end, since after each pass the last element will be in its place.

The second loop `(for(int j = 0; j < size - 1 - i; ++j))` - this loop compares and swaps adjacent elements of the array. The number of comparisons decreases on each pass, because the elements at the end are already sorted.

The condition `if((*arr)[j] > (*arr)[j + 1])` - if the current element is greater than the next, then they are swapped using `swap((*arr)[j], (*arr)[j + 1])`.

### Example
Suppose we have an array:
`[5, 2, 9, 1, 5, 6]`

1. Pass 1:

    - Compare 5 and 2: 5 > 2, swap → [2, 5, 9, 1, 5, 6]
    - Compare 5 and 9: 5 < 9, leave as is → [2, 5, 9, 1, 5, 6]
    - Compare 9 and 1: 9 > 1, swap → [2, 5, 1, 9, 5, 6]
    - Compare 9 and 5: 9 > 5, swap → [2, 5, 1, 5, 9, 6]
    - Compare 9 and 6: 9 > 6, swap → [2, 5, 1, 5, 6, 9]

After the first pass, the last element (9) is in place.

2. Pass 2:

    - Compare 2 and 5: 2 < 5, leave as is → [2, 5, 1, 5, 6, 9]
    - Compare 5 and 1: 5 > 1, swap → [2, 1, 5, 5, 6, 9]
    - Compare 5 and 5: 5 = 5, leave as is → [2, 1, 5, 5, 6, 9]
    - Compare 5 and 6: 5 < 6, leave as is → [2, 1, 5, 5, 6, 9]

After the second pass, element 6 is in place.

3. Pass 3:

    - Compare 2 and 1: 2 > 1, swap → [1, 2, 5, 5, 6, 9]
    - Compare 2 and 5: 2 < 5, leave as is → [1, 2, 5, 5, 6, 9]
    - Compare 5 and 5: 5 = 5, leave as is → [1, 2, 5, 5, 6, 9]

Sorted array: `[1, 2, 5, 5, 6, 9]`