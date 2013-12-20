/*
 * Sort a linked list using insertion sort.
 * http://oj.leetcode.com/problems/insertion-sort-list/
 */
#include "list.h"

Node<int> *InsertionSort(Node<int> *head) {
    if (!head)
        return NULL;
    Node<int> *prev = head, *cur = head->next;
    while (cur) {
        if (prev->value <= cur->value) {
            // Already sorted, no need to change
            prev = cur;
            cur = cur->next;
        } else {
            // delete current node
            prev->next = cur->next;

            // insert it
            if (head->value > cur->value) {
                cur->next = head;
                head = cur;
            } else {
                Node<int> *insert_point = head;
                while (insert_point->next->value <= cur->value)
                    insert_point = insert_point->next;
                cur->next = insert_point->next;
                insert_point->next = cur;
            }

            // update cur
            cur = prev->next;
        }
    }
    return head;
}

void Test(int *array, int len) {
    Node<int> *head = InitList(array, len);
    PrintList(head);
    head = InsertionSort(head);
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

    return 0;
}
