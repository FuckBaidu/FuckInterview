/*
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 * Return 6.
 */

#include "tree.h"
int MaxPathSum(Node<int> *node, int &max_root) {
    int max_left_path = INT_MIN, max_right_path = INT_MIN,
        max_left = INT_MIN, max_right = INT_MIN;
    if (node->left)
        max_left_path = MaxPathSum(node->left, max_left);
    if (node->right)
        max_right_path = MaxPathSum(node->right, max_right);
    if (max_left <= 0 && max_right <= 0)
        max_root = node->value;
    else
        max_root = node->value + std::max(max_left, max_right);
    int max_path = node->value;
    if (max_left > 0)
        max_path += max_left;
    if (max_right > 0)
        max_path += max_right;
    max_path = std::max(max_path, max_left_path);
    max_path = std::max(max_path, max_right_path);
    return max_path;
}

int MaxPathSum(Node<int> *root) {
    if (!root)
        return 0;
    int max_root = INT_MIN;
    return MaxPathSum(root, max_root);
}

int main() {
    std::string tests[] = {"1 2 3", "-1 2 1 $ $ 3 $ $ 3 $ $", "-1 2 1 $ $ 3 $ $ -2 $ $"};
    int results[] = {6, 7, 6};
    for (int i = 0; i < 3; i++) {
        BinaryTree<int> tree(tests[i]);
        assert(MaxPathSum(tree.GetRoot()) == results[i]);
    }
    return 0;
}
