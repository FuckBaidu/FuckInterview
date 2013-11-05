/**
 * 4.3 in <Crack the code interview>.
 * Given a sorted (increasing order) array, create a binary search tree with minimum height
 */
#include "tree.h"

template <class T>
void InsertMinimumBinarySearchTree(int *array, int low, int high, BinarySearchTree<T> &tree) {
    if (low <= high) {
        int mid = (low + high) / 2;
        tree.Insert(array[mid]);
        InsertMinimumBinarySearchTree(array, low, mid - 1, tree);
        InsertMinimumBinarySearchTree(array, mid + 1, high, tree);
    }
}

void Test(int *array, int len){
    std::cout << "Tree:" << std::endl;
    BinarySearchTree<int> tree;
    InsertMinimumBinarySearchTree(array, 0, len - 1, tree);
    tree.Print();
}

int main() {
    int a1[] = {1, 2, 3, 4, 5, 6};
    Test(a1, 6);
    int a2[] = {1, 2, 3, 4, 5, 6, 7};
    Test(a2, 7);
    return 0;
}
