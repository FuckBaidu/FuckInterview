#define N 26
#include <string.h>
#include <string>
#include <iostream>
struct Node {
    char data;
    bool is_terminate;
    Node *child[N];
    Node(char _data) : data(_data), is_terminate(false) {
        memset(child, 0, sizeof(child));
    }
};

class TrieTree {
public:
    TrieTree() {
        _root = new Node(0);
    }

    ~TrieTree() {
        _DeleteSubTree(_root);
    }

    void Insert(const std::string &str) {
        Node *cur = _root;
        for (int i = 0; i < str.length(); i++) {
            if (cur->child[str[i] - 'a'] == NULL)
                cur->child[str[i] - 'a'] = new Node(str[i]);
            cur = cur->child[str[i] - 'a'];
        }
        cur->is_terminate = true;
    }

    void Traverse() {
        std::string output;
        _Traverse(_root, output);
    }

private:
    void _DeleteSubTree(Node *node) {
        if (node == NULL)
            return;
        for (int i = 0; i < N; i++)
            if (node->child[i])
                _DeleteSubTree(node->child[i]);
        delete node;

    }

    void _Traverse(Node *node, std::string &output) {
        output.push_back(node->data);
        if (node->is_terminate) {
            std::cout << output << std::endl;
        }
        int old_len = output.length();
        for (int i = 0; i < N; i++) {
            if (node->child[i]) {
                if (output.length() > old_len) {
                    output.erase(old_len);
                }
                _Traverse(node->child[i], output);
            }
        }
    }

    Node *_root;
};

int main() {
    TrieTree trie_tree;
    trie_tree.Insert("testertest");
    trie_tree.Insert("testingtester");
    trie_tree.Insert("tester");
    trie_tree.Insert("testing");
    trie_tree.Insert("test");
    trie_tree.Traverse();
    return 0;
}
