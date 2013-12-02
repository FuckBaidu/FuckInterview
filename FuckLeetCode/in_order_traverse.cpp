/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 */
#include <vector>
#include <stack>
#include <iostream>
#include "tree.h"

std::vector<int> InOrderTraverse(Node<int> *root) {
    std::vector<int> result;
    std::stack<Node<int>*> stack;
    Node<int> *cur = root;
    while (cur) {
        while (cur) {
            stack.push(cur);
            cur = cur->left;
        }
        do {
            cur = stack.top();
            result.push_back(cur->value);
            stack.pop();
        } while (!cur->right && !stack.empty());
        cur = cur->right;
    }

    return result;
}

void Test(Node<int> *root) {
    std::vector<int> result = InOrderTraverse(root);
    std::cout << "In Order Traverse tree: ";
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
}

int main() {
    srand(time(NULL));
    BinarySearchTree<int> tree;
    for (int i = 0; i < 10; i++)
        tree.Insert(rand() % 20);
    tree.Print();
    Test(tree.GetRoot());
    return 0;
}
