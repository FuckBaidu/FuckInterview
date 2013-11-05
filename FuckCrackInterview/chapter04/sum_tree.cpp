/**
 * 4.8 in <Crack the code interview>.
 * You are given a binary tree in which each node contains a value. Design an algorithm
 * to print all paths which sum up to that value.Note that it does not have to start from
 * the root
 */
#include <time.h>
#include "tree.h"
void PrintPath(Node<int> *node, std::vector<int> &path, int sum) {
    if (!node)
        return;
    int end = path.size();
    path.push_back(node->value);
    int start = end;
    int cur_sum = 0;
    for ( ; start >= 0; start--) {
        cur_sum += path[start];
        if (cur_sum > sum)
            break;
        if (cur_sum == sum) {
            std::cout << "Found path: ";
            for (int i = start; i <= end; i++)
                std::cout << path[i] <<" ";
            std::cout << std::endl;
            break;
        }
    }

    PrintPath(node->left, path, sum);
    if (path.size() > end + 1)
        path.erase(path.begin() + end + 1, path.end());
    PrintPath(node->right, path, sum);
}

void PrintPath(BinarySearchTree<int> &tree, int sum) {
    std::vector<int> vec;
    PrintPath(tree.GetRoot(), vec, sum);
}

int main() {
    srand(time(NULL));
    BinarySearchTree<int> tree;
    for (int i = 0; i < 15; i++)
        tree.Insert(rand() % 10);
    tree.Print();
    std::cout << "Sum equals 0" << std::endl;
    PrintPath(tree, 0);
    std::cout << "Sum equals 7" << std::endl;
    PrintPath(tree, 7);
    std::cout << "Sum equals 19" << std::endl;
    PrintPath(tree, 19);
    std::cout << "Sum equals 9" << std::endl;
    PrintPath(tree, 9);
    return 0;
}
