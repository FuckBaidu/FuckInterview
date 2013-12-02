/**
 * 2.4 in <Crack the code interview>.
 * You have two numbers represented by a linked list, where each node contains a single digit.
 * The digitss are stored in reversed order.Write a function that adds the two numbers and return
 * the sum as a linked list
 */
#include "util.h"
Node<int>* Sum(Node<int> *head1, Node<int> *head2) {
    int carry = 0;
    Node<int> *cur1 = head1, *cur2 = head2, *result = NULL, *curr = NULL;
    while (cur1 != NULL && cur2 != NULL) {
        int value = (cur1->value + cur2->value + carry) % 10;
        carry = (cur1->value + cur2->value + carry) / 10;
        Node<int> *node = new Node<int>(value);
        if (!result) {
            result = node;
        } else {
            curr->next = node;
        }
        curr = node;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    if (cur1 != NULL && cur2 == NULL)
        CopyList(curr, cur1);
    else if (cur2 != NULL && cur1 == NULL)
        CopyList(curr, cur2);
    if (!result)
        result = curr;
    return result;
}

Node<int> *Sum1(const Node<int> *l1, const Node<int> *l2) {
    int carry = 0, sum = 0;
    Node<int> *head = NULL, *cur = NULL;
    while (l1 || l2) {
        int num1 = l1? l1->value : 0;
        int num2 = l2? l2->value: 0;
        sum = (num1 + num2 + carry) % 10;
        carry = (num1 + num2 + carry) / 10;
        Node<int> *new_node = new Node<int>(sum);
        new_node->next = NULL;
        if (!head) {
            head = new_node;
        } else {
            cur->next = new_node;
        }
        cur = new_node;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry) {
        Node<int> *new_node = new Node<int>(sum);
        new_node->next = NULL;
        cur->next = new_node;
    }
    return head;
}

void Test(int *array1, int len1, int *array2, int len2) {
    Node<int> *head1 = InitList(array1, len1);
    Node<int> *head2 = InitList(array2, len2);
    Node<int> *result = Sum1(head1, head2);
    PrintList(head1);
    std::cout << "Add" << std::endl;
    PrintList(head2);
    std::cout << "Equals:" << std::endl;
    PrintList(result);
    FreeList(head1);
    FreeList(head2);
    FreeList(result);
}

int main() {
    int a1[] = {3, 1, 6};
    int a2[] = {5, 9, 2};
    int a3[] = {};
    int a4[] = {5, 9, 2, 1, 2, 3};
    Test(a1, sizeof(a1) / sizeof(int), a2 ,sizeof(a2)/sizeof(int));
    Test(a3, sizeof(a3) / sizeof(int), a2 ,sizeof(a2)/sizeof(int));
    Test(a4, sizeof(a4) / sizeof(int), a2 ,sizeof(a2)/sizeof(int));
    Test(a2, sizeof(a2) / sizeof(int), a4 ,sizeof(a4)/sizeof(int));
    return 0;
}
