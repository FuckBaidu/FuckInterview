/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */
#define private public
#define protected public
#include "tree.h"
#include <ext/hash_map>

typedef __gnu_cxx::hash_map<int, int> HashMap;

Node<int> *BuildTree(const std::vector<int> &preorder, int preorder_begin, int inorder_begin,
                    int size, HashMap &inorder) {
    if (size == 0)
        return NULL;
    int cur = preorder[preorder_begin], inorder_index = inorder[cur];
    Node<int> *node = new Node<int>(cur);
    int left_size = inorder_index - inorder_begin, right_size = size - left_size - 1;
    node->left = BuildTree(preorder, preorder_begin + 1, inorder_begin, left_size, inorder);
    node->right = BuildTree(preorder, preorder_begin + left_size + 1, inorder_index + 1, right_size, inorder);
    return node;
}

Node<int> *BuildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
        return NULL;
    HashMap inorder_index;
    for (int i = 0; i < inorder.size(); i++)
        inorder_index[inorder[i]] = i;
    return BuildTree(preorder, 0, 0, preorder.size(), inorder_index);
}

int main() {
    int p[] = {1, 9, 3, 20, 5, 7};
    int i[] = {9, 3, 1, 5, 20, 7};
    std::vector<int> preorder(p, p + 6);
    std::vector<int> inorder(i, i + 6);
    Node<int> *root = BuildTree(preorder, inorder);
    BinarySearchTree<int> tree;
    tree._root = root;
    tree.Print();
}
