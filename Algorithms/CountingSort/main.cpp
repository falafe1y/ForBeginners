#include <iostream>
#include <vector>
#include "CountingSort.h"

int main() {
    std::vector<int> arr = {8, 4, 0, 3, 7};

    std::cout << "Source array:";

    for (int i : arr) {
        std::cout << ' ' << i;
    }

    std::cout << "\n\n";

    CountingSort(&arr);

    std::cout << "\nCounting sort: ";
    for (int j : arr) {
        std::cout << j << ' ';
    }

    return 0;
}