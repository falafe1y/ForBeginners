# Heap
- [ ] Done?
## Theory

There are two types of heaps - **max-heap** and **min-heap**
Differences:

|**Characteristic**|**Max-heap**|**Min-heap**|
|---|---|---|
|**Property**|Parent ≥ Children|Parent ≤ Children|
| **Top of heap** | Maximum element | Minimum element |
| **Usage** | Priority queues, max-finding | Priority queues, min-finding |
| **Add and remove operations** | Provides max-finding | Provides min-finding |

### **Used to implement**:

|**Applications**|**Max-heap**|**Min-heap**|
|---|---|---|
|Priority Queues|Highest Priority|Lowest Priority|
|Graph Algorithms|Kruskal, Prim|Dijkstra, Prim|
|Sorting|Descending|Ascending|
|Select *K* best/worst items|*K* largest items|*K* smallest items|
|Streaming Data|Maximum Value in Stream|Minimum Value in Stream|

## Differences Between Heap and Tree
Tree and heap are data structures that are often confused due to their similarities, but they have fundamental differences. Let's analyze them by key parameters:

- **Tree** is a hierarchical structure in which each node can have an arbitrary number of children.

- Its nodes can be placed at any level, with no strict rules for filling.
- It is used to represent relationships in which nodes are related according to their hierarchy (e.g. file system).

- **Heap** is a special case of a tree, and a strictly binary tree at that.

- A heap is filled from left to right, level by level. The last level may be incomplete, but its elements are strictly on the left.
- It is designed to work efficiently with minimum or maximum elements.
- Extracting the minimum (or maximum) element takes constant time.

|**Operation**|**Tree (BST)**|**Heap**|
|---|---|---|
|**Finding an element**|*O(log⁡N)* (in a B-tree)|*O(N)*|
|**Adding an element**|*O(log⁡N)*|*O(logN)*|
|**Removing an element**|*O(log⁡N)*|*O(logN)* (deleting the root)|
|**Root access**|*O(log⁡N)* (may not be the largest/smallest)|*O(1)* (root is min/max)|

If you imagine a heap as a tree, it might look like this:

1
/ \
2 3
/ \ \
4 5 6

Interestingly, traversing such a heap will be identical to traversing a binary tree using the BFS method.

# Explanation
**Methods**:
- heapifyUp -
- heapifyDown -
- insert - add a new element to the heap and restore its property
- extractMax - remove and return the maximum element from the heap (the root of the tree), then restore the heap property.
- getMax - return the maximum element (the root of the tree) without removing it.
- printHeap - print heap to terminal
___
```cpp
void MaxHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}
```
`while (index > 0)` loop continues until current node reaches root or its position (index = 0).

`int parent = (index - 1) / 2;` in this line we find parent using formula *(index - 1) / 2*. For node with index = 5: `parent = (5 - 1) / 2 = 2`.

```cpp
if (heap[index] > heap[parent]) {
std::swap(heap[index], heap[parent]);
index = parent;
}
```
If the current node is greater than its parent, we swap them and set `index` to `parent`. The same is true for the **min** heap, but the sign is reversed:
```cpp
if (heap[index] < heap[parent])
```
In fact, the only difference between the two classes is this line and a similar one in the `heapifyDown` method.
### Example
Initial heap: [50, 30, 20, 15, 10, 8, 5]

Add element 40. Now the heap is: [50, 30, 20, 15, 10, 8, 5, 40].
The heapifyUp method has started working:

1. index=7, parent: (7−1)/2=3. Compare 40 and 15:
40 > 15, swap them.
Array: [50, 30, 20, 40, 10, 8, 5, 15].
index = 3.

2. index = 3, parent: (3−1)/2=1. Compare 40 and 30:
40 > 30, swap them.
Array: [50, 40, 20, 30, 10, 8, 5, 15].
index = 1.

3. index = 1, parent: (1−1)/2=0. Compare 40 and 50:
40 ≤ 50, loop ends.

Resulting heap: [50, 40, 20, 30, 10, 8, 5, 15]

