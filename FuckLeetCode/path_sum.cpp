/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 */
#include "tree.h"
void PathSum(Node<int> *root, int sum, std::vector<int> path, std::vector< std::vector<int> > &results) {
    if (!root)
        return;
    sum -= root->value;
    path.push_back(root->value);
    if (sum == 0 && !root->left && !root->right) {
        results.push_back(path);
    } else {
        if (root->left)
            PathSum(root->left, sum, path, results);
        if (root->right)
            PathSum(root->right, sum, path, results);
    }
}

std::vector< std::vector<int> > PathSum(Node<int> *root, int sum) {
    std::vector< std::vector<int> > results;
    if (root)
        PathSum(root, sum, std::vector<int>(), results);
    return results;
}

void Test(const std::string &rep, int sum) {
    BinaryTree<int> tree(rep);
    tree.Print();
    std::vector< std::vector<int> > result = PathSum(tree.GetRoot(), sum);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }
}

int main() {
    Test("5 4 11 7 $ $ 2 $ $ $ 8 13 $ $ 4 5 $ $ 1 $ $", 22);
    return 0;
}
