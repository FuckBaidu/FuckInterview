/*
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space
 * solution?
 */
#include "tree.h"
#include <stack>
void RecoverTree(Node<int> *root) {
    std::stack<Node<int>*> stack;
    Node<int> *cur = root, *prev = NULL, *node1 = NULL, *node2 = NULL;
    while (cur) {
        while (cur) {
            stack.push(cur);
            cur = cur->left;
        }
        
        do {
            cur = stack.top();
            stack.pop();
            if (prev && prev->value > cur->value) {
                if (!node1)
                    node1 = prev;
                node2 = cur;
            }
            prev = cur;
        } while (!stack.empty() && !cur->right);
        cur = cur->right;
    }
    if (node1 && node2)
        std::swap(node1->value, node2->value);
}

int main() {
    BinaryTree<int> tree1("2 1 $ $ 3 $ $");
    tree1.Print();
    RecoverTree(tree1.GetRoot());
    std::cout << "after recovery:" << std::endl;
    tree1.Print();

    std::cout << std::endl;
    BinaryTree<int> tree2("1 2 $ $ 3 $ $");
    tree2.Print();
    RecoverTree(tree2.GetRoot());
    std::cout << "after recovery:" << std::endl;
    tree2.Print();

    std::cout << std::endl;
    BinaryTree<int> tree3("2 3 $ $ 1 $ $");
    tree3.Print();
    RecoverTree(tree3.GetRoot());
    std::cout << "after recovery:" << std::endl;
    tree3.Print();
    return 0;
}