### Is the resulting heap valid?
Yes, because a heap is an **unordered** array in the general sense. Its validity is determined by two rules:
- **Max/Min Heap** Property:

In a max heap, the value of any node must be greater than or equal to the value of its children (if any).

In a min heap, the value of any node must be less than or equal to the value of its children.

- **Complete Property:**

The heap must be a complete binary tree, filling levels from left to right without spaces.
___
```cpp
void MaxHeap::heapifyDown(int index) {
    int size = heap.size();
    while (index < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}
```
used to restore the MaxHeap property when moving a node down the tree. This may be needed, for example, after extracting the maximum element from the root (extractMax), when the last element replaces the root, but may violate the heap property.

Next, the indices of the left `(2 * index + 1)` and right `(2 * index + 2)` children are calculated.

Next, we look for the largest node. At the very beginning, we take the current node as the largest. Then we look if the left or right child of our largest node is larger. If one of the conditions is true, we set the largest node to the one we just found.

```cpp
if (largest != index) {
    std::swap(heap[index], heap[largest]);
    index = largest;
}
```

The condition checks if the index of the largest node has changed.
At the beginning of the iteration, the current node (index) is assumed to be the largest.
However, if the left or right child node is larger than the current node, then the largest variable (in the code above) is updated.

If largest != index, it means that the current node has a child node that is larger than it. In this case, you need to fix the situation to restore the MaxHeap property.

### Example
Let's say we have a heap like this: [5, 10, 20, 30, 15, 8, 40]

This is an invalid MaxHeap, since the root 5 is smaller than the children. We need to restore the heap property using `heapifyDown(0)`.

1. index = 0, heap[0] = 5.

Left child: heap[1] = 10, right child: heap[2] = 20.

Biggest node: heap[2] = 20.

Swap: std::swap(heap[0], heap[2]).

Heap: [20, 10, 5, 30, 15, 8, 40].

New index = 2.

2. index = 2, heap[2] = 5.

Left child: heap[5] = 8, right child: heap[6] = 40.

Biggest node: heap[6] = 40.

Swap: std::swap(heap[2], heap[6]).

Heap: [20, 10, 40, 30, 15, 8, 5].

New index = 6.

3. index = 6, heap[6] = 5.

No children, because left = 13, right = 14 are beyond the array size.

End the loop.

Final heap: [20, 10, 40, 30, 15, 8, 5]
___
```cpp
void MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}
```
The new element is added to the end of the heap (to the bottom right position of the tree). Then "sifting up" is performed:
- Compare the new element with its parent.
- If the new element is larger than the parent, they are swapped.
- Repeat until the heap property is restored (or until we reach the root).

### Example
Let the heap initially be represented by an array: `[50, 30, 20, 15, 10, 8, 16]`.

Add the value 60:

- After `push_back`: `[50, 30, 20, 15, 10, 8, 16, 60]`.
- HeapifyUp:
- 60 > 15, swap: `[50, 30, 20, 60, 10, 8, 16, 15]`.
- 60 > 30, swap: `[50, 60, 20, 30, 10, 8, 16, 15]`. - 60 > 50, swap: `[60, 50, 20, 30, 10, 8, 16, 15]`.

Final heap: `[60, 50, 20, 30, 10, 8, 16, 15]`.

For the minimum heap, everything is the same, but the "sifting" will be downwards.
___
```cpp
int MaxHeap::extractMax() {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return maxValue;
}
```
We check if the heap is empty. If so, we say so.

Otherwise, keep the maximum (root) element of the heap, move the last element to the root, and delete the last element. Then sift down (`heapifyDown`)

### Example

Heap: `[60, 50, 20, 30, 10, 8, 16, 15]`.

- Keep 60.
- Move 15 to the root: `[15, 50, 20, 30, 10, 8, 16]`.
- "Sifting down":
- 15 < 50, swap: `[50, 15, 20, 30, 10, 8, 16]`.
- 15 < 30, swap: `[50, 30, 20, 15, 10, 8, 16]`.

Result: `[50, 30, 20, 15, 10, 8, 16]`. Return value: 60.