/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */
#define private public
#define protected public
#include "tree.h"
#include <vector>
Node<int> *SortedArrayToBST(const std::vector<int> &num, int begin, int end) {
    if (begin > end)
        return NULL;
    int mid = (begin + end) / 2;
    Node<int> *node = new Node<int>(num[mid]);
    node->left = SortedArrayToBST(num, begin, mid - 1);
    node->right = SortedArrayToBST(num, mid + 1, end);
    return node;
}

Node<int> *SortedArrayToBST(std::vector<int> &num) {
    int begin = 0, end = (int)num.size() - 1;
    return SortedArrayToBST(num, begin, end);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> A(a, a + 6), B(b, b + 7);
    BinarySearchTree<int> tree;
    tree._root = SortedArrayToBST(A);
    tree.Print();
    tree._root = SortedArrayToBST(B);
    tree.Print();
    return 0;
}
