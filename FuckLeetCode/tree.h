#ifndef  __UTIL_H_
#define  __UTIL_H_
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <deque>
#include <iomanip>

template <class T>
struct Node {
    Node *left;
    Node *right;
    Node *parent;
    Node *sibling;
    T value;
    Node(T _value) : left(NULL), right(NULL), parent(NULL), sibling(NULL), value(_value) { }
};

template <class T>
class BinarySearchTree {
public:
    BinarySearchTree() : _root(NULL) { }
    ~BinarySearchTree() {
        if (!_root)
            DeleteTree(_root);
    }

    BinarySearchTree(BinarySearchTree &other) {
        _Assign(other);
    }

    void Insert(T value) {
        Node<T> *node = new Node<T>(value);
        if (_root) {
            Node<T> *cur = _root, *parent = NULL;
            while (cur != NULL) {
                parent = cur;
                if (value < cur->value)
                    cur = cur->left;
                else
                    cur = cur->right;
            }
            node->parent = parent;
            if (value < parent->value)
                parent->left = node;
            else
                parent->right = node;
        } else {
            _root = node;
        }
    }

    Node<T>* Search(T value) {
        Node<T> *cur = _root;
        while (cur) {
            if (value == cur->value)
                break;
            else if (value < cur->value)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return cur;
    }

    void Delete(Node<T> *node) {
        if (!node)
            return;
        Node<T> *to_delete = node;
        if (node->left && node->right) {
            Node<T> *cur = NULL;
            cur = node->left;
            while (cur->right)
                cur = cur->right;
            node->value = cur->value;
            to_delete = cur;
        }

        Node<T> *parent = to_delete->parent;
        Node<T> *new_child = to_delete->left? to_delete->left : to_delete->right;
        if (parent) {
            if (to_delete == parent->left)
               parent->left = new_child;
            else
               parent->right = new_child;
        }
        if (new_child)
            new_child->parent = parent;
        delete to_delete;
    }

    void DeleteTree(Node<T> *root) {
        if (root->left)
            DeleteTree(root->left);
        if (root->right)
            DeleteTree(root->right);
        delete root;
        if (root == _root)
            _root = NULL;
    }
    
    int GetHeight() {
        return _GetHeight(_root);
    }

    void Print() {
        std::deque<Node<T>*> cur_nodes;
        cur_nodes.push_back(_root);
        int height = GetHeight();
        // The lenth of underline before node:"___10___", branch_len is 3;
        int branch_len = (1 << height) - 2;
        // Starting space to the first node to print of each level 
        // (for the left most node of each level only)
        int start_len = 0;
        // Distance between nodes
        int node_space_len = (1 << (height + 1)) + 2;
        for (int h = 1; h <= height; h++) {
            node_space_len = (node_space_len >> 1) + 1;
            branch_len = (branch_len >> 1) - 1;
            start_len = branch_len + 2;
            int num_nodes = 1 << (h - 1);
            //print branches and nodes
            typename std::deque<Node<T>*>::const_iterator iter = cur_nodes.begin();
            for (int i = 0; i < num_nodes; i++, ++iter) {
                if (h != height) {
                    if (i == 0)
                        std::cout << std::setw(start_len) << "";
                    else
                        std::cout << std::setw(node_space_len) << "";
                    if (*iter && (*iter)->left)
                        std::cout << std::setfill('_');
                    else
                        std::cout << std::setfill(' ');
                    // Add 2 is for the width of node' value
                    std::cout << std::setw(branch_len + 2);
                    if (*iter)
                        std::cout << (*iter)->value;
                    else
                        std::cout << "";
                    if (*iter && (*iter)->right)
                        std::cout << std::setfill('_');
                    else
                        std::cout << std::setfill(' ');
                    std::cout << std::setw(branch_len) << "";
                    //reset
                    std::cout << std::setfill(' ');
                } else {
                    if (i == 0)
                        std::cout << std::setw(2) << "";
                    else
                        std::cout << std::setw(4) << "";
                    if (*iter)
                        std::cout << (*iter)->value;
                    else
                        std::cout << "";
                }
            }
            std::cout << std::endl;
            //print arms
            if (h != height) {
                iter = cur_nodes.begin();
                for (int i = 0; i < num_nodes; i++, iter++) {
                    if (i == 0)
                        std::cout << std::setw(start_len - 1) << "";
                    else
                        std::cout << std::setw(node_space_len - 2) << "";
                    if (*iter && (*iter)->left)
                        std::cout << '/';
                    else
                        std::cout << ' ';
                    std::cout << std::setw(2 * branch_len + 2) << "";
                    if (*iter && (*iter)->right)
                        std::cout << '\\';
                    else
                        std::cout << ' ';
                }
                std::cout << std::endl;
            }
            for (int i = 0; i < num_nodes; i++) {
                Node<T> *cur = cur_nodes.front();
                cur_nodes.pop_front();
                if (cur) {
                    cur_nodes.push_back(cur->left);
                    cur_nodes.push_back(cur->right);
                } else {
                    cur_nodes.push_back(NULL);
                    cur_nodes.push_back(NULL);
                }
            }
        }
    }

    void PrintByLevel() {
        if (!_root)
            return;

        std::queue< Node<T>* > queue;
        queue.push(_root);
        Node<T> *last_cur_level = _root;
        while (!queue.empty()) {
            Node<T>* cur = queue.front();
            std::cout << cur->value;
            queue.pop();
            if (cur->left != NULL)
                queue.push(cur->left);
            if (cur->right != NULL)
                queue.push(cur->right);
            if (cur == last_cur_level) {
                std::cout << std::endl;
                if (!queue.empty())
                    last_cur_level = queue.back();
            }
        }
    }

    void LinkSibling() {
        if (!_root)
            return;

        std::queue< Node<T>* > queue;
        queue.push(_root);
        Node<T> *last = _root, *head = NULL;
        while (!queue.empty()) {
            Node<T>* cur = queue.front();
            queue.pop();
            if (head != NULL) {
                head->sibling = cur;
            }
            head = cur;
            if (cur->left != NULL)
                queue.push(cur->left);
            if (cur->right != NULL)
                queue.push(cur->right);
            if (cur == last) {
                head = NULL;
                if (!queue.empty())
                    last = queue.back();
            }
        }
    }

    void PrintBySibling() {
        if (!_root)
            return;
        LinkSibling();
        Node<T> *head = _root;
        while (head) {
            Node<T>* cur = head;
            while (cur) {
                std::cout << cur->value;
                cur = cur->sibling;
            }
            std::cout << std::endl;
            head = head->left;
        }
    }

    Node<T> *GetRoot() {
        return _root;
    }

    BinarySearchTree& operator=(const BinarySearchTree &other) {
        if (this != &other) {
            _Assign(other);
        }
        return *this;
    }

private:
    int _GetHeight(Node<T> *node) {
        int left_height = node->left? _GetHeight(node->left) : 0;
        int right_height = node->right? _GetHeight(node->right) : 0;
        return std::max(left_height, right_height) + 1;
    }

    void _Print(Node<T> *root, int num_spaces) {
        if (!root)
            return;

        if (root->right)
            _Print(root->right, num_spaces + 5);
        for (int i = 0; i < num_spaces; i++)
            std::cout << " ";
        std::cout << root->value << std::endl;
        if (root->left)
            _Print(root->left, num_spaces + 5);
    }

    void _Assign(const BinarySearchTree &other) {
        DeleteTree(_root);
        _root = new Node<T>(*other._root);
        std::queue< Node<T>* > queue;
        queue.push(_root);
        while (!queue.empty()) {
            Node<T> *cur = queue.front();
            queue.pop();
            if (cur->left) {
                cur->left = new Node<T>(*cur->left);
                queue.push(cur->left);
            }
            if (cur->right) {
                cur->right = new Node<T>(*cur->right);
                queue.push(cur->right);
            }
        }
    }

    Node<T> *_root;
};
#endif  //__UTIL_H_
