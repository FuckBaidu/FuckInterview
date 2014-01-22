/*
 * Check if a linked list a palindrome
 */
#include "list.h"
#include <assert.h>
bool IsPalindrome(Node<char> *&head, int len) {
    if (len == 0)
        return true;
    Node<char> *cur = head;
    bool result = false;
    if (len == 1) {
        result = true;
    } else {
        Node<char> *cur = head;
        head = head->next;
        if (IsPalindrome(head, len - 2) && cur->value == head->value)
            result = true;
        else
            result = false; 
    }
    head = head->next;
    return result;
}
bool IsPalindrome(Node<char> *head) {
    int len = 0;
    Node<char> *cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return IsPalindrome(head, len);
}

int main() {
    assert(IsPalindrome(NULL));
    char a[] = {'1', '2', '3', '3', '2', '1'};
    Node<char> *h1 = InitList(a, 6);
    assert(IsPalindrome(h1));
    char b[] = {'1', '2', '2', '2', '2', '1'};
    Node<char> *h2 = InitList(b, 6);
    assert(IsPalindrome(h2));
    char c[] = {'1', '2', '2', '2', '2', '3'};
    Node<char> *h3 = InitList(c, 6);
    assert(!IsPalindrome(h3));
    char d[] = {'1', '2', '3', '2', '1'};
    Node<char> *h4 = InitList(d, 5);
    assert(IsPalindrome(h4));
    return 0;
}
