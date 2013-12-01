/**
 * 20.13 in <Crack the code interview>.
 * Given a dictonary of millions of words, give an algorithm to find the largest
 * possible rectangle of letters such that each row forms a word(reading from
 * left to right) and every column forms a word(reading from up to bottom)
 */
#include <ext/hash_set>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#define N 26

struct Node {
    char data;
    bool is_terminate;
    Node *child[N];
    Node(char _data) : data(_data), is_terminate(false) {
        for (int i = 0; i < N; i++)
            child[i] = NULL;
    }
};

class TrieTree {
public:
    TrieTree() : _root(NULL) {
        _root = new Node(0);
    }

    ~TrieTree() {
        //_DeleteSubTree(_root);
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

    const Node* Search(const std::string &str) {
        Node *cur = _root;
        for (int i = 0; i < str.length(); i++) {
            cur = cur->child[str[i] - 'a'];
            if (!cur)
                break;
        }
        return cur;
    }

    const Node* GetRoot() const{
        return _root;
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

struct Rectangle {
    int height;
    int width;

    Rectangle(int _height, int _width) : height(_height), width(_width) { }

    bool operator<(const Rectangle &other) const {
        return height * width < other.height * other.width;
    }
};

struct Hash {
    size_t operator()(const std::string& s) const {
        unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;

        const char *str = s.c_str();
        while (*str)
        {
            hash = hash * seed + (*str++);
        }

        return (hash & 0x7FFFFFFF);
    }
};

bool IsValidRect(const Rectangle &rect, const TrieTree &trie, int row_index, char **matrix) {
    for (int i = 0; i < rect.width; i++) {
        const Node *cur = trie.GetRoot();
        for (int j = 0; j <= row_index; j++) {
            cur = cur->child[matrix[j][i] - 'a'];
            if (!cur)
                return false;
            if (j == rect.height - 1 && !cur->is_terminate)
                return false;
        }
    }
    return true;
}

bool FillNextRow(const Rectangle &rect, const std::vector<std::string> &words,
                 const TrieTree &trie, int row_index, bool *used, char **matrix) {
    if (row_index == rect.height) {
        return true;
    } else {
        for (int i = 0; i < words.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                memcpy(matrix[row_index], words[i].c_str(), words[i].length());
                    std::cout << std::endl;
                for (int m = 0; m <= row_index ; m++) {
                    for (int n = 0; n < rect.width; n++)
                        std::cout << matrix[m][n] << " ";
                    std::cout << std::endl;
                }
                if (IsValidRect(rect, trie, row_index, matrix)) {
                    if (FillNextRow(rect, words, trie, row_index + 1, used, matrix))
                        return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
}

bool CanMakeRectangle(const Rectangle &rect, const std::vector<std::string> &words,
                      const TrieTree &trie, char **matrix) {
    bool *used = new bool[words.size()];
    memset(used, 0, sizeof(bool) * words.size());
    bool result = FillNextRow(rect, words, trie, 0, used, matrix);
    delete[] used;
    return result;
}

typedef __gnu_cxx::hash_set<std::string, Hash> HashSet;
void PrintLargestWordRectangle(const HashSet &dict) {
    std::priority_queue<Rectangle> rects;
    std::map< int, std::vector<std::string> > words;
    TrieTree trie;
    HashSet::const_iterator iter = dict.begin();
    int max_length = 0;
    for (; iter != dict.end(); iter++) {
        const std::string &str = *iter;
        words[str.length()].push_back(*iter);
        trie.Insert(*iter);
        if (max_length < str.length())
            max_length = str.length();
    }
    char **matrix = new char* [max_length];
    for (int i = 0; i < max_length; i++)
        matrix[i] = new char[max_length];
    for (int i = 1; i <= max_length; i++)
        for (int j = 1; j <= max_length; j++)
            rects.push(Rectangle(i, j));

    while (!rects.empty()) {
        Rectangle rect = rects.top();
        rects.pop();
        if (words.count(rect.height) != 0 && words.count(rect.width) != 0
            && CanMakeRectangle(rect, words[rect.width], trie, matrix)) {
            std::cout << "Found solution:" << std::endl;
            for (int i = 0; i < rect.height; i++) {
                for (int j = 0; j < rect.width; j++)
                    std::cout << matrix[i][j] << " ";
                std::cout << std::endl;
            }
            return;
        }
    }

    for (int i = 0; i < max_length; i++)
        delete[] matrix[i];
    delete[] matrix;
    std::cout << "No solution" << std::endl;
    return;
}

int main() {
    HashSet hash_set;
    hash_set.insert("shit");
    hash_set.insert("fuck");
    hash_set.insert("dude");
    hash_set.insert("word");
    hash_set.insert("list");
    hash_set.insert("hoop");
    hash_set.insert("lamp");
    hash_set.insert("rep");
    hash_set.insert("pond");
    hash_set.insert("heap");
    hash_set.insert("api");
    hash_set.insert("wfts");
    hash_set.insert("tank");
    hash_set.insert("ouah");
    hash_set.insert("tip");
    hash_set.insert("cat");
    hash_set.insert("rcni");
    hash_set.insert("dkkt");
    hash_set.insert("car");
    hash_set.insert("ape");
    PrintLargestWordRectangle(hash_set);
    return 0;
}
