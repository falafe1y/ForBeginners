# Stack
- [ ] Been finished?
## Theory
**A stack** is a basic data structure that works on the LIFO (Last In, First Out) principle, meaning that the last element added will be the first to be removed.

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
- Rollbacks: for example, to implement the function of undoing actions in applications.
- Handling function calls: when executing programs, the stack manages function calls and their parameters, which allows you to organize the execution and return to previous functions.

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
            std::cout << "Создан новый узел!\n";
        }
    };

    Node* topNode;
    size_t size;
```

`template<typename T>` используется, когда заранее неизвестно, с каким типом данных предстоит работать. Стек должен уметь хранить разные типы данных — int, string, float, boolean, а также собственные типы, поэтому мы используем шаблоны.

Кстати, если вы не знаете разницу между `class` и `struct` — она только в модификаторе доступа по умолчанию:

- class использует private, если не указано иное;
- struct использует public, если не указано иное.

`Node* next;` указывает на предыдущую вершину стека. Аргумент `nextNode`, переданный в конструктор, является указателем на текущую вершину стека (до добавления нового узла).
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

