/**
 * Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
 *
 */
#include "tree.h"
Node<int> *ToDoubleLinkedList(Node<int> *node) {
    Node<int> *right = node->right, *last = node;
    if (node->left) {
        node->right = node->left;
        last = ToDoubleLinkedList(node->left);
        node->left = NULL;
        last->right = right;
    }
    if (right)
        last = ToDoubleLinkedList(right);
    return last;
}

void Flatten(Node<int> *root) {
    if (!root)
        return;
    ToDoubleLinkedList(root);
}

void Test(const std::string &rep) {
    BinaryTree<int> tree(rep);
    tree.Print();
    Node<int> *root = tree.GetRoot();
    Flatten(root);
    Node<int> *cur = root;
    while (cur) {
        std::cout << cur->value;
        cur = cur->right;
        if (cur)
            std::cout << "->";
    }
    std::cout << std::endl;
}

int main() {
    Test("1 2 $");
    Test("1 $ 2");
    Test("1 2 3 $ $ 4 $ $ 5 $ 6 $ $");
    return 0;
}
