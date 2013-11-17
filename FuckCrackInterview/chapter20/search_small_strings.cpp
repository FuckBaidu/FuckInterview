/**
 * 20.8 in <Crack the code interview>.
 * Given a string s and an array of smaller strings T.Design a method to search
 * s for each small string T
 */
#define N 26
#include <vector>
#include <string>
#include <iostream>
struct Node {
    char data;
    std::vector<int> index;
    Node *child[N];
    Node() : data(0) {
        memset(child, 0, sizeof(child));
    }
};

class SuffixTree {
public:
    SuffixTree(const std::string &str) {
        _CreateSuffixTree(str);
    }

    void Insert(const std::string &str, int index) {
        Node *cur = _root;
        for (int i = 0; i< str.length(); i++) {
            if (cur->child[str[i] - 'a'] == NULL)
                cur->child[str[i] - 'a'] = new Node;
            cur = cur->child[str[i] - 'a'];
            cur->index.push_back(index);
            cur->data = str[i];
        }
    }

    void Search(const std::string &str, std::vector<int> &position) {
        Node *cur = _root;
        for (int i = 0; i < str.length(); i++) {
            if (cur->child[str[i] - 'a'] == NULL)
                return;
            else
                cur = cur->child[str[i] - 'a'];
        }
        position.insert(position.end(), cur->index.begin(), cur->index.end());
    }

private:
    void _CreateSuffixTree(const std::string &str) {
        _root = new Node();
        for (int i = 0; i < str.length(); i++)
            Insert(str.substr(i), i);
    }
    Node *_root;
};

void Test() {
    const char* str = "mississippi";
    SuffixTree tree(str);
    const std::string strs[] = {"is", "sip" , "hi", "sis"};
    for (int i = 0; i < 4; i++) {
        std::vector<int> position;
        tree.Search(strs[i], position);
        if (position.empty()) {
            std::cout << "Not Found " << strs[i] << " in " << str << std::endl;
        } else {
            std::cout << "Found " << strs[i] << " in " << str << ":";
            for (int j = 0; j < position.size(); j++)
                std::cout << position[j] << " ";
            std::cout << std::endl;
        }
    }
}

int main() {
    Test();
    return 0;
}
