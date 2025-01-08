#include <iostream>
#include <queue>
#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    tree.insert(1, "right");
    tree.insert(2, "left");
    tree.insert(3, "right");
    tree.insert(15, "left left"); //  Element will not add to tree
    tree.insert(7, "left");
    tree.insert(8, "right");
    tree.insert(9, "right");
    
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.BFS();

    return 0;
}
