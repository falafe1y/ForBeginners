#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);

    std::cout << "List contents: ";
    list.print();

    std::cout << "List size: " << list.get_size() << '\n';

    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();

    list.clear();
    std::cout << "After clear: ";
    list.print();

    return 0;
}
