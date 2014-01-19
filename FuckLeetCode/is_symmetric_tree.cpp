/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

   For example, this binary tree is symmetric:
   
       1
      / \
     2   2
    / \ / \
   3  4 4  3
   But the following is not:
       1
      / \
     2   2
      \   \
      3    3
   Note:
   Bonus points if you could solve it both recursively and iteratively.
 */
#include "tree.h"
#include <stack>
#include <assert.h>

bool IsSymmetric(Node<int> *node1, Node<int> *node2) {
    if (!node1 && !node2) {
        return true;
    } else if (node1 && node2) {
        if (node1->value != node2->value)
            return false;
        return IsSymmetric(node1->left, node2->right) && IsSymmetric(node1->right, node2->left);
    } else {
        return false;
    }
}

bool IsSymmetric1(Node<int> *root) {
    if (!root)
        return true;
    return IsSymmetric(root->left, root->right);
}

bool IsSymmetric(Node<int> *root) {
    if (!root)
        return true;
    std::stack<Node<int>*> s1, s2;
    s1.push(root->left);
    s2.push(root->right);
    while (!s1.empty() && !s2.empty()) {
        Node<int> *node1 = s1.top(), *node2 = s2.top();
        s1.pop();
        s2.pop();
        if (!node1 && !node2)
            continue;
        if (!node1 && node2 || node1 && !node2)
            return false;
        if (node1->value != node2->value)
            return false;
        s1.push(node1->right);
        s1.push(node1->left);
        s2.push(node2->left);
        s2.push(node2->right);   
    }
    return true;
}

int main() {
    BinaryTree<int> tree1("1 2 3 $ $ 4 $ $ 2 4 $ $ 3 $ $");
    assert(IsSymmetric(tree1.GetRoot()));

    BinaryTree<int> tree2("1 2 $ 3 $ $ 2 $ 3 $ $");
    assert(!IsSymmetric(tree2.GetRoot()));
    return 0;
}
