# Stack
## Theory
A **stack** is a basic data structure that operates on the LIFO (Last In, First Out) principle, meaning that the last element added will be the first one removed.

As an example, you can imagine a stack of washed dishes. You cannot take a dish from the middle or from the very bottom. You can only take a dish from the top. In turn, the dish that is currently on the top ended up there most recently. The dish that is at the very bottom came to the stack first.

You can also think of a stack like a deck of cards — the principle is the same, and the analogy is not important.

A stack implementation must contain several basic operations:

- Push: Add an element to the top of the stack.
- Pop: Remove an element from the top of the stack.
- Peek (or Top): Get the value of the top element of the stack without removing it.
- IsEmpty: Check if the stack is empty.
- Size: Get the number of elements in the stack.

**Used to implement**:
- Recursion: to store the context of function calls.
- Writeback: for example, to implement undo in applications.
- Handling function call: when programs are executed, the stack manages function calls and their parameters, which allows you to organize the execution and return to previous functions.

# Explanation
```cpp
template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T &value, Node* nextNode = nullptr) {
            data = value;
            next = nextNode;
            std::cout << "New node created!\n";
        }
    };

    Node* topNode;
    size_t size;
```

`template<typename T>` is used when we don't know what type of data we will be working with. A stack have to store different types of data - int, string, float, boolean, and maybe even **our own types**, so we can use templates.

By the way, if you don't know the difference between `class` and `struct` - it's only in the **default access modifier**:
- `class` uses **private** unless explicitly stated otherwise;
- `struct` uses **public** instead.

`Node* next;` points to the previous top of the stack. The argument `nextNode` passed to the constructor is a pointer to the current top of the stack (before adding the new node).
___

```cpp
Stack() : topNode(nullptr), size(0) {}

~Stack() {
    while (!isEmpty()) {
        pop();
    }
}
```
Constructor and destructor. The constructor can be replaced with...
```cpp
// Stack() {
//     topNode = nullptr;
//     size = 0;
// }
```
A one-line constructor makes sense if you are simply assigning some values to objects. If your constructor involves calculations and other more complex logic, then this option will not work.
___

