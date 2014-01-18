/*
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting
 * some (can be none) of the characters without disturbing the relative positions of the remaining
 * characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 */
#include <string>
#include <vector>
#include <assert.h>
int NumDistinct(const std::string &S, const std::string &T) {
    if (S.empty())
        return 0;
    if (T.empty())
        return 1;
    std::vector<int> cur(S.length()), prev(S.length());
    cur[0] = S[0] == T[0];
    for (int i = 1; i < S.length(); i++)
        cur[i] = cur[i - 1] + (S[i] == T[0] ? 1 : 0);
   for (int i = 1; i < T.length(); i++) {
       std::swap(cur, prev);
       for (int j = 0; j < i; j++)
           cur[j] = 0;
       for (int j = i; j < S.length(); j++) {
           cur[j] = cur[j - 1];
           if (S[j] == T[i])
               cur[j] += prev[j - 1];
       }
   }
   return cur.back();
}

int main() {
    assert(NumDistinct("rabbbit", "rabbit") == 3);
    assert(NumDistinct("ababc", "abc") == 3);
    return 0;
}
