/*
 * Describe an algorithm to save a Binary Search Tree (BST) to a file in terms
 * of run-time and disk space complexity. You must be able to restore to the
 * exact original BST using the saved format.
 */
#include "tree.h"
int main() {
    std::string rep = "30 20 10 40 35 37 50";
    BinarySearchTree<int> tree(rep);
    tree.Print();
    std::cout << tree.Serialize() << std::endl;
    return 0;
}
