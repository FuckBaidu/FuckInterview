/**
 * 4.1 in <Crack the code interview>.
 * Implement a function to check if a tree is balanced
 */
#include "tree.h"
#include <algorithm>

template <class T>
int GetBalancedTreeHeight(Node<T> *root) {
    if (!root)
        return -1;
    int left_height = 0, right_height = 0;
    if (root->left)
        left_height = GetBalancedTreeHeight(root->left);
    if (root->right)
        right_height = GetBalancedTreeHeight(root->right);
    if (left_height == -1 || right_height == -1)
        return -1;
    if (left_height != 0 && right_height != 0) {
        int diff = left_height - right_height;
        if (abs(diff) > 1)
            return -1;
    }
    return std::max(left_height, right_height) + 1;
}

template <class T>
int MaxDepth(Node<T> *root) {
    if (!root)
        return 0;
    return std::max(MaxDepth(root->left), MaxDepth(root->right)) + 1;
}

template <class T>
int MinDepth(Node<T> *root) {
    if (!root)
        return 0;
    int left_depth = MinDepth(root->left);
    int right_depth = MinDepth(root->right);
    if (left_depth != 0 && right_depth != 0)
        return std::min(left_depth, right_depth) + 1;
    else
        return left_depth + right_depth + 1;

}

template <class T>
bool IsBalanced(Node<T> *root) {
    return (MaxDepth(root) - MinDepth(root) <= 1);
}

void Test(BinarySearchTree<int> &tree) {
    tree.Print();
    if (GetBalancedTreeHeight(tree.GetRoot()) == -1)
        printf("Not balanced\n");
    else
        printf("Balanced\n");
}

void Test1(BinarySearchTree<int> &tree) {
    tree.Print();
    if (!IsBalanced(tree.GetRoot()))
        printf("Not balanced\n");
    else
        printf("Balanced\n");
}

int main() {
    BinarySearchTree<int> tree;
    tree.Insert(5);
    Test(tree);
    Test1(tree);
    tree.Insert(4);
    tree.Insert(3);
    tree.Insert(6);
    Test(tree);
    Test1(tree);
    tree.Insert(2);
    Test(tree);
    Test1(tree);
    tree.Insert(7);
    Test(tree);
    Test1(tree);
    tree.PrintByLevel();
    return 0;
}
