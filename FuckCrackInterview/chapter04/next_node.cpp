/**
 * 4.5 in <Crack the code interview>.
 * write an algorithm to find the next node(in-order successor) of a given node
 * in a binary search tree where each node has a link to its parent.
 */
#include "tree.h"

template <class T>
Node<T>* Successor(Node<T>* node) {
    if (node == NULL)
      return NULL;
    Node<T> *cur;
    if (node->right) {
        cur = node->right;
        while (cur->left)
          cur = cur->left;
    } else {
        cur = node->parent;
        while (cur->parent && cur->parent->left == cur)
            cur = cur->parent;
    }

    return cur;
}

void Test() {
    BinarySearchTree<int> tree;
    tree.Insert(5);
    tree.Insert(4);
    tree.Insert(3);
    tree.Insert(7);
    tree.Print();
    std::cout << std::endl;
    Node<int> *cur = tree.Search(3);
    Node<int> *succ = Successor(cur);
    std::cout <<"The successor of " << cur->value << "is " << succ->value  << std::endl;
    tree.Insert(6);
    tree.Print();
    std::cout << std::endl;
    cur = tree.Search(5);
    succ = Successor(cur);
    std::cout <<"The successor of " << cur->value << "is " << succ->value  << std::endl;
}

int main() {
    Test();
    return 0;
}
