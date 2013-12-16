#ifndef  __UTIL_H_
#define  __UTIL_H_
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>

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

    void Print() {
       _Print(_root, 0);
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

    void LinkSibling(Node<T> *node) {
        if (!node)
            return;
        if (node->right) {
            Node<T> *sibling_parent = node->sibling, *sibling_child = NULL;
            while (sibling_parent) {
                if (sibling_parent->left) {
                    sibling_child = sibling_parent->left;
                    break;
                }
                if (sibling_parent->right) {
                    sibling_child = sibling_parent->right;
                    break;
                }
                sibling_parent = sibling_parent->sibling;
            }
            node->right->sibling = sibling_child;
            LinkSibling(node->right);
        }

        if (node->left) {
            if (node->right) {
                node->left->sibling = node->right;
            } else {
                Node<T> *sibling_parent = node->sibling, *sibling_child = NULL;
                while (sibling_parent) {
                    if (sibling_parent->left) {
                        sibling_child = sibling_parent->left;
                        break;
                    }
                    if (sibling_parent->right) {
                        sibling_child = sibling_parent->right;
                        break;
                    }
                    sibling_parent = sibling_parent->sibling;
                }
                node->left->sibling = sibling_child;
            }
            LinkSibling(node->left);
        }
    }

    void PrintBySibling() {
        if (!_root)
            return;
        LinkSibling(_root);
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
