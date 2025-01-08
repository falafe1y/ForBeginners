# Counting sort
- [ ] Been finished?
## Theory
**Big O** — O(n * k)

Counting sort works best under the following conditions:

- The array is very large — there are many values;
- The values ​​are in a range that we know (for example, the operating range of a sensor);
- The range is much smaller than the array size, meaning that data units may be repeated.

In short, **counting sort** is used for small integers, it is an algorithm with complexity O(n + k) as the worst case, where 'n' is the number of elements and k is the largest number among all elements.
The algorithm works by counting, rather than comparing, the elements.

## Explanation
`if (arr->empty()) return;` If array is empty we exit from function

`std::vector<int> count(maxElement + 1, 0);` Create a vector of size maxElement + 1, where all elements are 0
```
for (int num : *arr) {
        count[num]++;
    }
```
Calculate the frequency of occurrence of each element

`int index = 0;` Variable that will track the current position in the arr array, where we will write the sorted elements

```
for (int i = 0; i <= maxElement; ++i) {
    std::cout << "Itteration №" << i+1 << ": ";
    while (count[i] > 0) {
        (*arr)[index++] = i;
        count[i]--;
    }
    for (int num : *arr) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}
```
Overwrite the original array taking into account the count
