# Radix Sort
- [ ] Done?
## Theory
**Big O** — O(n * k), where `n` is the number of elements, `k` is the number of digits in the maximum number

**Radix Sort** is an algorithm that sorts numbers starting from the least significant digits (units) and ending with the most significant digits (tens, hundreds, etc.). For each iteration, an auxiliary sort by the current digit is used (for example, Counting Sort).

The algorithm is stable, since it preserves the order of identical numbers from the original array.

### Pros

- Linear running time for a limited range
- If the numbers have a limited length (number of digits), the algorithm works in O(n⋅k)O(n⋅k), where nn is the array size, and kk is the number of digits. This is faster than O(nlog⁡n)O(nlogn) of algorithms like Merge Sort or Quick Sort for large nn.

- No recursion
- The algorithm is easy to implement since it does not use recursive calls (unlike Quick Sort and Merge Sort).

- Sort stability
- Radix Sort preserves the order of elements with the same values. This is useful for problems where elements have additional keys besides numbers.

- No complex operations
- The algorithm relies only on digit partitioning and counting sorting, which makes it understandable and predictable.

### Cons

- Dependence on the range of values
- If the numbers have a large number of digits (for example, 20-digit numbers), the algorithm becomes less efficient as the number of iterations increases. However, if the digit values ​​are unevenly distributed, counting may become inefficient.
- Data type limitations
- The algorithm works best for integers. For real numbers or strings, its implementation becomes more complex.
- Memory overhead
- An additional array is created for each digit, which increases the memory requirements. This can be a problem for large arrays.
- Not applicable to all data types
- Radix Sort is difficult to use for sorting complex objects where the order is determined by more than just numbers.
- Inefficient for small arrays
- For small arrays, n⋅kn⋅k can be larger than nlog⁡nnlogn, due to overhead.
# Explanation

## Explanation
```cpp
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
```
**countingSortByDigit function (counting sort auxiliary function):**

Extracts the current digit of the number (`digit=(arr[i]/exp)%10digit=(arr[i]/exp)%10`). Then counts how many times each possible digit (0…9) occurs in the array, storing this data in the `count` array, and then transforms the `count` array so that it contains the indices where the elements should be in the sorted array. Then sorts the elements by the current digit, starting from the end of the array to maintain sort stability. Finally, copies the sorted array back to the original array.

**radixSort function:**

Finds the maximum number in the array to determine the number of digits to sort, then calls `countingSortByDigit` for each digit of the number in turn (1 - units, 10 - tens, 100 - hundreds, etc.). As a result, the array is sorted in ascending order.

### Example

Initial array:
`[329, 457, 657, 839, 436, 720, 355]`

1. Step 1: Sort by ones (`exp = 1`)

    - Extract the last digits: [9, 7, 7, 9, 6, 0, 5]
    - Sort by these digits: [720, 355, 436, 657, 329, 839, 457]

    Array after the first iteration:
    [720, 355, 436, 657, 329, 839, 457]
2. Step 2: Sort by tens (`exp = 10`)

    - Extract the tens digits: [2, 5, 3, 5, 2, 3, 5]
    - Sort by these digits: [720, 329, 839, 436, 355, 457, 657]

    The array after the second iteration:
    [720, 329, 839, 436, 355, 457, 657]
3. Step 3: Sort by hundreds (`exp = 100`)

    - Extract the hundreds digits: [7, 3, 8, 4, 3, 4, 6]
    - Sort by these digits: [329, 355, 436, 457, 657, 720, 839]

    The array after the third iteration:
    [329, 355, 436, 457, 657, 720, 839]

Result:

Sorted array:
`[329, 355, 436, 457, 657, 720, 839]`