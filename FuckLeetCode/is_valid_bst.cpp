/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 */
#include <assert.h>
#include <stack>
#include "tree.h"
bool IsValidBST(Node<int> *root) {
    std::stack<Node<int>*> stack;
    Node<int> *cur = root, *prev = NULL;
    while (cur) {
        while (cur) {
            stack.push(cur);
            cur = cur->left;
        }
        do {
            cur = stack.top();
            stack.pop();
            if (prev && prev->value >= cur->value)
                return false;
            prev = cur;
        } while (!stack.empty() && !cur->right);
        cur = cur->right;
    }
    return true;
}

int main() {
    BinaryTree<int> tree1("2 1 $ $ 3 $ $");
    assert(IsValidBST(tree1.GetRoot()));
    BinaryTree<int> tree2("1 2 $ $ 3 $ $");
    assert(!IsValidBST(tree2.GetRoot()));
    return 0;
}
