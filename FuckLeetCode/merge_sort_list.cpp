/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 * http://oj.leetcode.com/problems/sort-list/
 */
#include "list.h"
Node<int> *Merge(Node<int> *left, Node<int> *right) {
    Node<int> *new_head = NULL, *prev = NULL;
    while (left || right) {
        int left_valueue = left ? left->value : INT_MAX;
        int right_valueue = right ? right->value : INT_MAX;
        Node<int> *cur;
        if (left_valueue < right_valueue) {
            cur = left;
            left = left->next;
        } else {
            cur = right;
            right = right->next;
        }
        
        if (prev)
            prev->next = cur;
        else
            new_head = cur;
        prev = cur;
    }
    
    return new_head;
}

Node<int> *MergeSort(Node<int> *&cur, int len) {
    Node<int> *new_head;
    if (len == 1) {
        new_head = cur;
        cur = cur->next;
        new_head->next = NULL;
    } else {
        Node<int> *left = MergeSort(cur, len / 2);
        Node<int> *right = MergeSort(cur, len - len / 2);
        new_head = Merge(left, right);
    }
    return new_head;
}

Node<int> *Sort(Node<int> *head) {
    if (!head)
        return NULL;
    int len = 0;
    Node<int> *cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return MergeSort(head, len);
}

void Test(int *array, int len) {
    Node<int> *head = InitList(array, len);
    PrintList(head);
    head = Sort(head);
    PrintList(head);
    FreeList(head);
}

int main() {
    int a[] = {0};
    Test(a, sizeof(a) / sizeof(int));
    int b[] = {1, 2};
    Test(b, sizeof(b) / sizeof(int));
    int c[] = {2, 1};
    Test(c, sizeof(c) / sizeof(int));
    int d[] = {5, 3, 6, 2, 4};
    Test(d, sizeof(d) / sizeof(int));
    int e[] = {};
    Test(e, 0);
    int f[] = {4, 19, 14, 5, -3, 1, 8, 5, 11, 15};
    Test(f, sizeof(f) / sizeof(int));

    return 0;
}

