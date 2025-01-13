# Stack
- [ ] Done?
## Theory
**Stack** is a basic data structure that works on the LIFO (Last In, First Out) principle, meaning that the last element added will be the first to be removed.

An example would be a stack of washed plates. It is not possible to take a plate from the middle or the very bottom. You can only take the one on top. The plate that is currently on top was the last to be added, and the plate at the very bottom was the first.

You can also think of a stack as a deck of cards - the principle is the same, the analogy is not so important.

A stack implementation should include several basic operations:

- Push: Add an element to the top of the stack.
- Pop: Remove an element from the top of the stack.
- Peek (or Top): Get the value of the top element of the stack without removing it.
- IsEmpty: Check if the stack is empty.
- Size: Get the number of elements in the stack.

**Used to implement**:
- Recursion: to store the context of function calls.
- Rollbacks: for example, to implement the undo function in applications.
- Function call handling: when programs are executed, the stack manages function calls and their parameters, which allows you to organize the execution and return to previous functions.

# Explanation
**Methods**:
- push - add an element to the top of the stack
- pop - remove an element from the top of the stack
- top - return an element from the top of the stack (the second implementation is a method that works with and returns a constant)
- isEmtpy - return a `bool` indicating whether the stack is currently empty
- getSize - return the current size (number of elements) in the stack.
___
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
std::cout << "A new node has been created!\n";
}
};

Node* topNode;
size_t size;
```

`template<typename T>` is used when it is not known in advance what type of data we will be working with. The stack must be able to store different data types - int, string, float, boolean, as well as our own types, so we use templates.

By the way, if you don't know the difference between `class` and `struct` - it is only in the default access modifier:

- class uses private unless otherwise specified;
- struct uses public unless otherwise specified.

`Node* next;` points to the previous top of the stack. The `nextNode` argument passed to the constructor is a pointer to the current top of the stack (before adding the new node).
___

```cpp
Stack() : topNode(nullptr), size(0) {}

~Stack() {
while (!isEmpty()) {
pop();
}
}
```
Constructor and destructor. Constructor can be replaced with...
```cpp
// Stack() {
// topNode = nullptr;
// size = 0;
// }
```
___
```cpp
void pop() {
if (isEmpty()) {
throw std::underflow_error("Stack is empty!");
}
Node* temp = topNode;
topNode = topNode->next;
delete temp;
--size;
}
```
Method for removing the top of the stack. The line `Node* temp = topNode;` creates a temporary node pointing to the current top of the stack (`topnode`). This step is necessary to save a reference to the current node before deleting it. Next, we update the current node to the previous one `topNode = topNode->next;`, so now `topNode` points to the second from the top element in the stack. Then we delete the temporary node and decrease `size` by 1.
### Example:
Stack [5, 4, 3, 2, 1]
- `Node* temp = topNode;`
    - Create a temporary node `temp'. It now points to 5.
- `topNode = topNode->next;`
    - `topNode`, which before this step pointed to 5, now points to 4.
- `delete temp;`
    - Free the memory area occupied by `temp`. Now there's nothing there, and since it was pointing to 5, there's no longer 5, and `topNode` now points to the correct top of the stack.