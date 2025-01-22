#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template <typename K, typename V>
class HashTable {
private:
    std::vector<std::list<std::pair<K, V>>> table;
    size_t table_size;

    // hash-function
    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % table_size;
    }

public:
    HashTable(size_t size = 16) : table_size(size), table(size) {}

    void insert(const K& key, const V& value) {
        size_t index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    // search of the element
    bool search(const K& key, V& value) const {
        size_t index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    bool remove(const K& key) {
        size_t index = hash(key);
        auto& list = table[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                list.erase(it); // Remove pair
                return true;
            }
        }
        return false;
    }

    void print() const {
        for (size_t i = 0; i < table_size; ++i) {
            std::cout << "Index " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    size_t size() const {
        return table_size;
    }
};
