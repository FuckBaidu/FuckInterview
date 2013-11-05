/**
 * 4.4 in <Crack the code interview>.
 * Given a binary search tree, design an algorithm which creates a linked list
 * of all the nodes at each depth
 */
#include "tree.h"

int main() {
    BinarySearchTree<int> tree;
    tree.Insert(5);
    std::cout << std::endl;
    tree.PrintBySibling();
    tree.Insert(4);
    tree.Insert(3);
    tree.Insert(6);
    std::cout << std::endl;
    tree.PrintBySibling();
    tree.Insert(2);
    tree.Insert(7);
    std::cout << std::endl;
    tree.PrintBySibling();

    return 0;
}
