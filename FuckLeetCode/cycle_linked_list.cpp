/**
 * Given a linked list, determine if it has a cycle in it.
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Follow up:
 * Can you solve it without using extra space?
 */
#include "list.h"
#include <assert.h>
bool HasCycle(Node<int> *head) {
    Node<int> *fast = head, *slow = head;
    while (fast) {
        for (int i = 0; i < 2 && fast; i++) {
            fast = fast->next;
            if (fast == slow)
                return true;
        }
        slow = slow->next;
    }
    return false;
}

Node<int> *DetectCycle(Node<int> *head) {
    bool find_cycle = false;
    Node<int> *fast = head, *slow = head;
    int distance = 0, num_fast_steps = 0, num_slow_steps = 0;
    while (fast) {
        for (int i = 0; i < 2 && fast != NULL; i++) {
            fast = fast->next;
            num_fast_steps++;
            if (fast == slow) {
                find_cycle = true;
                break;
            }
        }
        if (find_cycle)
            break;
        slow = slow->next;
        num_slow_steps++;
    }
    if (!find_cycle)
        return NULL;
    distance = num_fast_steps - num_slow_steps;
    fast = slow = head;
    for (int i = 0; i < distance; i++)
        fast = fast->next;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    Node<int> *head = InitList(a, sizeof(a) / sizeof(int));
    assert(!HasCycle(head));
    assert(!DetectCycle(head));
    Node<int> *cur = head, *loop = head, *tail;
    int len = 3;
    while (cur) {
        if (cur->next == NULL)
            tail = cur;
        if (len > 0) {
            len--;
            loop = loop->next;
        }
        cur = cur->next;
    }
    tail->next = loop;
    assert(HasCycle(head));
    assert(DetectCycle(head) == loop);
    return 0;
}
