/**
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 * http://oj.leetcode.com/problems/word-break-ii/
 */

#include <iostream>
#include <string>
#include <set>
#include <vector>

void WordBreak(const std::string &s, int start, const std::set<std::string> &dict, 
               std::vector<bool> &is_breakable, std::vector<std::string> &path,
               std::vector<std::string> &result) {
    if (start == s.length()) {
        std::string tmp = path[0];
        for (int i = 1; i < path.size(); i++)
            tmp += " " + path[i];
        result.push_back(tmp);
    } else {
        for (int i = start; i < s.length(); i++) {
            if (!is_breakable[i + 1])
                continue;
            std::string cur(s.begin() + start, s.begin() + i + 1);
            if (dict.count(cur)) {
                path.push_back(cur);
                int size_before = result.size();
                WordBreak(s, i + 1, dict, is_breakable, path, result);
                int size_after = result.size();
                if (size_before == size_after)
                    is_breakable[i + 1] = false;
                path.pop_back();
            }
        }
    }
}

std::vector<std::string> WordBreak(const std::string &s, const std::set<std::string> &dict) {
    std::vector<std::string> path, result;
    if (!s.empty()) {
        std::vector<bool> is_breakable(s.length() + 1, true);
        WordBreak(s, 0, dict, is_breakable, path, result);
    }
    return result;
}

void Test(const std::string &str, const std::set<std::string> &dict) {
    std::cout << "Input:" << str << std::endl;
    std::vector<std::string> result = WordBreak(str, dict);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;
}

int main() {
    std::string a = "catsanddog";
    std::string A1[] = {"cat", "cats", "and", "sand", "dog"};
    std::set<std::string> dict;
    for (int i = 0 ; i < sizeof(A1) / sizeof(std::string); i++)
        dict.insert(A1[i]);
    Test(a, dict);

    dict.clear();
    std::string b = "aaaaaaaa";
    std::string A2[] = {"aa", "aaa", "aaaa"};
    for (int i = 0 ; i < sizeof(A2) / sizeof(std::string); i++)
        dict.insert(A2[i]);
    Test(b, dict);

    std::string c = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    dict.insert("a");
    dict.insert("aa");
    dict.insert("aaa");
    dict.insert("aaaa");
    dict.insert("aaaaa");
    dict.insert("aaaaaa");
    dict.insert("aaaaaaa");
    dict.insert("aaaaaaaa");
    dict.insert("aaaaaaaaa");
    dict.insert("aaaaaaaaaa");
    Test(c, dict);
    return 0;
}
