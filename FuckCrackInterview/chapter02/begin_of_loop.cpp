/**
 * 2.5 in <Crack the code interview>.
 * Given a cicular linked list, implement an algorithm which returns node 
 * at the beginning of the loop
 * DEFINITION
 * Circular linked list: A(corrupt) linked list in which a node's next 
 * pointer points to an earlier node, so as to make a loop in the linked list
 * EXAMPLE
 * input: A->B->C->D->E->C[the same C as earlier]
 * output: C
 */
#include "util.h"
inline int GetPosition(char c) {
    if (c >= 'A' && c<= 'Z')
        return 26 + (c - 'A');
    else if (c >= 'a' && c<= 'z')
        return c - 'a';
    else
        return -1;
}

Node<char>* MakeCircularList(char *array, int len) {
    Node<char> *ptrs[52];
    memset(ptrs, 0, sizeof(ptrs));
    Node<char> *prev = NULL, *head = NULL;
    for (int i = 0; i < len; i++) {
        Node<char> *cur;
        if (ptrs[GetPosition(array[i])]) {
            cur = ptrs[GetPosition(array[i])];
        } else {
            cur = new Node<char>(array[i]);
            ptrs[GetPosition(array[i])] = cur;
        }
        if (!head) {
            head = cur;
        } else {
            prev->next = cur;
        }
        prev = cur;
    }
    return head;
}

void PrintCircularList(Node<char> *head) {
    bool flags[52];
    memset(flags, 0, sizeof(flags));
    while (head) {
        std::cout << head->value;
        if(flags[GetPosition(head->value)])
            break;
        std::cout << "->";
        flags[GetPosition(head->value)] = true;
        head = head->next;
    }
    std::cout << std::endl;
}

Node<char>* FindLoopBegin(Node<char> *head) {
    Node<char>* loop_begin = NULL;
    Node<char>* fast = head, *slow = head;
    int fast_count = 0, slow_count = 0;
    while (1) {
        for (int i = 0; i < 2; i++) {
            fast = fast->next;
            ++fast_count;
            if (fast == slow)
                goto LABEL_MEET;
        }
        slow = slow->next;
        ++slow_count;
    }
LABEL_MEET:
    int loop_len = fast_count - slow_count;
    fast = slow = head;
    for (int i = loop_len; i > 0; i--)
        fast = fast->next;
    do {
        fast = fast->next;
        slow = slow->next;
    } while (fast != slow);
    return fast;
}

void Test(char *array, char len) {
    Node<char> *head = MakeCircularList(array, len);
    std::cout << "Circular List:" << std::endl;
    PrintCircularList(head);
    std::cout << "Beginning of Loop:" << std::endl;
    Node<char> *loop_begin = FindLoopBegin(head);
    std::cout << loop_begin->value << std::endl;
}

int main() {
    char a1[] = {'A', 'B', 'C', 'D', 'E', 'C'};
    Test(a1, sizeof(a1) / sizeof(char));
    char a2[] = {'A', 'B', 'c', 'D', 'E', 'c'};
    Test(a2, sizeof(a2) / sizeof(char));
    return 0;
}
