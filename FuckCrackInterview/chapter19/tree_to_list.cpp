/**
 * 17.13 in <Crack the code interview> 5th edition.
 * Convert a binary seach tree into a double linked list.The values should be
 * kept in order, and the operation should be performed in place
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

Node<int> *AppendList(Node<int> *node, Node<int> *cur_tail) {
    if (node->left)
        cur_tail = AppendList(node->left, cur_tail);
    node->left = cur_tail;
    if (cur_tail)
        cur_tail->right = node;
    cur_tail = node;
    if (node->right)
        cur_tail = AppendList(node->right, cur_tail);
    return cur_tail;
}

void Test(int *array, int len){
    std::cout << "Tree:" << std::endl;
    BinarySearchTree<int> tree;
    InsertMinimumBinarySearchTree(array, 0, len - 1, tree);
    tree.Print();
    Node<int> *tail = AppendList(tree.GetRoot(), NULL);
    std::cout << "List:";
    while (tail) {
        std::cout << tail->value << " ";
        tail = tail->left;
    }
    std::cout << std::endl;
}

int main() {
    int a[15];
    for (int i = 0; i < 15; i++)
        a[i] = i;
    Test(a, 15);
    return 0;
}
