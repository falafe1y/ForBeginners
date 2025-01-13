#include <iostream>
#include <stdexcept>
#include "Stack.h"

int main() {
    try {
        Stack<int> stack;

        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "Top element: " << stack.top() << std::endl;
        std::cout << "Stack size: " << stack.getSize() << std::endl;

        stack.pop();
        std::cout << "Top element after pop: " << stack.top() << std::endl;
        std::cout << "Stack size after pop: " << stack.getSize() << std::endl;

        stack.pop();
        stack.pop();

        stack.pop();    // Error
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
