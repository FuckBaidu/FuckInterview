#ifndef  __UTIL_H_
#define  __UTIL_H_
#include <iostream>
#include <stdlib.h>

template <class T>
struct Node {
    T value;
    Node *next;

    Node(T _value) : value(_value), next(NULL) {}
};

template <class T>
void PrintList(Node<T> *head) {
    while (head != NULL) {
        std::cout << head->value;
        if (head->next)
            std::cout << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

template <class T>
void FreeList(Node<T> *head) {
    Node<T> *cur;
    while (head != NULL) {
        cur = head;
        head = head->next;
        delete cur;
    }
}

template <class T>
Node<T> *InitList(T *array, int len) {
    if (!array)
        return NULL;
    Node<T> *head = NULL, *cur = NULL;
    for (int i = 0; i < len; i++) {
        Node<T> *node = new Node<T>(array[i]);
        if (!head) {
            head = node;
        } else {
            cur->next = node;
        }
        cur = node;
    }

    return head;
}

template <class T>
void CopyList(Node<T> *&dst, Node<T> *src) {
    Node<T> *cur = dst;
    while (src != NULL) {
        Node<int> *node = new Node<int>(src->value);
        if (!cur) {
            dst = node;
            cur = node;
        } else {
            cur->next = node;
        }
        cur = node;
        src = src->next;
    }
}

#endif  //__UTIL_H_
