/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

   An example is the root-to-leaf path 1->2->3 which represents the number 123.
   Find the total sum of all root-to-leaf numbers.
   For example,
       1
      / \
     2   3
   The root-to-leaf path 1->2 represents the number 12.
   The root-to-leaf path 1->3 represents the number 13.
   Return the sum = 12 + 13 = 25.
 */
#include <stdio.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void SumNumbers(TreeNode *node, int cur, int &sum) {
    cur += node->val;
    if (node->left || node->right) {
        cur *= 10;
        if (node->left)
            SumNumbers(node->left, cur, sum);
        if (node->right)
            SumNumbers(node->right, cur, sum);   
    } else {
        sum += cur;
    }
}

int SumNumbers(TreeNode *root) {
    if (!root)
        return 0;
    int sum = 0;
    SumNumbers(root, 0, sum);
    return sum;
}

int main() {
    return 0;
}
