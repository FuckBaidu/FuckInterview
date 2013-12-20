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

std::vector<std::string> WordBreak(const std::string &s, const std::set<std::string> &dict, int start, std::vector<bool> &is_breakable) {
    std::vector<std::string> result;
    std::string substr = s.substr(start, s.length() - start);
    if (dict.count(substr))
        result.push_back(substr);
    for (int i = start + 1; i < s.length(); i++) {
        substr = s.substr(start, i - start);
        if (dict.count(substr) && is_breakable[i]) {
            std::vector<std::string> tmp = WordBreak(s, dict, i, is_breakable);
            if (tmp.empty()) {
                is_breakable[i] = false;
            } else {
                for (int j = 0; j < tmp.size(); j++)
                    result.push_back(substr + " " + tmp[j]);
            }
        }
    }
    return result;
}

std::vector<std::string> WordBreak(const std::string &s, const std::set<std::string> &dict) {
    // Record whether the substr(i, end) can be broken into words to eliminate the search space
    std::vector<bool> is_breakable(s.length(), true); 
    return WordBreak(s, dict, 0, is_breakable);
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
