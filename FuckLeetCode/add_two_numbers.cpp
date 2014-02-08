/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in
 * reverse order and each of their nodes contain a single digit. Add the two numbers and return it
 * as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
#include "list.h"
#include <vector>
#include <iostream>
Node<int> *AddTwoNumbers(Node<int> *l1, Node<int> *l2) {
    Node<int> *head = NULL, *cur = NULL;
    int carry = 0;
    while (l1 || l2) {
        int va = l1 ? l1->value : 0;
        int vb = l2 ? l2->value : 0;
        int sum = (va + vb + carry) % 10;
        carry = (va + vb + carry) / 10;
        Node<int> *node = new Node<int>(sum);
        if (cur)
            cur->next = node;
        else
            head = node;
        cur = node;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry) {
        Node<int> *node = new Node<int>(carry);
        cur->next = node;
    }
    return head;
}

int main() {
    int a[] = {2, 4, 3}, b[] = {5, 6, 4};
    Node<int> *h1 = InitList(a, 3);
    std::cout << "  ";
    PrintList(h1);
    Node<int> *h2 = InitList(b, 3);
    std::cout << "+ ";
    PrintList(h2);
    Node<int> *result = AddTwoNumbers(h1, h2);
    std::cout << "= ";
    PrintList(result);
    int c[] = {2, 4, 3}, d[] = {5, 6, 7};
    h1 = InitList(c, 3);
    std::cout << "  ";
    PrintList(h1);
    h2 = InitList(d, 3);
    std::cout << "+ ";
    PrintList(h2);
    result = AddTwoNumbers(h1, h2);
    std::cout << "= ";
    PrintList(result);
    return 0;
}
