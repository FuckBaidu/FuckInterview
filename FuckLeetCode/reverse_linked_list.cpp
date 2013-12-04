/*
 * Implement the reversal of a singly linked list iteratively and recursively.
 * f list.
 * http://leetcode.com/2010/04/reversing-linked-list-iteratively-and.html
 *
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 <= m <= n <= length of list
 * http://oj.leetcode.com/problems/reverse-linked-list-ii/
 */
#include "list.h"

Node<int>* ReverseList(Node<int> *head) {
    if (!head)
        return NULL;
    Node<int> *prev = NULL, *cur = head, *next = NULL;
    while (cur) {
        next = cur->next;
        if (!next)
            head = cur;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return head;
}

Node<int>* ReverseList1(Node<int> *head) {
    if (!head)
        return NULL;
    Node<int> *next = head->next;
    if (next) {
        Node<int> *cur = head;
        head = ReverseList1(next);
        next->next = cur;
        cur->next = NULL;
    }
    return head;
}

Node<int> *ReverseList(Node<int> *head, int m, int n) {
    if (!head)
        return NULL;
    int distance = n - m + 1;
    Node<int> *start = head, *end = head, *before = NULL;
    for (int i = 0; i < distance; i++)
        end = end->next;
    for (int i = 1; i < m; i++) {
        before = start;
        start = start->next;
        end = end->next;
    }
    Node<int> *prev = end, *next = NULL;
    while (start != end) {
        if (start->next == end) {
            if (!before)
                head = start;
            else
                before->next = start;
        }
        next = start->next;
        start->next = prev;
        prev = start;
        start = next;
    }

    return head;
}

void Test(int *array, int len) {
    Node<int> *head = InitList(array, len);
    PrintList(head);
    head = ReverseList(head);
    PrintList(head);
    head = ReverseList1(head);
    PrintList(head);
    head = ReverseList(head, 1, len);
    PrintList(head);
    if (len >= 5) {
        head = ReverseList(head, 1, 1);
        PrintList(head);
        head = ReverseList(head, 1, 4);
        PrintList(head);
        head = ReverseList(head, 2, 4);
        PrintList(head);
    }
    FreeList(head);
}

int main() {
    int a[] = {1};
    Test(a, sizeof(a) / sizeof(int));
    int b[] = {1, 3, 5, 7, 9};
    Test(b, sizeof(b) / sizeof(int));
    return 0;
}

