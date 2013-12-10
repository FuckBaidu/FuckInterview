/*
 * Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree
 * to a file is called ?serialization? and reading back from the file to reconstruct the exact same
 * binary tree is ?deserialization?.
 */
#include "tree.h"
int main() {
    std::string str = "30 10 50 $ $ $ 20 45 $ $ 35 $ $";
    BinaryTree<int> tree(str);
    tree.Print();
    std::string rep = tree.Serialize();
    std::cout << rep << std::endl;
    BinaryTree<int> new_tree(rep);
    tree.Print();
    std::cout << new_tree.Serialize() << std::endl;
    return 0;
}
