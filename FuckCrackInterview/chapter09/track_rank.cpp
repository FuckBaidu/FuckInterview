/**
 * 11.8 in <Crack the code interview> 5th edition.
 * Imagine you are reading in a stream of integers.Periodically, you wish to be
 *  able to look up the rank of number x(the number of values less than or equal
 *  to x).Implement the method GetRankOfNumber(int x), which returns the dynamic
 *  rank of number x when numbers are generated continuously
 */
#include <assert.h>
#include <iostream>
#include <vector>
struct Node {
    int value;
    int size;
    Node *left;
    Node *right;
    Node(int _value) : value(_value), size(1), left(NULL), right(NULL) { }
};

void InsertTree(int value, Node **root) {
    if (*root) {
        Node *cur = *root, *parent = NULL;
        while (cur) {
            parent = cur;
            cur->size++;
            if (value <= cur->value)
                cur = cur->left;
            else
                cur = cur->right;
        }
        cur = new Node(value);
        if (value <= parent->value)
            parent->left = cur;
        else
            parent->right = cur;
    } else {
        *root = new Node(value);
    }
}

int GetRankOfNumber(const Node *root, int x) {
    assert(root != NULL);
    const Node *cur = root, *parent = NULL;
    int count = 0;
    while (cur) {
        if (cur->value == x)
            break;
        parent = cur;
        if (x > cur->value)
            cur = cur->right;
        else
            cur = cur->left;
    }
    if (cur) {
        count = cur->size - 1;
        if (cur->right != NULL)
            count -= (cur->right->size);
        if (parent != NULL && parent->right == cur)
            count += (parent->size - cur->size);
    }
    return count;
}

void Test() {
    int a[] = {5, 1, 4, 4, 5, 9, 7, 13, 3};
    Node *root = NULL;
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        InsertTree(a[i], &root);
        std::cout << "The integer stream is: ";
        for (int j = 0; j <= i; j++)
            std::cout << a[j] << " ";
        std::cout << std::endl;
        std::cout << "The rank of number 5 is: " << GetRankOfNumber(root, 5) << std::endl;
        std::cout << "The rank of number 4 is: " << GetRankOfNumber(root, 4) << std::endl;
        std::cout << "The rank of number 9 is: " << GetRankOfNumber(root, 9) << std::endl;
    }
}

int main() {
    Test();
    return 0;
}
