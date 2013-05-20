/**
 *  reverse the last half of single linked list, the merge the list with first half of the list
 *  eg: Input:  a->b->c->d->e->f->g
 *      Output: a->g->b->f->c->e->d
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
struct list_node {
    char data;
    struct list_node *next;
};

void PrintList(list_node *head) {
    while (head != NULL) {
        printf("%c ",  head->data);
        head = head->next;
    }

    printf("\n");
}


list_node *FindMidOfList(list_node *head) {
    list_node *cur = head, *mid = head;
    while (cur->next != NULL) {
        cur = cur->next;
        if (cur->next != NULL) {
            cur = cur->next;
            mid = mid->next;
        }
    }
    return mid;
}

list_node *ReverseList(list_node *head) {
    list_node *prev = NULL, *cur = head, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

list_node *MergeList(list_node *head1, list_node *head2) {
    list_node *cur1 = head1, *cur2 = head2, *new_head = head1, *tmp = NULL;
    while (cur1 != NULL && cur2 != NULL) {
        tmp = cur1->next;
        if (cur2 != NULL)
            cur1->next = cur2;
        cur1 = tmp;
        tmp = cur2->next;
        if (cur1 != NULL)
            cur2->next = cur1;
        cur2 = tmp;
    }

    return new_head;
}


list_node *FuckList(list_node *head) {
    if (head == NULL)
        return NULL;
    list_node *mid = FindMidOfList(head);
    if (mid->next == NULL)
        return head;
    list_node *new_mid = mid->next;
    mid->next = NULL;
    new_mid = ReverseList(new_mid);
    head = MergeList(head, new_mid);
    return head;
}

list_node *PrepareList(const char *str) {
    list_node *head = NULL, *cur = NULL, *prev = NULL;
    for (int i = 0; i < strlen(str); i++) {
       cur = (list_node*)malloc(sizeof(list_node));
       cur->data = str[i];
       cur->next = NULL;
       if (prev != NULL) {
           prev->next = cur;
           prev = cur;
       } else {
           prev = cur;
       }

       if (head == NULL)
           head = cur;
    }
    return head;
}

void FreeList(list_node *head) {
    list_node *cur = head, *tmp = NULL;
    while (cur != NULL) {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

int main() {
    printf("Test1\n");
    assert(FuckList(NULL) == NULL);
    printf("Test2\n");
    list_node *head = PrepareList("abcdefg");
    PrintList(head);
    head = FuckList(head);
    PrintList(head);
    FreeList(head);

    printf("Test3\n");
    head = PrepareList("abcdef");
    PrintList(head);
    head = FuckList(head);
    PrintList(head);
    FreeList(head);

    printf("Test4\n");
    head = PrepareList("a");
    PrintList(head);
    head = FuckList(head);
    PrintList(head);
    FreeList(head);

    printf("Test5\n");
    head = PrepareList("abc");
    PrintList(head);
    head = FuckList(head);
    PrintList(head);
    FreeList(head);
    return 0;
}
