/**
 * 4.7 in <Crack the code interview>.
 * You have two very large binary trees: T1 with millions of nodes, and T2 with hundreds of
 * nodes.Create an algorithm to decide if T2 is a subtree of T1
 */
#include "tree.h"
template <class T>
bool IsSubTree(Node<T> *t1, Node<T> *t2, Node<T> *root) {
    if (!t2)
        return true;
    if (!t1)
        return false;

    if (t1->value == t2->value) {
        return IsSubTree(t1->left, t2->left, root)
               && IsSubTree(t1->right, t2->right, root);
    } else {
        if (t2 == root)
            return IsSubTree(t1->left, root, root)
                   || IsSubTree(t1->right, root, root);
        else
            return IsSubTree(t1, root, root);
    }
}

void Test(BinarySearchTree<int> &t1, BinarySearchTree<int> &t2) {
    printf("T1:\n");
    t1.Print();
    printf("T2:\n");
    t2.Print();
    bool result = IsSubTree(t1.GetRoot(), t2.GetRoot(), t2.GetRoot());
    if (result)
        printf("T2 is a subtree of T1\n");
    else
        printf("T2 is not a subtree of T1\n");
}

template <class T>
void InsertMinimumBinarySearchTree(int *array, int low, int high, BinarySearchTree<T> &tree) {
    if (low <= high) {
        int mid = (low + high) / 2;
        tree.Insert(array[mid]);
        InsertMinimumBinarySearchTree(array, low, mid - 1, tree);
        InsertMinimumBinarySearchTree(array, mid + 1, high, tree);
    }
}

int main() {
    BinarySearchTree<int> t1, t2, t3;
    int array[15];
    for (int i = 0; i < 15; i++)
        array[i] = i + 1;
    InsertMinimumBinarySearchTree(array, 0, 14, t1);
    t2.Insert(8);
    t2.Insert(5);
    t2.Insert(2);
    t2.Insert(1);
    t2.Insert(3);
    t2.Insert(12);
    Test(t1, t2);
    t3.Insert(8);
    t3.Insert(4);
    t3.Insert(2);
    t3.Insert(1);
    t3.Insert(3);
    t3.Insert(12);
    Test(t1, t3);
    BinarySearchTree<int> t4, t5;
    t4.Insert(8);
    t4.Insert(8);
    t4.Insert(9);
    t5.Insert(8);
    t5.Insert(9);
    Test(t4, t5);
    BinarySearchTree<int> t6, t7;
    t6.Insert(1);
    t6.Insert(5);
    t6.Insert(8);
    t7.Insert(1);
    t7.Insert(8);
    Test(t6, t7);
    return 0;
}
