#include <iostream>
#include "HashTable.h"

int main() {
    // Создаем хеш-таблицу для хранения пар "ключ-значение"
    HashTable<std::string, int> hashTable;

    // Вставляем элементы
    hashTable.insert("apple", 5);
    hashTable.insert("banana", 3);
    hashTable.insert("orange", 7);
    hashTable.insert("pear", 2);

    // Печатаем хеш-таблицу
    std::cout << "Hash table contents:" << std::endl;
    hashTable.print();

    // Ищем элементы
    int value;
    if (hashTable.search("banana", value)) {
        std::cout << "Found banana, value: " << value << std::endl;
    } else {
        std::cout << "banana not found." << std::endl;
    }

    // Удаляем элемент
    if (hashTable.remove("apple")) {
        std::cout << "apple removed." << std::endl;
    } else {
        std::cout << "apple not found for removal." << std::endl;
    }

    // Печатаем хеш-таблицу после удаления
    std::cout << "Hash table after removal:" << std::endl;
    hashTable.print();

    return 0;
}
