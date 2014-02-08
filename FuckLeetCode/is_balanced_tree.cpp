#include "tree.h"

bool IsBalanced(Node<int> *node, int &height) {
    int left_height = 0, right_height = 0;
    if (node->left && !IsBalanced(node->left, left_height))
        return false;
    if (node->right && !IsBalanced(node->right, right_height))
        return false;
    if (std::abs(left_height - right_height) > 1)
        return false;
    height = std::max(left_height, right_height) + 1;
    return true;
}

bool IsBalanced(Node<int> *root) {
    if (!root)
        return true;
    int height;
    return IsBalanced(root, height);
}

void Test(BinarySearchTree<int> &tree) {
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
    tree.Insert(4);
    tree.Insert(3);
    tree.Insert(6);
    Test(tree);
    tree.Insert(2);
    Test(tree);
    tree.Insert(7);
    Test(tree);
    return 0;
}
