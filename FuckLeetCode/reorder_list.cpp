/*
 * Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 * reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
#include "list.h"
void Merge(Node<int> *left_head, Node<int> *right_head) {
    while (right_head) {
        Node<int> *left_next = left_head->next, *right_next = right_head->next;
        left_head->next = right_head;
        right_head->next = left_next;
        left_head = left_next;
        right_head = right_next;
    }
}

Node<int> *Reverse(Node<int> *head) {
    Node<int> *cur = head, *prev = NULL;
    while (cur) {
        Node<int> *next = cur->next;
        if (!next)
            head = cur;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return head;
}

void ReorderList(Node<int> *head) {
    Node<int> *mid = head, *runner = head;
    while (runner) {
        if (runner->next && runner->next->next) {
            mid = mid->next;
        }
        runner = runner->next;
        if (runner)
            runner = runner->next;
    }
    Node<int> *right_head = Reverse(mid->next);
    mid->next = NULL; // Important
    Merge(head, right_head);
}

void Test(int *array, int len) {
    Node<int> *head = InitList(array, len);
    PrintList(head);
    ReorderList(head);
    PrintList(head);
    FreeList(head);
}

int main() {
    int a[] = {1};
    Test(a, 1);
    int b[] = {1, 2, 3, 4};
    Test(b, 4);
    int c[] = {1, 2, 3, 4, 5};
    Test(c, 5);
    return 0;
}
