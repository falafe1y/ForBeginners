#include <iostream>
#include "HashTable.h"

int main() {
    // 
    HashTable<std::string, int> hashTable;

    // Add elements
    hashTable.insert("apple", 5);
    hashTable.insert("banana", 3);
    hashTable.insert("orange", 7);
    hashTable.insert("pear", 2);

    // Print hash-table
    std::cout << "Hash table contents:" << std::endl;
    hashTable.print();

    // Search elements
    int value;
    if (hashTable.search("banana", value)) {
        std::cout << "Found banana, value: " << value << std::endl;
    } else {
        std::cout << "banana not found." << std::endl;
    }

    // Remove elements
    if (hashTable.remove("apple")) {
        std::cout << "apple removed." << std::endl;
    } else {
        std::cout << "apple not found for removal." << std::endl;
    }

    // Print hash-table after remove
    std::cout << "Hash table after removal:" << std::endl;
    hashTable.print();

    return 0;
}
