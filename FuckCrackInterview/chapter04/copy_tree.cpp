/**
 * 13.8 in <Crack the code interview>.
 * Copy a binary tree
 */

#include "tree.h"

int main() {
    BinarySearchTree<int> tree;
    BinarySearchTree<int> new_tree;
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(7);
    std::cout << "old tree:" << std::endl;
    tree.Print();
    new_tree.Insert(4);
    new_tree.Insert(3);
    new_tree.Insert(6);
    std::cout << "new tree:" << std::endl;
    new_tree.Print();
    std::cout << std::endl;
    new_tree = tree;
    std::cout << "new tree:" << std::endl;
    new_tree.Print();
    tree.Insert(2);
    new_tree.Insert(7);
    std::cout << "old tree:" << std::endl;
    tree.Print();
    std::cout << "new tree:" << std::endl;
    new_tree.Print();

    return 0;
}
