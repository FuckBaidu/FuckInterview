/*
 * Given a binary tree, find its maximun height
 * http://leetcode.com/2010/04/maximum-height-of-binary-tree.html
 */
#include <stack>
#include "tree.h"

int GetHeight(Node<int> *node) {
    if (!node) {
        return 0;
    } else {
        int left_height = node->left ? GetHeight(node->left) : 0;
        int right_height = node->right ? GetHeight(node->right) : 0;
        return std::max(left_height, right_height) + 1;
    }
}

int GetHeight1(Node<int> *node) {
    if (!node) {
        return 0;
    } else {
        std::stack<Node<int>*> stack;
        stack.push(node);
        int max_height = 0;
        Node<int> *prev = NULL;
        while (!stack.empty()) {
            Node<int> *cur = stack.top();
            if (!prev || cur == prev->left || cur == prev->right) {
                if (cur->left)
                    stack.push(cur->left);
                else if (cur->right)
                    stack.push(cur->right);
                else {
                    if (max_height < stack.size())
                        max_height = stack.size();
                    stack.pop();
                }
            } else {
                if (prev == cur->left) {
                    if (cur->right)
                        stack.push(cur->right);
                    else
                        stack.pop();
                } else if (prev == cur->right) {
                    stack.pop();
                }
            }
            prev = cur;
        }

        return max_height;
    }
}

int main() {
    srand(time(NULL));
    BinarySearchTree<int> tree;
    for (int i = 0; i < 10; i++)
        tree.Insert(rand() % 20);
    tree.Print();
    std::cout << "Height: " << GetHeight1(tree.GetRoot()) << std::endl;
    return 0;
}
