# Linked list
A linked list is a data structure consisting of nodes, where each node contains **data** and **a pointer to the next node** (or several pointers in the case of a doubly linked list). In memory, such a structure is stored randomly. A linked list does not require nodes to be in adjacent memory cells. This has both pros and cons.

There are 3 types of linked lists:
- Singly linked list - each node stores **a pointer only to the next node**, navigation is possible **only in one direction**.
- Doubly linked list - each node contains **two pointers**: to the next node and to the previous one. Navigation is possible in both directions.
- Circular list - **the last node in the list points to the first**, forming a ring. Can be either singly linked or doubly linked.

### **Pros and Cons of Using a Linked List**:
|**Advantages**|**Disadvantages**|
|---|---|
|Adding or removing an element at the beginning of a list takes **O(1)**.| To get an element by index, you need to sequentially traverse the list from the beginning to the desired node O(n).|
|Elements are added and removed without the need to reallocate memory..| Extra memory is spent on storing pointers.|

### **Where is it used?**:
- Processing buffers
- Message queues
- STL C++ in `std::list`
- Crafting system in games
- Blockchain
- Skip List
- Ring buffers
- Linked trees:
- Text editor management (representation of text lines, simplified work with it)
- Memory allocators (e.g. malloc in C)
- Graphs
- In operating systems:
    - File Descriptor Table: Files opened by processes can be stored in a linked list.
    - Task management: Singly or doubly linked lists are used to implement task queues.

# Explanation
**Methods**:
- push_front — adds an element to the beginning of the list.
- push_back — adds an element to the end of the list.
- pop_front — removes the first element from the list.
- clear — removes all elements from the list, freeing up memory.
- print — prints the contents of the list to the console.
- get_size — returns the number of elements in the list.
- is_empty — checks if the list is empty.
___
```cpp
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

Node* head; // Pointer to begin of list
size_t size; // Size of list
```
`Node` is a private substructure of the `LinkedList` class that implements a node in a linked list.
___
```cpp
void push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}
```
It's easier to explain with an example.

P.s. important clarification so that no one gets confused: a linked list is read from left to right, so the "head" is the leftmost element.

### Example

Suppose we have a list:
```
    10 -> 20 -> 30
    |
   HEAD
```
and we add a new element 5 using `push_front(5)`.
We create a new node `newNode` with data 5. It is not linked to any other nodes yet.

Now we do this:
```cpp
newNode->next = head;   // Новый элемент теперь указывает на старую голову (на 10)
```

This links the new element to the current first element of the list.

Next, we update head to point to the new element:
```
head = newNode; // Голова теперь указывает на новый элемент (на 5)
```
Now the list structure will be:
```
    5 -> 10 -> 20 -> 30
    |
   HEAD
```
___
```cpp
void push_back(const T& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}   
```
This method adds an element to the **end** of the linked list, i.e. as **right** as possible. If the `push_front` method added an element as **left** as possible, then this one works **the other way around**.

So, we create `newNode`, check if the linked list is empty (`if (!head)`). If it is empty, then the newly created node becomes the head. If the list is **not empty**, then:
- We start at the head of the list (`temp = head`).
- Then in the while (`temp->next`) loop, we go through the list until we find the last element. The last element's `next` field will be `nullptr`.
- When the loop ends, `temp` points to the last element of the list.
- We add the new element to the end of the list, setting the last element of `temp->next` to point to the new node `newNode`.

Then we increase the size of the linked list.
### Example
Suppose we have an empty list, and we add some elements.

1. - First call to `push_back(10)`:
        - A new node newNode is created with data 10.
        - The list is empty, so head will point to the new node.
        - The list is now:

    `10 -> nullptr`

2. - Second call to `push_back(20)`:

        - A new node newNode is created with data 20.
        - The list is not empty, so we start at the head of the list.
        - We see that the next element at head is nullptr, so it is the last element.
        - Set temp->next = newNode to point to the new node as the last element.
        - The list is now:

    `10 -> 20 -> nullptr`

3. - Third call to `push_back(30)`:

        - A new node newNode is created with the data 30.
        - Again, we walk the list starting from the head and find the last element (20).
        - Set temp->next = newNode to point to the new node as the last element.
        - The list is now:

    `10 -> 20 -> 30 -> nullptr`
___
```cpp
void pop_front() {
    if (!head) return;

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}
```
Method for removing the leftmost element, i.e. the *head*. We check if `head` exists. If not, we return nothing. Otherwise, we create a temporary node `temp` pointing to the current head. Then we reassign the head pointer from the very first to the next - second - element of the list.

### Example

We have the following list:
```cpp
    1 -> 2 -> 3 -> nullptr
    |
   HEAD
```
There is a head, so we will not proceed to creating a dummy node. The lines
```cpp
Node* temp = head;
head = head->next;
```
Thus, we have
```cpp
*1* -> 2 -> 3 -> nullptr
       |
      HEAD 
```
The dummy node is shown here as `*1*`. Now we delete the dummy node so that it doesn't take up memory space and reduce the size of the list:
```cpp
delete temp;
size--;
```
Thus, we have effectively deleted the head, which was current before calling this method.
___
```cpp
void clear() {
    while (head) {
        pop_front();
    }
}
```
While the head exists, we call the `pop_front` method.

### Example
List:
```cpp
    1 -> 2 -> 3 -> nullptr
    |
   HEAD
```

The deleted elements will be in square brackets `[]`.

1. First call. Head - `1`
    ```cpp
    [1] -> 2 -> 3 -> nullptr
           |
          HEAD
    ```

2. Second call. Head - `2`
    ```cpp
    [1] -> [2] -> 3 -> nullptr
                  |
                 HEAD
    ```

3. Third call. Head - `3`
    ```cpp
    [1] -> [2] -> [3] -> nullptr
                            |
                           HEAD
    ```

Now the head is nullptr, which means the linked list is empty.