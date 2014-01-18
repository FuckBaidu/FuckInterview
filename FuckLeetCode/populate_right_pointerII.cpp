/*
 *  Follow up for problem "Populating sibling Right Pointers in Each Node".

    What if the given tree could be any binary tree? Would your previous solution still work?
    
    Note:
    
    You may only use constant extra space.
    For example,
    Given the following binary tree,
             1
           /  \
          2    3
         / \    \
        4   5    7
    After calling your function, the tree should look like:
             1 -> NULL
           /  \
          2 -> 3 -> NULL
         / \    \
        4-> 5 -> 7 -> NULL
 */
#include "tree.h"
Node<int>* PopulateNext(Node<int> *node) {
    Node<int> *next = NULL, *cur = node->sibling;
    while (cur) {
        if (cur->left) {
            next = cur->left;
            break;
        }
        if (cur->right) {
            next = cur->right;
            break;
        }
        cur = cur->sibling;
    }
    return next;
}

void Connect(Node<int> *root) {
    if (!root)
        return;
    // should deal with the right subtree first
    if (root->right) {
        root->right->sibling = PopulateNext(root);
        Connect(root->right);
    }   
    if (root->left) {
        if (root->right)
            root->left->sibling = root->right;
        else
            root->left->sibling = PopulateNext(root);
        Connect(root->left);
    }
}

void PrintTree(Node<int> *head) {
    assert(head != NULL);
    Node<int> *cur = head;
    std::queue<Node<int>*> queue;
    do {
        queue.push(cur);
        cur = cur->left;
    } while (cur != NULL);
    int count = 0;
    while (!queue.empty()) {
        cur = queue.front();
        queue.pop();
        printf("level %d:", count++);
        do {
            printf("%d ", cur->value);
            cur = cur->sibling;
        } while (cur != NULL);
        printf("\n");
    }
    printf("\n");
}

int main() {
    BinaryTree<int> tree("1 2 4 6 $ $ $ 5 $ $ 3 $ 7 $ 8 $ $");
    Connect(tree.GetRoot());
    PrintTree(tree.GetRoot());
    return 0;
}
