/**
 * 2.7 in <Crack the code interview> 5th edition.
 * Write a method to check if a linked list is a palindrome
 */
#include "util.h"
const Node<char> *FindMiddle(const Node<char> *head) {
    const Node<char> *mid = head, *cur = head;
    while (cur) {
        cur = cur->next;
        if (!cur)
            break;
        cur = cur->next;
        if (cur)
            mid = mid->next;
    }
    return mid;
}

Node<char> *ReverseList(Node<char> *head) {
    Node<char> *prev = NULL, *cur = head, *next = NULL, *tail = NULL;
    while (cur) {
        next = cur->next;
        if (!next)
            tail = cur;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return tail;
}

bool IsPalindrome(const Node<char> *head) {
    if (!head)
        return false;
    Node<char> *mid = (Node<char>*)FindMiddle(head);
    Node<char> *half_head = ReverseList(mid->next);
    mid->next = NULL;

    bool result = true;
    const Node<char> *cur1 = head, *cur2 = half_head;
    while (cur1 && cur2) {
        if (cur1->value != cur2->value) {
            result = false;
            break;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    // Restore list
    mid->next = ReverseList(half_head);
    return result;
}

void Test(const std::string &str) {
    Node<char> *head = InitList(str.c_str(), str.length());
    std::cout << "Is " << str << " a palindrome? " << IsPalindrome(head) << std::endl;
    FreeList(head);
}

int main() {
    Test("abccba");
    Test("abcba");
    Test("abcb");
    Test("a");
    Test("");
    return 0;
}

