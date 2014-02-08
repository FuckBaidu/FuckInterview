/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 *    Note:
 *    Given n will always be valid.
 *    Try to do this in one pass.
 */
#include "list.h"
Node<int> *RemoveNthFromEnd(Node<int> *head, int n) {
    Node<int> *runner = head, *cur = head, *prev = NULL;
    int i = 0;
    for (; i < n && runner; i++)
        runner = runner->next;
    if (i == n) {
        while (runner) {
            runner = runner->next;
            prev = cur;
            cur = cur->next;
        }
        if (prev)
            prev->next = cur->next;
        else
            head = cur->next;
        delete cur;
    }
    return head;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    Node<int> *head = InitList(a, 5);
    PrintList(head);
    head = RemoveNthFromEnd(head, 2);
    PrintList(head);
    return 0;
}
