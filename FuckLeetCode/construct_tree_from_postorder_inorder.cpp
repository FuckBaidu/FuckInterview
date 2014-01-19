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

Node<int> *BuildTree(const std::vector<int> &postorder, int postorder_end, int inorder_begin,
                    int size, HashMap &inorder) {
    if (size == 0)
        return NULL;
    int cur = postorder[postorder_end], inorder_index = inorder[cur];
    Node<int> *node = new Node<int>(cur);
    int left_size = inorder_index - inorder_begin, right_size = size - left_size - 1;
    node->left = BuildTree(postorder, postorder_end - right_size - 1, inorder_begin, left_size, inorder);
    node->right = BuildTree(postorder, postorder_end - 1, inorder_index + 1, right_size, inorder);
    return node;
}

Node<int> *BuildTree(std::vector<int> &postorder, std::vector<int> &inorder) {
    if (postorder.empty() || inorder.empty())
        return NULL;
    HashMap inorder_index;
    for (int i = 0; i < inorder.size(); i++)
        inorder_index[inorder[i]] = i;
    return BuildTree(postorder, postorder.size() - 1, 0, postorder.size(), inorder_index);
}

int main() {
    int p[] = {3, 9, 5, 7, 20, 1};
    int i[] = {9, 3, 1, 5, 20, 7};
    std::vector<int> postorder(p, p + 6);
    std::vector<int> inorder(i, i + 6);
    Node<int> *root = BuildTree(postorder, inorder);
    BinarySearchTree<int> tree;
    tree._root = root;
    tree.Print();
}
