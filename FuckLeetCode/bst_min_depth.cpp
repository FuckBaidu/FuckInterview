/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root
 * node down to the nearest leaf node.
 */
#include "tree.h"
int MinDepth(Node<int> *root) {
    if (!root)
        return 0;
    if (!root)
        return 0;
    if (root->left || root->right) {
        int left_depth = INT_MAX, right_depth = INT_MAX;
        if (root->left)
            left_depth = MinDepth(root->left);
        if (root->right)
            right_depth = MinDepth(root->right);
        return std::min(left_depth, right_depth) + 1;
    } else {
        return 1;
    }
}

int main() {
    BinaryTree<int> tree("1 2 3 $ $ $ 4 $ $");
    assert(MinDepth(tree.GetRoot()) == 2);
    return 0;
}
