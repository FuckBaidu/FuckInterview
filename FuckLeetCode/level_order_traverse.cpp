/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
 *For example:
 *Given binary tree {3,9,20,#,#,15,7},
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *return its zigzag level order traversal as:
 *[
 *  [3],
 *  [20,9],
 *  [15,7]
 *]
 */
#include <stack>
#include "tree.h"

std::vector< std::vector<int> > LevelOrderTraverse(Node<int> *root) {
    std::vector<int> cur_result;
    std::vector< std::vector<int> > results;
    if (root) {
        std::queue<Node<int>*> cur_level, next_level;
        cur_level.push(root);
        while (!cur_level.empty()) {
            Node<int> *cur = cur_level.front();
            cur_level.pop();
            cur_result.push_back(cur->value);
            if (cur->left)
                next_level.push(cur->left);
            if (cur->right)
                next_level.push(cur->right);
            if (cur_level.empty()) {
                std::swap(cur_level, next_level);
                results.push_back(cur_result);
                cur_result.clear();
            }
        }
    }
    return results;
}

int GetHeight(Node<int> *node) {
    if (!node)
        return 0;
    int left_height = (node->left) ? GetHeight(node->left) : 0;
    int right_height = (node->right) ? GetHeight(node->right) : 0;
    return std::max(left_height, right_height) + 1;
}

void TraverseLevel(Node<int> *node, int level, std::vector<int> &result) {
    if (level == 1) {
        result.push_back(node->value);
    } else {
        if (node->left)
            TraverseLevel(node->left, level - 1, result);
        if (node->right)
            TraverseLevel(node->right, level - 1, result);
    }
}

std::vector< std::vector<int> > DFSTraverse(Node<int> *root) {
    std::vector<int> cur_result;
    std::vector< std::vector<int> > results;
    int height = GetHeight(root);
    for (int i = 1; i <= height; i++) {
        TraverseLevel(root, i, cur_result);
        results.push_back(cur_result);
        cur_result.clear();
    }
    return results;
}

std::vector< std::vector<int> > ZigzagLevelOrderTraverse(Node<int> *root) {
    std::vector<int> cur_result;
    std::vector< std::vector<int> > results;
    if (root) {
        bool is_left_to_right = true;
        std::stack<Node<int>*> cur_level, next_level;
        cur_level.push(root);
        while (!cur_level.empty()) {
            Node<int> *cur = cur_level.top();
            cur_level.pop();
            cur_result.push_back(cur->value);
            if (is_left_to_right) {
                if (cur->left)
                    next_level.push(cur->left);
                if (cur->right)
                    next_level.push(cur->right);
            } else {
                if (cur->right)
                    next_level.push(cur->right);
                if (cur->left)
                    next_level.push(cur->left);
            }
            if (cur_level.empty()) {
                std::swap(cur_level, next_level);
                results.push_back(cur_result);
                cur_result.clear();
                is_left_to_right = !is_left_to_right;
            }
        }
    }
    return results;
}

typedef std::vector< std::vector<int> > (*Func)(Node<int> *root);
int main() {
    std::string rep = "3 9 $ $ 20 15 17 $ $ $ 7 $ $";
    BinaryTree<int> tree(rep);
    tree.Print();
    Func funcs[] = {LevelOrderTraverse, ZigzagLevelOrderTraverse, DFSTraverse};
    for (int i = 0; i < 3; i++) {
        std::vector< std::vector<int> > results;
        results = funcs[i](tree.GetRoot());
        for (int i = 0; i < results.size(); i++) {
            std::cout << "[";
            for (int j = 0; j < results[i].size(); j++)
                std::cout << results[i][j] << (j == results[i].size() - 1 ? "" : ",");
            std::cout << "]";
            std::cout << std::endl;
        }
    }
    return 0;
}
