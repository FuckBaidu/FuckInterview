/**
 * 2.3 in <Crack the code interview>.
 * Implement an algorithm to delete a node in the middle of a single linked list
 * Example:
 * input:a->b->c->d->e
 * output:a->b->d->e
 */
#include "util.h"
Node<int>* DeleteMiddle(Node<int> *head) {
    Node<int> *mid = head, *cur = head, *prev = NULL;
    while (cur != NULL) {
        int count = 2;
        while (count--) {
            cur = cur->next;
            if (!cur)
                goto LABEL_FIND; 
        }
        prev = mid;
        mid = mid->next;
    }
LABEL_FIND:
    if (prev)
        prev->next = mid->next;
    else
        head = mid->next;
    delete mid;
    return head;
}

void Test(int *array, int len) {
    Node<int> *head = InitList(array, len);
    std::cout << "Before:" << std::endl;
    PrintList(head);
    head = DeleteMiddle(head);
    std::cout << "After:" << std::endl;
    PrintList(head);
    FreeList(head);
}

int main() {
    int a1[] = {1};
    Test(a1, sizeof(a1) / sizeof(int));
    int a2[] = {1, 2};
    Test(a2, sizeof(a2) / sizeof(int));
    int a3[] = {1, 2, 3, 4, 5, 6, 7};
    Test(a3, sizeof(a3) / sizeof(int));
    return 0;
}
