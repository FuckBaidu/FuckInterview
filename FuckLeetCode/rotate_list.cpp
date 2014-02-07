/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */
#include "list.h"
Node<int> *RotateList(Node<int> *head, int k) {
    if (!head)
        return NULL;
    int len = 0;
    Node<int> *cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    k = k % len;
    if (k == 0)
        return head;
    Node<int> *new_head = head, *prev = NULL;
    for (int i = 0; i < len - k; i++) {
        prev = new_head;
        new_head  = new_head ->next;
    }
    prev->next = NULL;
    cur = new_head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = head;
    return new_head;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    Node<int> *head = InitList(a, 5);
    PrintList(head);
    for (int i = 0; i < 10; i++) {
        head = InitList(a, 5);
        std::cout << "After Rotate " << i << " steps:";
        PrintList(RotateList(head, i));
    }
    return 0;
}
