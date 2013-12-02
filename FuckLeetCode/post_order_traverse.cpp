/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 */
#include <vector>
#include <stack>
#include <iostream>
#include "tree.h"

std::vector<int> PostOrderTraverse(Node<int> *root) {
    std::vector<int> result;
    Node<int> *prev = NULL;
    std::stack<Node<int>*> stack;
    stack.push(root);
    while (!stack.empty()) {
        Node<int> *cur = stack.top();
        if (!prev || cur == prev->left || cur == prev->right) {
            if (cur->left) {
                stack.push(cur->left);
            } else if (cur->right) {
                stack.push(cur->right);
            } else {
                result.push_back(cur->value);
                stack.pop();
            }
        } else {
            if (prev == cur->left) {
                if (cur->right) {
                    stack.push(cur->right);
                } else {
                    result.push_back(cur->value);
                    stack.pop();
                }
            } else if (prev == cur->right) {
                result.push_back(cur->value);
                stack.pop();
            }
        }
        prev = cur;
    }

    return result;
}

void Test(Node<int> *root) {
    std::vector<int> result = PostOrderTraverse(root);
    std::cout << "PostOrder Traverse tree: ";
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
