/**
 * 4.5 in <Crack the code interview> 5th edition.
 * Implement a method to check if a binary tree is a binary search tree
 */
#include "tree.h"
bool IsBinarySearchTree(const Node<int> *node, int &pre_value) {
    if (!node)
        return true;
    if (!IsBinarySearchTree(node->left, pre_value))
        return false;
    if (pre_value > node->value)
        return false;
    pre_value = node->value;
    return IsBinarySearchTree(node->right, pre_value);
}

bool IsBinarySearchTree(const Node<int> *root) {
    int pre_value = INT_MIN;
    return IsBinarySearchTree(root, pre_value);
}

template <class T>
void InsertMinimumBinarySearchTree(int *array, int low, int high, BinarySearchTree<T> &tree) {
    if (low <= high) {
        int mid = (low + high) / 2;
        tree.Insert(array[mid]);
        InsertMinimumBinarySearchTree(array, low, mid - 1, tree);
        InsertMinimumBinarySearchTree(array, mid + 1, high, tree);
    }
}

int main() {
    int array[15];
    for (int i = 0; i < 15; i++)
        array[i] = i + 1;
    BinarySearchTree<int> tree;
    InsertMinimumBinarySearchTree(array, 0, 14, tree);
    tree.Print();
    std::cout << "Tree above is a binary search tree? "
        << IsBinarySearchTree(tree.GetRoot()) << std::endl;
    tree.GetRoot()->right->value = 10;
    tree.Print();
    std::cout << "Tree above is a binary search tree? "
        << IsBinarySearchTree(tree.GetRoot()) << std::endl;
}
