/**
 * 4.6 in <Crack the code interview>.
 * Degine an algorithm to write code to find the first common ancestor of two nodes
 * in a binary tree.This is not necessarily a binary search tree.
 */
#include "tree.h"

template <class T>
class Base {
public:
    virtual Node<T> *FindFirstCommonAncestor(BinarySearchTree<T> *tree,
            Node<T> *node1, Node<T> *node2) = 0;
};

//Binary Search Tree
template <class T>
class Derived1 : public Base<T> {
public:
    virtual Node<T> *FindFirstCommonAncestor(BinarySearchTree<T> *tree,
            Node<T> *node1, Node<T> *node2) {
        printf("Assume the tree is a binary search tree\n");
        if (!node1 || !node2)
            return NULL;
        Node<T> *cur = tree->GetRoot(), *parent = NULL;
        if (!cur)
            return NULL;
        while (1) {
            parent = cur;
            if (cur != node1 && cur != node2) {
                if (cur->value >= node1->value && cur->value >= node2->value)
                    cur = cur->left;
                else if (cur->value <= node1->value && cur->value <= node2->value)
                    cur = cur->right;
                else
                    break;
            } else {
                break;
            }
        }

        return parent;
    }
};

template <class T>
static inline int Distance(Node<T> *node, Node<T> *ancestor) {
    int count = 0;
    Node<T> *cur = node;
    while (cur != ancestor) {
        count++;
        cur = cur->parent;
    }
    return count;
}

template <class T>
class Derived2 : public Base<T> {
public:
    virtual Node<T> *FindFirstCommonAncestor(BinarySearchTree<T> *tree,
            Node<T> *node1, Node<T> *node2) {
        printf("Assume each node in the tree has a parent link\n");
        if (!node1 || !node2)
            return NULL;
        Node<T> *root = tree->GetRoot();
        if (!root)
            return NULL;
        int diff = Distance(node1, root) - Distance(node2, root);
        Node<T> *cur;
        if (diff < 0)
            cur = node2;
        else
            cur = node1;
        for (int i = 0; i < std::abs(diff); i++)
            cur = cur->parent;
        if (diff < 0)
            node2 = cur;
        else
            node1 = cur;
        while (node1 != node2) {
            node1 = node1->parent;
            node2 = node2->parent;
        }

        return node1;
    }
};

//Not a Binary Search Tree, and has no parent link
template <class T>
class Derived3 : public Base<T> {
public:
    virtual Node<T> *FindFirstCommonAncestor(BinarySearchTree<T> *tree,
            Node<T> *node1, Node<T> *node2) {
        printf("Neither the tree is a binary search tree nor the nodes in the tree have a parent link\n");
        if (!node1 || !node2)
            return NULL;
        Node<T> *root = tree->GetRoot(), *result = NULL;
        _FindFirstCommonAncestor(root, node1, node2, &result);
        return result;
    }

private:
    bool _FindFirstCommonAncestor(Node<T> *cur, Node<T> *node1, Node<T> *node2,
            Node<T> **result) {
        if (!cur)
            return false;
        if (*result != NULL)
            return true;
        bool find_left = _FindFirstCommonAncestor(cur->left, node1, node2, result);
        if (*result != NULL)
            return true;
        bool find_right = _FindFirstCommonAncestor(cur->right, node1, node2, result);
        if (*result != NULL)
            return true;
        bool find_cur = (cur == node1 || cur == node2);
        if (find_left && find_right || find_left && find_cur || find_right && find_cur)
            *result = cur;
        return find_left || find_right || find_cur;
    }
};

template <class T>
void InsertMinimumBinarySearchTree(int *array, int low, int high, BinarySearchTree<T> &tree) {
    if (low <= high) {
        int mid = (low + high) / 2;
        tree.Insert(array[mid]);
        InsertMinimumBinarySearchTree(array, low, mid - 1, tree);
        InsertMinimumBinarySearchTree(array, mid + 1, high, tree);
    }
}

void Test() {
    int array[15];
    for (int i = 0; i < 15; i++)
        array[i] = i + 1;
    BinarySearchTree<int> tree;
    InsertMinimumBinarySearchTree(array, 0, 14, tree);
    tree.Print();
    Base<int> *algo[3];
    algo[0] = new Derived1<int>();
    algo[1] = new Derived2<int>();
    algo[2] = new Derived3<int>();
    std::pair<int, int> pairs[5];
    pairs[0] = std::make_pair(13, 15);
    pairs[1] = std::make_pair(3, 7);
    pairs[2] = std::make_pair(2, 10);
    pairs[3] = std::make_pair(5, 9);
    pairs[4] = std::make_pair(1, 4);
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 3; i++) {
            Node<int> *node1 = tree.Search(pairs[j].first);
            Node<int> *node2 = tree.Search(pairs[j].second);
            Node<int> *ancestor = algo[i]->FindFirstCommonAncestor(&tree, node1, node2);
            printf("The ancestor of %d and %d is %d(use algorithm %d)\n", node1->value, node2->value, ancestor->value, i);
        }
    }
}

int main() {
    Test();
    return 0;
}
