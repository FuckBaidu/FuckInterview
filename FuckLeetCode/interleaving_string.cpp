/*
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */
#include <assert.h>
#include <string>
#include <vector>

bool IsInterleave(const std::string &s1, const std::string &s2, const std::string &s3) {
    if (s1.length() + s2.length() != s3.length())
        return false;
        std::vector<bool> prev(s2.length() + 1), cur(s2.length() + 1);
        cur[0] = true;
        for (int i = 1; i < cur.size(); i++)
            cur[i] = s2[i - 1] == s3[i - 1];
        for (int i = 0; i < s1.length(); i++) {
            std::swap(cur, prev);
            cur[0] = s1[i] == s3[i] ? prev[0] : false;
            for (int j = 0; j < s2.length(); j++) {
                int k = i + j + 1;
                cur[j + 1] = false;
                if (s3[k] == s1[i] && prev[j + 1] || s3[k] == s2[j] && cur[j])
                    cur[j + 1] = true;
            }
        }
    return cur.back();
}

int main() {
    assert(IsInterleave("aabcc", "dbbca", "aadbbcbcac"));
    assert(!IsInterleave("aabcc", "dbbca", "aadbbbaccc"));
    assert(IsInterleave("aabcc", "dbbca", "aadbcbbcac"));
    return 0;
}
