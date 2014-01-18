/*
 * Problem 1:
 * Given a binary tree
 * struct Node {
 *   Node* leftChild;
 *   Node* rightChild;
 *   Node* nextRight;
 * }
 * Populate the nextRight pointers in each node.
 * You may assume that it is a full binary tree (ie, each node other than the leaves has two children.)
 *
 */
#include <assert.h>
#include <queue>
struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
    Node* nextRight;
    Node(int data) : data(data), leftChild(NULL), rightChild(NULL), nextRight(NULL) {}
};

Node* GenerateFullBinaryTree(int num) {
    assert(num > 0);
    std::queue<Node *> queue;
    int count = 1;
    Node *head = new Node(0);
    queue.push(head);
    while (count < num) {
       Node *cur = queue.front();
       queue.pop();
       cur->leftChild = new Node(count);
       count++;
       queue.push(cur->leftChild);
       if (count == num)
           break;
       cur->rightChild = new Node(count);
       queue.push(cur->rightChild);
       count++;
    }
    return head;
}

void ConnectrightChild(Node *head) {
    if (!head)
        return;
    Node *leftChild = head->leftChild;
    Node *rightChild = head->rightChild;
    if (leftChild != NULL) {
        leftChild->nextRight = rightChild;
        if (rightChild != NULL) {
            if (head->nextRight != NULL)
                rightChild->nextRight = head->nextRight->leftChild;
            else
                rightChild->nextRight = NULL;
        }
        ConnectrightChild(leftChild);
        ConnectrightChild(rightChild);
    }
}

void PrintTree(Node *head) {
    assert(head != NULL);
    Node *cur = head;
    std::queue<Node*> queue;
    do {
        queue.push(cur);
        cur = cur->leftChild;
    } while (cur != NULL);
    int count = 0;
    while (!queue.empty()) {
        cur = queue.front();
        queue.pop();
        printf("level %d:", count++);
        do {
            printf("%d ", cur->data);
            cur = cur->nextRight;
        } while (cur != NULL);
        printf("\n");
    }
    printf("\n");
}

int main() {
    Node *head = GenerateFullBinaryTree(1);
    ConnectrightChild(head);
    PrintTree(head);
    head = GenerateFullBinaryTree(15);
    ConnectrightChild(head);
    PrintTree(head);
    head = GenerateFullBinaryTree(18);
    ConnectrightChild(head);
    PrintTree(head);
    head = GenerateFullBinaryTree(50);
    ConnectrightChild(head);
    PrintTree(head);
}
