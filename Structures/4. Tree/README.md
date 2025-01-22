# Binare tree

Why **binary** tree? A node in such a tree can only have **two** children - a left and a right.

**Used to implement**:
- Searching and sorting
- Data structure storage
- Expression representation
- Computer graphics
- Database management systems
- Data compression, such as ZIP and JPEG
- Games and AI

Tree can be represented something like this:

                                            1
                                           / \
                                          2   3
                                         / \   \
                                        7   8   9

# Explanation

Here, **private** methods will be discussed. There is no point in a detailed explanation of public methods because they serve as regular **interfaces**.

```cpp
class BinaryTree {
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };
```

This is a nested structure of a node. We have already seen this language mechanism in the implementation of a **stack**.

```cpp
Node* root;

    void insertPrivate(Node* node, int value, const std::string& direction) {
        if (direction == "left") {
            if (node->left == nullptr) {
                node->left = new Node(value);
            } else {
                insertPrivate(node->left, value, direction);
            }
        } else if (direction == "right") {
            if (node->right == nullptr) {
                node->right = new Node(value);
            } else {
                insertPrivate(node->right, value, direction);
            }
        } else {
            return;
        }
    }
```

A pointer to the root - the very first - node of the tree and a method for adding new nodes. My variation of this method takes a direction of type `string`. If we pass `left`, it creates a left child from the root node with the value `value`. The same happens for `right` if the corresponding direction is passed. If the user makes a mistake and passes a different string instead of a direction, the method simply skips such an addition.

Next in the code are 3 methods for traversing the tree of type `DFS` and one of type `BFS`. Information about them is written below.

After that, there is a method for cleaning up memory from the tree data. It is called in the **destructor**.

# Tree Traversal
For example, let's take the following tree:

                                            A
                                           / \
                                          B   C
                                         / \   \
                                        D   E   F

## DFS
### Inorder (symmetrical) bypass
Traversal order: Left subnode → Root → Right subnode

Steps:
- Start at the root (A).
- Go to the left subtree (B).
- Go to the left subtree (D). Print D.
- Return to B. Print B.
- Go to the right subtree (E). Print E.
- Return to A. Print A.
- Go to the right subtree (C).
- Go to the right subtree (F). Print F.

Result: D, B, E, A, C, F

### Preorder (direct) traversal

Traversal order: Root → Left subnode → Right subnode

Steps:

- Start at the root (A). Print A.
- Go to the left subtree (B). Print B.
- Go to the left subtree (D). Print D.
- Go back to B and go to the right subtree (E). Print E.
- Go back to A and go to the right subtree (C). Print C.
- Go to the right subtree (F). Print F.

Result: A, B, D, E, C, F

### Postorder (reversed) bypass

Traversal order: Left subnode → Right subnode → Root

Steps:

- Start at the root (A) and go to the left subtree (B).
- Go to the left subtree (D). Print D.
- Return to B and go to the right subtree (E). Print E.
- Return to B. Print B.
- Return to A and go to the right subtree (C). Print C.
- Go to the right subtree (F). Print F.
- Return to C. Print C.
- Return to A. Print A.

Result: D, E, B, F, C, A

## BFS (breadth first search)

                                            A
                                           / \
                                          B   C
                                         / \   \
                                        D   E   F

Traversal order: First visit the root, then all nodes on the first level, then the second level, and so on.

Steps:
- Start with the root (A) and put it on the queue.
- Pop A from the queue and print it.
- Add all children of A (B and C) to the queue.
- Pop B from the queue and print it.
- Add all children of B (D and E) to the queue.
- Pop C from the queue and print it.
- Add C's child (F) to the queue.
- Pop D from the queue and print it. (D has no children)
- Pop E from the queue and print it. (E has no children)
- Pop F from the queue and print it. (F has no children)

Result: A, B, C, D, E, F