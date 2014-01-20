/*
 * Problem 1:
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

   For example,
   Given n = 3, there are a total of 5 unique BST's.
   
      1         3     3      2      1
       \       /     /      / \      \
        3     2     1      1   3      2
       /     /       \                 \
      2     1         2                 3
    
    Problem 2:
    Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
    
    For example,
    Given n = 3, your program should return all 5 unique BST's shown below.
    
       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
 */
#define private public
#define protected public
#include "tree.h"
#include <assert.h>

int NumTrees(int n) {
    if (n == 0)
        return 0;
    std::vector<int> num(n + 1);
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= i; j++)
            count += num[j - 1] * num[i - j];
        num[i] = count;
    }
    return num.back();
}

void GenerateTrees(int begin, int end, std::vector<Node<int>*> &result) {
    if (begin > end) {
        result.push_back(NULL);   
    } else {
        for (int i = begin; i <= end; i++) {
            std::vector<Node<int>*> left_subtree, right_subtree;
            GenerateTrees(begin, i - 1, left_subtree);
            GenerateTrees(i + 1, end, right_subtree);
            for (int j = 0; j < left_subtree.size(); j++) {
                for (int k = 0; k < right_subtree.size(); k++) {
                    Node<int> *node = new Node<int> (i);
                    node->left = left_subtree[j];
                    node->right = right_subtree[k];
                    result.push_back(node);
                }
            }
        }
    }
}

std::vector<Node<int> *> GenerateTrees(int n) {
    std::vector<Node<int>*> result;
    GenerateTrees(1, n, result);
    return result;
}

int main() {
    assert(NumTrees(4) == 14);
    std::vector<Node<int>*> result = GenerateTrees(4);
    for (int i = 0; i < result.size(); i++) {
        BinarySearchTree<int> tree;
        tree._root = result[i];
        tree.Print();
        std::cout << std::endl;
    }
    return 0;
}
