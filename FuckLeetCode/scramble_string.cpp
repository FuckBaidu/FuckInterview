/*
 *Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */
#include <assert.h>
#include <vector>
#include <string>
bool IsAnagram(const std::string &s1, const std::string &s2) {
    if (s1.length() != s2.length())
        return false;
    std::vector<int> count1(26, 0), count2(26, 0);
    for (int i = 0; i < s1.length(); i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (count1[i] != count2[i])
            return false;
    return true;
}

bool IsScramble(const std::string &s1, const std::string &s2) {
    if (!IsAnagram(s1, s2))
        return false;
    std::vector< std::vector< std::vector<bool> > > result(s1.length() + 1);
    for (int i = 0; i <= s1.length(); i++) {
        result[i].resize(s1.length());
        for (int j = 0; j < s1.length(); j++)
            result[i][j].resize(s1.length());
    }
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s1.length(); j++) {
            result[0][i][j] = 1;
            result[1][i][j] = (s1[i] == s2[j]); 
        }
    }
    for (int len = 2; len <= s1.length(); len++) {
        for (int i = 0; i <= s1.length() - len; i++) {
            std::string substr1 = s1.substr(i, len);
            for (int j = 0; j <= s1.length() - len; j++) {
                std::string substr2 = s2.substr(j, len);
                if(substr1 == substr2) {
                    result[len][i][j] = 1;
                } else {
                    result[len][i][j] = 0;
                    for (int k = 1; k < len; k++) {
                        if (result[k][i][j] && result[len - k][i + k][j + k]
                            || result[k][i][j + len - k] && result[len - k][i + k][j]) {
                            result[len][i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return result[s1.length()][0][0];
}

bool IsScramble1(const std::string &s1, const std::string &s2) {
    if (s1 == s2)
        return true;
    if (s1.length() != s2.length())
        return false;
    std::vector<int> count1(26, 0), count2(26, 0);
    for (int i = 0; i < s1.length(); i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (count1[i] != count2[i])
            return false;
    for (int i = 1; i < s1.length(); i++) {
        if (IsScramble1(s1.substr(0, i), s2.substr(0, i))
            && IsScramble1(s1.substr(i), s2.substr(i)))
            return true;
        if (IsScramble1(s1.substr(0, i), s2.substr(s1.length() - i))
            && IsScramble1(s1.substr(i), s2.substr(0, s1.length() - i)))
            return true;
    }
    return false;
}

int main() {
    assert(IsScramble1("aa", "aa"));
    assert(IsScramble("aa", "aa"));
    assert(!IsScramble("abcd", "bdac"));
    assert(!IsScramble1("abcd", "bdac"));
    return 0;
}
