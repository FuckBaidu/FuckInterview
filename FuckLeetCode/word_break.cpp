/**
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a
 * space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 * http://oj.leetcode.com/problems/word-break/
 */

#include <assert.h>
#include <string>
#include <set>
#include <vector>

bool WordBreak(const std::string &s, const std::set<std::string> &dict) {
    if (s.empty())
        return false;
    std::vector<bool> is_breakable(s.length());
    for (int i = 0; i < s.length(); i++) {
        if (dict.count(s.substr(0, i + 1))) {
            is_breakable[i] = true;
        } else {
            is_breakable[i] = false;
            for (int j = 1; j <= i; j++) {
                if (is_breakable[j - 1] && dict.count(s.substr(j, i - j + 1))) {
                    is_breakable[i] = true;
                    break;
                }
            }
        }
    }
    return is_breakable.back();
}

int main() {
    std::string a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::set<std::string> dict;
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
    assert(WordBreak(a, dict) == false);

    dict.clear();
    std::string b = "acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb"; 
    std::string array[] = {"abbcbda","cbdaaa","b","dadaaad","dccbbbc","dccadd","ccbdbc","bbca","bacbcdd","a","bacb","cbc","adc","c","cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb","bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d","cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc","bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb","ab","aaaaa","acba","abbb"};
    for (int i = 0 ; i < sizeof(array) / sizeof(std::string); i++)
        dict.insert(array[i]);
    assert(WordBreak(b, dict) == true);
    return 0;
}
