# Queue
A Queue is a FIFO (First In, First Out) data structure. This means that items in a queue are added to the end (the back of the queue) and retrieved from the front (the front of the queue).

An example would be a typical grocery store line: if you are the first to arrive, you are also the first to be served and leave the store (queue).

You can also imagine a car conveyor: the car that is first put on the belt is the first to leave. I hope the principle is clear.

**Used to implement**:

- Waiting processes in operating systems (Scheduling);

- Data processing algorithms where items are processed in the order they are received, such as breadth-first search (BFS);

- Multitasking and multithreading programming. For example, the producer-consumer pattern;

- Data buffering;

- Event handling;

- Network applications (data flow control);

# Explanation
**Methods**:

- enqueue - add an element to the end of the queue
- dequeue - remove an element from the beginning of the queue
- peek - returns the first element without removing
- getSize - returns the size of the queue
- getCapacity - returns the `capacity` value, how many elements in total a particular class object can hold
- getQueue - returns all elements of the queue
- isEmpty - check if the queue is empty
- isFull - whether the queue is full
___

```cpp
class Queue {
private:
    int* data;       // Array for storing elements
    int capacity;    // Queue capacity
    int front;       // Queue start index
    int rear;        // Queue end index
    int size;        // Current size of queue
```
My implementation of the queue is based on an array, not on a linked list, like many others. Here are the pros and cons of this solution:

|Characteristic|Array-based Queue|Linked List-based Queue|
|---|---|---|
|**Performance (insert/delete)**|O(1) (if no reallocation required)|O(1) (if start/end pointers available)|
|**Memory**|Efficient memory usage|Requires extra memory for pointers|
|**Size**|Limited to a pre-defined capacity|Dynamic memory, can grow as needed|
|**Memory Management**|Reallocation issues|Dynamic memory allocation|
|**Flexibility**|Limited flexibility (fixed capacity)|High flexibility (dynamic resizing)|
|**Caching**|Excellent data locality|Poor data locality|
|**Implementation complexity**|Easy|Complex, requires working with pointers|

And yet, the root cause of this decision is that linked lists are inherently more complex than queues. To create a queue based on a linked list **you need to understand the structure of a linked list**, and we haven't even covered the queue. I find this a bit counterintuitive.
___
```cpp
// Add element in queue
void Queue::enqueue(int value) {
    if (isFull()) {
        return;
    }
    rear = (rear + 1) % capacity;
    data[rear] = value;
    ++size;
}
```
`rear + 1` — increases the current index `rear` by 1. This means that we are trying to move to the next cell in the array. `% capacity` is the remainder operator (modulo). It ensures that the index does not go beyond the array's bounds. If `rear + 1` becomes equal to `capacity` (i.e. goes beyond the bounds of the array), then instead of going beyond the bounds of the array, the expression evaluates to 0 (the beginning of the array).

That is, **when the end of the array is reached, the indices will "wrap" back to the beginning**.
### Example:

Suppose `capacity` is 5, and the current index of `rear` is 4. Then:

- Increment `rear` by 1: `rear + 1 = 5`.

- Take the remainder of the division by `capacity` (we get 5 % 5): the result is 0.

So after executing this line, the value of `rear` will be 0, which means that **the next element will be added to the beginning of the array**.

Next, we take the `data` array, find the `rare` index that we just calculated, and assign the value of `value` to this element of the array. ___
```cpp
// Delete element from queue
int Queue::dequeue() {
    if (isEmpty()) {
        throw invalid_argument("The queue is empty!");
    }
    int value = data[front];
    front = (front + 1) % capacity;
    --size;
    return value;
}
```
To be precise, we *don't* delete the element, we just shift the working area with the queue to the right. This is clearly demonstrated in `main.cpp`:

- Initially, the queue looks like this - `[10 20 30 40]`
- Then we delete the first element - `Deleted: 10`
- We print the queue again and see something strange - `[10 20 30 40]`.

Yes, the queue remained untouched, but front moved one position to the right, and we forgot about that.

An even more visual example: `f` - front, `r` - rear

- Initial queue:

```cpp
                                [10 20 30 40]
                                 f        r                               
```

- Delete the first element - `Deleted: 10`
- Received queue:

```cpp
                                [10 20 30 40]
                                    f     r                               
```
___
```cpp
vector<int> Queue::getQueue() const{
    vector<int> returnData = {};
    for (int i = 0; i < capacity; ++i) {
        returnData.push_back(data[i]);
    }
    return returnData;
}
```

As a rule, no one writes such a method, but it seemed useful to me to see the queue in action. Since the pointer to the array `*data` itself cannot be passed from the function, the vector `returnData` is created inside the function, which will store the resulting array before passing. Then, a simple loop from 0 to `capacity` (i.e. up to the value of the queue capacity) iterates through each element of the vector returnData, followed by assigning the corresponding elements from `*data`. 
___
```cpp
// Is the element contained in the queue
bool Queue::contains(int value) const {
    for (int i = 0; i < size; ++i) {
        int index = (front + i) % capacity;
        if (data[index] == value) return true;
    }
    return false;
}
```

We iterate over each element from 0 to `size`. We have already considered the line `int index = (front + i) % capacity;` in the `enqueue` method. Next, a simple check - if the queue element at the current index matches the passed value, then we return `true`, otherwise `false`. We have *O(n)*.