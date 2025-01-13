#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;            // Pointer to the array
    size_t vec_size;    // Current size of the vector
    size_t vec_capacity; // Current capacity of the vector

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

public:
    // Constructor
    Vector() : data(nullptr), vec_size(0), vec_capacity(0) {}

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Adds an element to the end
    void push_back(const T& value) {
        if (vec_size == vec_capacity) {
            size_t new_capacity = (vec_capacity == 0) ? 1 : vec_capacity * 2;
            resizeCapacity(new_capacity);
        }
        data[vec_size++] = value;
    }

    // Removes the last element
    void pop_back() {
        if (vec_size > 0) {
            --vec_size;
        } else {
            throw std::underflow_error("Vector is empty, cannot pop_back.");
        }
    }

    // Access by index
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

    // Returns the current size
    size_t size() const {
        return vec_size;
    }

    // Returns the current capacity
    size_t capacity() const {
        return vec_capacity;
    }

    // Clears the vector
    void clear() {
        vec_size = 0;
    }
};
