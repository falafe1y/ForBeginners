#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template <typename K, typename V>
class HashTable {
private:
    std::vector<std::list<std::pair<K, V>>> table; // Таблица хеширования
    size_t table_size; // Размер таблицы

    // Хеш-функция
    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % table_size;
    }

public:
    // Конструктор
    HashTable(size_t size = 16) : table_size(size), table(size) {}

    // Вставка элемента
    void insert(const K& key, const V& value) {
        size_t index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Если ключ уже существует, обновляем значение
                return;
            }
        }
        table[index].emplace_back(key, value); // Вставляем пару в список
    }

    // Поиск элемента
    bool search(const K& key, V& value) const {
        size_t index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true; // Если нашли, возвращаем значение
            }
        }
        return false; // Если не нашли
    }

    // Удаление элемента
    bool remove(const K& key) {
        size_t index = hash(key);
        auto& list = table[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                list.erase(it); // Удаляем пару
                return true;
            }
        }
        return false; // Если не нашли
    }

    // Печать хеш-таблицы
    void print() const {
        for (size_t i = 0; i < table_size; ++i) {
            std::cout << "Index " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    // Возвращает размер таблицы
    size_t size() const {
        return table_size;
    }
};
