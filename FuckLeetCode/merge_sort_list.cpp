/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 * http://oj.leetcode.com/problems/sort-list/
 */
#include "list.h"
Node<int> *Merge(Node<int> *left_head, Node<int> *right_head, int len, Node<int> *&tail) {
    Node<int> *left = left_head, *right = right_head, *end = tail->next,
              *prev = NULL, *head = left_head;
    int left_len = len / 2, right_len = len - len / 2;
    while (left_len || right_len) {
        int left_value = left_len ? left->value : INT_MAX;
        int right_value = right_len ? right->value : INT_MAX;
        Node<int> *cur;
        if (left_value <= right_value) {
            cur = left;
            left = left->next;
            left_len--;
        } else {
            cur = right;
            right = right->next;
            right_len--;
        }
        if (prev)
            prev->next = cur;
        else
            head = cur;
        prev = cur;
    }
    // update tail
    tail = prev;
    tail->next = end;
    return head;
}

Node<int> *MergeSort(Node<int> *head, int len, Node<int> *&tail) {
    if (len > 1) {
        Node<int> *left_head = MergeSort(head, len / 2, tail);
        tail = tail->next;
        Node<int> *right_head = MergeSort(tail, len - len / 2 , tail);
        head = Merge(left_head, right_head, len, tail);
    }
    return head;
}

Node<int> *Sort(Node<int> *head) {
    if (!head)
        return NULL;
    int len = 0;
    Node<int> *tail = head, *cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return MergeSort(head, len, tail);
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

