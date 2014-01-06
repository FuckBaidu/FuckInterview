/*
 * find the longest string (or strings) that is a substring (or are substrings) of two or more strings.
 */
#include <string>
#include <vector>
#include <iostream>

std::string LCS(const std::string &s1, const std::string &s2) {
    std::pair<int, int> result(0, 0);
    std::vector<int> cur_len(s2.length() + 1, 0), prev_len = cur_len;
    for (int i = 0; i < s1.length(); i++) {
        std::swap(cur_len, prev_len);
        for (int j = 0; j < s2.length(); j++) {
            cur_len[j + 1] = 0;
            if (s1[i] == s2[j]) {
                cur_len[j + 1] = prev_len[j] + 1;
                if (result.second < cur_len[j + 1]) {
                    result.second = cur_len[j + 1];
                    result.first = i - cur_len[j + 1] + 1;
                }
            }
        }
    }
    return s1.substr(result.first, result.second);
}

void Test(const std::string &s1, const std::string &s2) {
    std::cout << "The longest common sub string of " << s1 << " and "
        << s2 << " is " << LCS(s1, s2) << std::endl;
}

int main() {
    Test("", "");
    Test("", "abc");
    Test("abc", "");
    Test("abc", "ab");
    Test("bc", "abc");
    Test("abedf", "abcedf");
    return 0;
}
