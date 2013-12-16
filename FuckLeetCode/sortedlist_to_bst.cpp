/*
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height
 * balanced BST.
 */
#define private public
#define protected public
#include "tree.h"
struct ListNode {
    int value;
    ListNode *next;
    ListNode(int v) : value(v), next(NULL) { }
};

Node<int> *SortedListToBST(ListNode *&head, int begin, int end) {
    if (begin > end) {
        return NULL;
    } else {
        int mid = begin + (end - begin) / 2;
        Node<int> *left = SortedListToBST(head, begin, mid - 1);
        Node<int> *node = new Node<int>(head->value);
        node->left = left;
        head = head->next;
        node->right = SortedListToBST(head, mid + 1, end);
        return node;
    }
}

Node<int> *SortedListToBST(ListNode *head) {
    int len = 0;
    ListNode *cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    Node<int> *root = NULL;
    root = SortedListToBST(head, 0, len - 1);
    return root;
}

void PrintList(const ListNode *head) {
    while (head != NULL) {
        std::cout << head->value;
        if (head->next)
            std::cout << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

void FreeList(ListNode *head) {
    ListNode *cur;
    while (head != NULL) {
        cur = head;
        head = head->next;
        delete cur;
    }
}

ListNode *InitList(const int *array, int len) {
    if (!array)
        return NULL;
    ListNode *head = NULL, *cur = NULL;
    for (int i = 0; i < len; i++) {
        ListNode *node = new ListNode(array[i]);
        if (!head) {
            head = node;
        } else {
            cur->next = node;
        }
        cur = node;
    }

    return head;
}

void Test(int *array, int len) {
    ListNode *head = InitList(array, len);
    PrintList(head);
    Node<int> *root = SortedListToBST(head);
    BinarySearchTree<int> tree;
    tree._root = root;
    tree.Print();
    FreeList(head);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    Test(a, 6);
    int b[] = {1, 2, 3, 4, 5, 6, 7};
    Test(b, 7);
    return 0;
}
