# Vector
- [ ] Done?
## Theory
Vector is a container that represents a dynamic array. It allows you to store and manage elements. The access speed to elements is *O(1)*, since the data is in a continuous memory area. The implementation of the vector should imply automatic memory allocation for new data, as well as clearing the memory of deleted objects, so as not to create leaks.

**Used to implement**:

- Vector graphics
- Calculations for mathematics and physics
- Gaming industry (optimization)
- Machine learning

# Explanation
**Methods**:
- push_back - add an element to the end of the vector
- pop_back - remove the last element
- size - return the size of the vector (how many elements are currently in the vector)
- capacity - return the capacity of the vector
- clear - clear the contents of the vector
___
```cpp
T& operator[](size_t index) {
    if (index >= vec_size) {
        throw std::out_of_range("Index out of range.");
    }
    return data[index];
}

const T& operator[](size_t index) const {
    if (index >= vec_size) {
        throw std::out_of_range("Index out of range.");
    }
    return data[index];
}
```
These are two overloaded `[]` operators that allow accessing the elements of a vector via their indices.
___
```cpp
// Increases the array capacity
void resizeCapacity(size_t new_capacity) {
    T* new_data = new T[new_capacity]; // New array
    for (size_t i = 0; i < vec_size; ++i) {
        new_data[i] = data[i]; // Copy old data
    }
    delete[] data; // Free the old memory
    data = new_data; // Pointer to the new array
    vec_capacity = new_capacity;
}
```
A private method that changes the current size of a vector.

First, we create a new dynamic array of the size of `new_capacity` that was passed as an argument. Next, in the loop from 0 to the vector size, we compile each element from the existing dynamic array into the newly created one, without violating the relative order.

There is also a method for expanding a vector without copying data, but more on that later.
___
```cpp
// Adds an element to the end
void push_back(const T& value) {
    if (vec_size == vec_capacity) {
        size_t new_capacity = (vec_capacity == 0) ? 1 : vec_capacity * 2;
        resizeCapacity(new_capacity);
    }
    data[vec_size++] = value;
}
```
We pass a value of type `T`, i.e. a template, any. We check if the vector size matches its capacity value. If so, then the vector is full and its size needs to be updated.

We check if the vector is empty. If yes, its size will be 1, if no, then we multiply the current size by 2. Next, we allocate new memory equal to `new_capacity` and assign our value `value` to the element that is greater than the current vector size by 1.

I will explain the last line in more detail. The current size = 10 and the capacity is also 10. We double the capacity and create memory for it. Now the size = 10, and the capacity = 20. Now we access the element at index 10++, i.e. 11. The value passed to `push_back` will be stored there.

P.s. the line `size_t new_capacity = (vec_capacity == 0) ? 1 : vec_capacity * 2;` works according to the formula `condition ? do_if_true : do_if_false;`
___
```cpp
// Removes the last element
void pop_back() {
    if (vec_size > 0) {
        --vec_size;
    } else {
        throw std::underflow_error("Vector is empty, cannot pop_back.");
    }
}
```
It's simple here - if the vector size is not 0, then we simply decrease it by one. Everything outside the boundaries of the dynamic array, which is the basis of the vector, will be automatically deleted. Otherwise, we throw an exception.