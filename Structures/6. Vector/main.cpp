#include <iostream>
#include "Vector.h"

int main() {
    Vector<int> vec;

    // Adding elements
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Checking sizes
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    // Removing the last element
    vec.pop_back();
    std::cout << "After pop_back: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Clearing the vector
    vec.clear();
    std::cout << "Size after clear: " << vec.size() << std::endl;

    return 0;
}
