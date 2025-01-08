# Heap
- [ ] Been finished?
## Theory

There are two types of heaps - **maximum** and **minimum**
Различия:

|**Characteristic**|**Max-Heap**|**Min-Heap**|
|---|---|---|
|**Property**|Parent ≥ Children|Parent ≤ Children|
| **Top of Heap** | Maximum Element | Minimum Element |
| **Use** | Priority Queues, Finding the Maximum | Priority Queues, Finding the Minimum |
| **Add and Remove Operations** | Provides Finding the Maximum | Provides Finding the Minimum |

### **Used to implement**:

|**Applications**|**Max-Heap**|**Min-Heap**|
|---|---|---|
|Priority Queues|Highest Priority|Lowest Priority|
|Graph Algorithms|Kruskal, Prim|Dijkstra, Prim|
|Sorting|Descending Order|Ascending Order|
|Select *K* best/worst items|*K* largest items|*K* smallest items|
|Streaming Data|Maximum Value in Stream|Minimum Value in Stream|

# Differences between a heap and a tree
A tree and a heap are data structures that are often confused due to their similarity, but they have fundamental differences. Let's analyze them by key parameters:

- **Tree** is a merarchical structure, where each node can have an arbitrary number of descendants.

    - Its nodes can be placed at any level, without strict rules for filling.
    - It is used to represent relations, where nodes are connected according to their hierarchy (for example, a file system).

- **Heap** is a special case of a tree, and a strictly binary tree at that.

    - A heap is filled from left to right, level by level. The last level may be incomplete, but its elements are strictly on the left.
    - It is designed to work efficiently with minimum or maximum elements.
    - Extracting the minimum (or maximum) element takes constant time.


|**Operation**|**Tree (BST)**|**Heap**|
|---|---|---|
|**Finding an element**|*O(log⁡N)* (in a B-tree)|*O(N)*|
|**Adding an element**|*O(log⁡N)*|*O(logN)*|
|**Removing an element**|*O(log⁡N)*|*O(logN)* (removing the root)|
|**Accessing the root**|*O(log⁡N)* (may not be the largest/smallest)|*O(1)* (root is min/max)|


If you imagine a pile as a tree, it might look like this:

                                            1
                                           / \
                                          2   3
                                         / \   \
                                        4   5   6

Interestingly, traversing such a heap will be identical to traversing a binary tree using the BFS method.

# Explanation
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
`while (index > 0)` loop continues until the current node reaches the root or its position (index = 0).

`int parent = (index - 1) / 2;` in this line we find the parent using the formula *(index - 1) / 2*. For the node with index = 5: `parent = (5 - 1) / 2 = 2`.

```cpp
if (heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
```
If the current node is larger than its parent, we swap them and set `index` to `parent`. The same is true for the **minimal** heap, but the sign is changed to the **opposite**:
```cpp
if (heap[index] < heap[parent])
```
In fact, the only difference between these two classes is in this line and a similar one in the `heapifyDown` method.
### Example
Initial heap: [50, 30, 20, 15, 10, 8, 5]

Add element 40. Now the heap is: [50, 30, 20, 15, 10, 8, 5, 40].
The heapifyUp method has started working:

1. index=7, parent: (7−1)/2=3. Compare 40 and 15:
40 > 15, swap them.
Array: [50, 30, 20, 40, 10, 8, 5, 15].
index = 3.

2. index=3, parent: (3−1)/2=1. Compare 40 and 30:
40 > 30, swap them.
Array: [50, 40, 20, 30, 10, 8, 5, 15].
index = 1.

3. index=1, parent: (1−1)/2=0. Compare 40 and 50:
40 ≤ 50, loop ends.

Resulting heap: [50, 40, 20, 30, 10, 8, 5, 15]

### Is the resulting heap valid?
Yes, because a heap is an **unordered** array in the general sense. Its validity is determined by two rules:
- **Max/Min Heap Property**:

    In a max heap, the value of any node must be greater than or equal to the value of its children (if any).

    In a min heap, the value of any node must be less than or equal to the value of its children.

- **Complete Property:**

    The heap must be a complete binary tree, filling levels from left to right without gaps.
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
is used to restore the MaxHeap property when a node is moved down the tree. This may be needed, for example, after extracting the maximum element from the root (extractMax), when the last element replaces the root, but may violate the heap property.

Next, the indices of the left `(2 * index + 1)` and right `(2 * index + 2)` descendants are calculated.

Next, we look for the largest node. At the very beginning, we take the current node as the largest. Then we look to see if the left or right descendant of our largest node is larger. If one of the conditions is true, we set the largest node to the one we just found.

```cpp
if (largest != index) {
    std::swap(heap[index], heap[largest]);
    index = largest;
}
```

The condition checks if the index of the largest node has changed.
At the start of the iteration, it is assumed that the current node (index) is the largest.
However, if the left or right child is larger than the current node, then the largest variable is updated (in the code above).

If largest != index, it means that the current node has a child that is larger than it. In this case, you need to fix the situation to restore the MaxHeap property.



### Example
Let's say we have a heap like this: [5, 10, 20, 30, 15, 8, 40]

This is not a valid MaxHeap, since the root 5 is smaller than the children. We need to restore the heap property using `heapifyDown(0)`.

1.  index = 0, heap[0] = 5.

    Left child: heap[1] = 10, right child: heap[2] = 20.

    Largest node: heap[2] = 20.

    Swap: std::swap(heap[0], heap[2]).

    Heap: [20, 10, 5, 30, 15, 8, 40].

    New index = 2.

2.  index = 2, heap[2] = 5.

    Left child: heap[5] = 8, right child: heap[6] = 40.

    Largest node: heap[6] = 40.

    Swap: std::swap(heap[2], heap[6]).

    Heap: [20, 10, 40, 30, 15, 8, 5].

    New index = 6.

3.  index = 6, heap[6] = 5.

    No children, since left = 13, right = 14 are beyond the array size.

    End the loop.

    Final heap: [20, 10, 40, 30, 15, 8, 5]