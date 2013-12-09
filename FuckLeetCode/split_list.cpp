/*
 * Given a list, split it into two sublists ? one for the front half, and one for the back half. If
 * the number of elements is odd, the extra element should go in the front list. So FrontBackSplit()
 * on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}.
 * http://leetcode.com/2010/09/splitting-linked-list.html
 */
#include "list.h"
template<class T>
void SplitList(Node<T> *head, Node<T> **front_half, Node<T> **back_half) {
    if (!head)
        return;
    *front_half = head, *back_half = head;
    Node<T> *runner = head;
    while (runner) {
        runner = runner->next;
        if (runner && runner->next) {
            runner = runner->next;
            *back_half = (*back_half)->next;
        }
    }
    Node<T> *tmp = (*back_half)->next;
    (*back_half)->next = NULL;
    *back_half = tmp;
}

void Test(int *array, int len) {
    Node<int> *head = InitList(array, len);
    PrintList(head);
    Node<int> *front_half = NULL, *back_half = NULL;
    SplitList(head, &front_half, &back_half);
    PrintList(front_half);
    PrintList(back_half);
    FreeList(front_half);
    FreeList(back_half);
}

int main() {
    int a[] = {0};
    Test(a, sizeof(a) / sizeof(int));
    int b[] = {0, 1};
    Test(b, sizeof(b) / sizeof(int));
    int c[] = {0, 1, 2, 3};
    Test(c, sizeof(c) / sizeof(int));
    int d[] = {0, 1, 2, 3, 4};
    Test(d, sizeof(d) / sizeof(int));
    return 0;
}
