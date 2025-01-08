# Radix sort
- [ ] Been finished?
## Theory
**Big O** — *O(d⋅(n+k))*, where:

- d is the number of digits in the longest number.
- n is the number of elements in the array.
- k is the range of results (0–9 for decimal numbers).

**Space complexity** — *O(n+k)* due to the use of an additional output array and array counter.

Radix sort works well for large arrays of numbers, especially if there are few digits. It is limited to data types that can be broken down into digits (numbers, fixed-length strings).

**Radix sort** is a linear sorting algorithm that operates on numbers by sorting their **digits by place value**. It is used for fixed-length numbers or strings. The algorithm uses an auxiliary sort (often counting), starting with the least significant digit (LSD).
___

### Auxiliary sorting
**Counting sort** is often used for sorting by numbers because it is efficient for a fixed range of values ​​(0-9 for numbers). 

## Explanation



How does exp work?

When sorting with Radix, numbers are processed by digits: starting with units, then tens, hundreds, and so on.

To extract a digit from a specific digit of a number, we use the formula:

`digit of the current digit = (number / exp) % 10`

For example, if we have the number 123, then: 
- For units (exp = 1): (123 / 1) % 10 = 3
- For tens (exp = 10): (123 / 10) % 10 = 2
- For hundreds (exp = 100): (123 / 100) % 10 = 1