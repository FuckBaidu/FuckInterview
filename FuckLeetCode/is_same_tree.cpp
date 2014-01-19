/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the
 * same value.
 */
#include "tree.h"
#include <assert.h>

bool IsSameTree(Node<int> *p, Node<int> *q) {
    if (!p && !q) {
        return true;
    } else if (p && q) {
        if (p->value != q->value)
            return false;
        return IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
    } else {
        return false;
    }
}

int main() {
    BinaryTree<int> a1("1 3 $ 9 $ $ 20 5 $ $ 7 $ $");
    BinaryTree<int> a2("1 3 $ 9 $ $ 20 5 $ $ 7 $ $");
    BinaryTree<int> a3("1 3 $ 9 $ $ 20 5 9 $ $ $ 7 $ $");
    assert(IsSameTree(a1.GetRoot(), a2.GetRoot()));
    assert(!IsSameTree(a1.GetRoot(), a3.GetRoot()));
    return 0;
}
