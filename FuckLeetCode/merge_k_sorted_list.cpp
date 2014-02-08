/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its
 * complexity.
 */
#include "list.h"
#include <queue>
struct Comparator {
    bool operator()(Node<int> *&left, Node<int> *&right) const {
        return left->value > right->value;
    }
};

Node<int> *MergeKLists(std::vector<Node<int> *> &lists) {
    Node<int> *head = NULL, *prev = NULL;
    std::priority_queue<Node<int>*, std::vector<Node<int>*>, Comparator> heap;
    for (int i = 0; i < lists.size(); i++)
        if (lists[i])
            heap.push(lists[i]);
    while (!heap.empty()) {
        Node<int> *cur = heap.top();
        heap.pop();
        if (!prev)
            head = cur;
        else
            prev->next = cur;
        prev = cur;
        if (cur->next)
            heap.push(cur->next);
    }
    return head;
}
