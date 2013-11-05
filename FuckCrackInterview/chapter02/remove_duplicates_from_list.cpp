/**
 * 2.1 in <Crack the code interview>:
 * Write code to remove duplicates from an unsorted linked list
 */

#include "util.h"

void RemoveDuplicate(Node<char> *head) {
    bool flags[256];
    memset(flags, 0, sizeof(flags));
    Node<char> *cur = head, *prev = NULL;
    while(cur != NULL) {
        char value = cur->value;
        if (flags[value]) {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else {
            flags[value] = true;
            prev = cur;
            cur = cur->next;
        }
    }
}

void RemoveDuplicate1(Node<char> *head) {
    Node<char> *cur = head;
    while(cur != NULL) {
        char value = cur->value;
        Node<char> *prev = cur, *runner = cur->next;
        while (runner != NULL) {
            if (runner-> value == value) {
                prev->next = runner->next;
                delete runner;
                runner = prev->next;
            } else {
                prev = runner;
                runner = runner->next;
            }
        }
        cur = cur->next;
    }
}

void Test(char *array, int len) {
    Node<char> *head = InitList(array, len);
    std::cout << "Before:" << std::endl;
    PrintList(head);
    RemoveDuplicate(head);
    std::cout << "After:" << std::endl;
    PrintList(head);
    FreeList(head);
}

void Test1(char *array, int len) {
    Node<char> *head = InitList(array, len);
    std::cout << "Before:" << std::endl;
    PrintList(head);
    RemoveDuplicate1(head);
    std::cout << "After:" << std::endl;
    PrintList(head);
    FreeList(head);
}

int main() {
    char a1[] = {'1'};
    Test(a1, sizeof(a1) / sizeof(char));
    Test1(a1, sizeof(a1) / sizeof(char));
    char a2[] = {'1', '2'};
    Test(a2, sizeof(a2) / sizeof(char));
    Test1(a2, sizeof(a2) / sizeof(char));
    char a3[] = {'1', '1'};
    Test(a3, sizeof(a3) / sizeof(char));
    Test1(a3, sizeof(a3) / sizeof(char));
    char a4[] = {'1', '1', '1'};
    Test(a4, sizeof(a4) / sizeof(char));
    Test1(a4, sizeof(a4) / sizeof(char));
    char a5[] = {'3', '1', '1', '2', '3', '2'};
    Test(a5, sizeof(a5) / sizeof(char));
    Test1(a5, sizeof(a5) / sizeof(char));
    return 0;
}
