/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */
#include <string>
#include <vector>
#include <assert.h>

int MinCut(const std::string &s) {
     if (s.empty())
         return 0;
     std::vector< std::vector<bool> > is_palindrome(s.length(), std::vector<bool>(s.length(), false));
    for (int i = 0; i < s.length(); i++) {
        is_palindrome[i][i] = true;
        if (i < s.length() - 1)
            is_palindrome[i][i + 1] = s[i] == s[i + 1];
    }
    for (int len = 3; len <= s.length(); len++) {
        for (int i = 0; i <= s.length() - len ; i++) {
            int j = i + len - 1;
            is_palindrome[i][j] = false;
            if (is_palindrome[i + 1][j - 1] && s[i] == s[j])
                is_palindrome[i][j] = true;
        }
    }
    std::vector<int> min_cuts(s.length(), INT_MAX);
    for (int i = 0; i < s.length(); i++) {
        if (is_palindrome[0][i]) {
            min_cuts[i] = 0;
        } else {
            for (int j = 1; j <= i; j++)
                if (is_palindrome[j][i] && min_cuts[i] > min_cuts[j - 1] + 1)
                    min_cuts[i] = min_cuts[j - 1] + 1;
        }
    }
    return min_cuts.back();
}

int main() {
    assert(MinCut("aab") == 1);
    assert(MinCut("abaaba") == 0);
    assert(MinCut("aaaaba") == 1);
    return 0;
}
