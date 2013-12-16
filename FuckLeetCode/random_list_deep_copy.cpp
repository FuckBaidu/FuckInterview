/*
 * A linked list is given such that each node contains an additional random pointer which could
 * point to any node in the list or null.
 *
 * Return a deep copy of the list.
 * http://oj.leetcode.com/problems/copy-list-with-random-pointer/
 */
#include <map>
struct ListNode {
    int value;
    ListNode *next;
    ListNode *random;
    ListNode(int v) : value(v), next(NULL), random(NULL) { }
};

ListNode *CopyRandomList(ListNode *head) {
    ListNode *new_head = NULL, *prev = NULL, *cur = head;
    std::map<ListNode*, ListNode*> map;
    while (cur) {
        // allocate and copy node
        ListNode *node = new ListNode(cur->value);
        node->random = cur->random;
        // For random pointer modify later
        map[cur] = node;
        if (prev == NULL) {
            new_head = node;
        } else {
            prev->next = node;
        }
        prev = node;
        cur = cur->next;
    }

    // Modify random pointer
    cur = new_head;
    while (cur) {
        if (cur->random)
            cur->random = map[cur->random];
        cur = cur->next;
    }
    return new_head;
}

int main() {
    return 0;
}
