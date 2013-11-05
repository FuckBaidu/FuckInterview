/**
 * 2.2 in <Crack the code interview>.
 * Implement an algorithm to find the nth to last element in singly linked list
 */
#include "util.h"
Node<int> *FindNthToLast(Node<int> *head, int n) {
    Node<int> *runner = NULL, *result = NULL;
    int count = n;
    do {
        if (!count) {
            if (result)
                result = result->next;
            else
                result = head;
        } else {
            count--;
        }
        if (runner)
            runner = runner->next;
        else
            runner = head;
    } while (runner != NULL);
    return result;
}

void Test(int *array, int len, int n) {
    Node<int> *head = InitList(array, len);
    PrintList(head);
    Node<int> *result = FindNthToLast(head, n);
    std::cout << "The Nth element is :";
    if (result)
        std::cout << result->value;
    else
        std::cout << "NULL";
    std::cout << std::endl;
    FreeList(head);
}

int main() {
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Test(a1, sizeof(a1) / sizeof(int), 1);
    Test(a1, sizeof(a1) / sizeof(int), 5);
    Test(a1, sizeof(a1) / sizeof(int), 9);
    Test(a1, sizeof(a1) / sizeof(int), 10);
    int a2[] = {1, 2};
    Test(a2, sizeof(a2) / sizeof(int), 1);
    int a3[] = {1};
    Test(a3, sizeof(a3) / sizeof(int), 1);
    return 0;
}
