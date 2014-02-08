/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum
 * length of S is 1000, and there exists one unique longest palindromic substring.
 */
#include <string>
#include <vector>
#include <assert.h>

std::string Preprocess(const std::string &s) {
    std::string result(1, '*');
    for (int i = 0; i < s.length(); i++) {
        result.push_back(s[i]);
        result.push_back('*');
    }
    return result;
}

std::string LongestPalindrome(const std::string &s) {
    if (s.empty())
        return s;
    std::string p = Preprocess(s);
    std::pair<int, int> longest(0, 0);
    std::vector<int> lens(p.length(), 0);
    int middle = 0, right = 0;
    for (int i = 1; i < p.length(); i++) {
        if (i > right) {
            middle = i;
            right = i;
        }
        lens[i] = std::min(lens[middle - (i - middle)], right - i);
        int new_right = i + lens[i] + 1, new_left = i - lens[i] - 1;
        while (new_right < p.length() && new_left >= 0 && p[new_right] == p[new_left]) {
            lens[i]++;
            new_right++;
            new_left--;
        }
        new_right--;
        if (new_right > right) {
            middle = i;
            right = new_right;
        }
        if (longest.second < lens[i]) {
            longest.first = (i - lens[i]) / 2;
            longest.second = lens[i];
        }
    }
    return s.substr(longest.first, longest.second);
}

int main() {
    assert(LongestPalindrome("aaaaaaaaa") == "aaaaaaaaa");
    assert(LongestPalindrome("abaaba") == "abaaba");
    assert(LongestPalindrome("cabcbabcbabcba") == "abcbabcbabcba");
    return 0;
}
