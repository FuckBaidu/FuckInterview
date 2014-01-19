/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

   For example:
   Given binary tree {3,9,20,#,#,15,7},
       3
      / \
     9  20
       /  \
      15   7
   return its zigzag level order traversal as:
   [
     [3],
     [20,9],
     [15,7]
   ]
 */
#include "tree.h"
#include <stack>

std::vector< std::vector<int> > ZigzagLevelOrder(Node<int> *root) {
    std::vector< std::vector<int> > result;
    if (root) {
        std::stack<Node<int>*> cur, next;
        cur.push(root);
        std::vector<int> cur_level;
        bool left_to_right = true;
        while (!cur.empty()) {
            Node<int> *node = cur.top();
            cur.pop();
            cur_level.push_back(node->value);
            if (left_to_right) {
                if (node->left)
                    next.push(node->left);
                if (node->right)
                    next.push(node->right);
            } else {
                if (node->right)
                    next.push(node->right);    
                if (node->left)
                    next.push(node->left);               
            }
            if (cur.empty()) {
                std::swap(cur, next);
                result.push_back(cur_level);
                cur_level.clear();
                left_to_right = !left_to_right;
            }
        }
    }
    return result;
}

int main() {
    BinaryTree<int> tree("3 9 6 $ $ 4 $ $ 20 15 $ $ 7 $ $");
    tree.Print();
    std::vector< std::vector<int> > result = ZigzagLevelOrder(tree.GetRoot());
    for (int i = 0; i < result.size(); i++) {
        std::cout << "level " << i << ":";
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}
