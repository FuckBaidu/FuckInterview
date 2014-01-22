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
    ListNode(const ListNode *node) : value(node->value), next(node->next), random(node->random){ }
};

ListNode *GetNewNode(std::map<ListNode*, ListNode*> &map, ListNode *cur) {
    ListNode *node;
    if (map.count(cur)) {
        node = map[cur];
    } else {
        node = new ListNode(cur);
        map[cur] = node;
    }
    return node;
}

ListNode *CopyRandomList(ListNode *head) {
    ListNode *new_head = NULL, *cur = head;
    std::map<ListNode*, ListNode*> map;
    while (cur) {
        // Getnew node
        ListNode *node = GetNewNode(map, cur);
        if (!new_head)
            new_head = node;
        // Set next pointer
        if (cur->next)
            node->next = GetNewNode(map, cur->next);
        // Set random pointer
        if (cur->random)
            node->random = GetNewNode(map, cur->random);
        cur = cur->next;
    }
    return new_head;
}

int main() {
    return 0;
}
