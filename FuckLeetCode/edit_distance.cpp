/*
 *Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

 You have the following 3 operations permitted on a word:

 a) Insert a character
 b) Delete a character
 c) Replace a character
 */

#include <string>
#include <vector>
#include <assert.h>
int MinDistance(const std::string &word1, const std::string &word2) {
    std::vector<int> cur(word2.length() + 1), prev = cur;
    for (int i = 0; i < cur.size(); i++)
        cur[i] = i;
    for (int i = 0; i < word1.length(); i++) {
        std::swap(cur, prev);
        cur[0] = i + 1;
        for (int j = 0; j < word2.length(); j++) {
            if (word1[i] != word2[j]) {
                cur[j + 1] = std::min(prev[j] + 1, prev[j + 1] + 1); // replace & delete word1
                cur[j + 1] = std::min(cur[j + 1], cur[j] + 1);    // delete word2
            } else {
                cur[j + 1] = prev[j];
            }
        }
    }
    return cur.back();
}

int main() {
    assert(MinDistance("abcd", "abed") == 1);
    assert(MinDistance("accd", "accd") == 0);
    assert(MinDistance("accdf", "acdf") == 1);
    return 0;
}
