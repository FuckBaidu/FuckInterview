/**
 * 2.4 in <Crack the code interview> 5th edition.
 * Write Code to partition a linked list around a value x, such that all nodes
 * less than x come before all nodes greater than x
 */
#include "util.h"

void PartitionList(Node<int> *head, int x) {
    Node<int> *larger = head, *smaller = NULL;
    while (larger) {
        if (larger->value <= x) {
            if (smaller == NULL)
                smaller = head;
            else
                smaller = smaller->next;
            std::swap(larger->value, smaller->value);
        }
        larger = larger->next;
    }
}

int main() {
    int a[] = {3, 6, 7, 5, 9, 2, 5, 1, 4};
    Node<int> *head = InitList(a, sizeof(a) / sizeof(int));
    PrintList(head);
    PartitionList(head, 5);
    PrintList(head);
    FreeList(head);
    return 0;
}
