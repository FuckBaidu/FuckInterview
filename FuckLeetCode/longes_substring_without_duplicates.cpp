/*
 *Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
#include <string>
#include <vector>
#include <assert.h>
int LengthOfLongestSubstring(const std::string &s) {
    int max = 0, begin = 0;
    std::vector<int> index(256, -1);
    for (int end = 0; end < s.length(); end++) {
        if (index[s[end]] != -1) {
            // invalid all indexes of characters between begin and index[s[end]]
            while (begin <= index[s[end]]) {
                index[s[begin]] = -1;
                begin++;
            }
        }
        index[s[end]] = end;
        int cur = end - begin + 1;
        if (max < cur)
            max = cur;
    }
    return max;
}

int main() {
    assert(LengthOfLongestSubstring("abcabcbb") == 3);
    assert(LengthOfLongestSubstring("bbbbb") == 1);
    assert(LengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") == 12);
    return 0;
}
