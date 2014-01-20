/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes
 * greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */
#include "list.h"
Node<int> *Partition(Node<int> *head, int x) {
    Node<int> *cur = head, *prev = NULL, *less = NULL;
    while (cur) {
        if (cur->value >= x || prev == less) {
            if (cur->value < x)
                less = cur;
            prev = cur;
            cur = cur->next;
        } else {
            // delete node
            prev->next = cur->next;
            // add to front
            if (less) {
                cur->next = less->next;
                less->next = cur;
            } else {
                cur->next = head;
                head = cur;
            }
            less = cur;
            cur = prev->next;
        }
    }
    return head;
}

int main() {
    int a[] = {1, 4, 3, 2, 5, 2};
    Node<int> *h1 = InitList(a, 6);
    PrintList(h1);
    h1 = Partition(h1, 3);
    PrintList(h1);
    FreeList(h1);

    int b[] = {1, 2, 3, 4, 5, 6};
    Node<int> *h2 = InitList(b, 6);
    PrintList(h2);
    h2 = Partition(h2, 3);
    PrintList(h2);
    FreeList(h2);

    int c[] = {4, 3, 2, 1, 5, 2};
    Node<int> *h3 = InitList(c, 6);
    PrintList(h3);
    h3 = Partition(h3, 3);
    PrintList(h3);
    FreeList(h3);
    return 0;
}
