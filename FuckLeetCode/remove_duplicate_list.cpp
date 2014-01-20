/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */
#include "list.h"
Node<int> *DeleteDuplicates(Node<int> *head) {
    Node<int> *cur = head;
    while (cur) {
        Node<int> *runner = cur->next;
        while (runner && runner->value == cur->value)
            runner = runner->next;
        cur->next = runner;
        cur = runner;
    }
    return head;
}

int main() {
    int a[] = {1, 1, 2};
    Node<int> *h1 = InitList(a, 3);
    PrintList(h1);
    h1 = DeleteDuplicates(h1);
    PrintList(h1);

    int b[] = {1, 1, 2, 3, 3};
    Node<int> *h2 = InitList(b, 5);
    PrintList(h2);
    h2 = DeleteDuplicates(h2);
    PrintList(h2);
    return 0;
}
