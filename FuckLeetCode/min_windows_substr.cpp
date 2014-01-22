/*
 * Given a string S and a string T, find the minimum window in S which will contain all the
 * characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique
 * minimum window in S.
 */
#include <string>
#include <vector>
#include <iostream>
std::string MinWindow(const std::string &S, const std::string &T) {
    std::vector<int> need_to_find(256, 0), has_found(256, 0);
    for (int i = 0; i < T.length(); i++)
        need_to_find[T[i]]++;
    int start = -1, count = 0;
    std::pair<int, int> min(0, 0);
    for (int end = 0; end < S.length(); end++) {
        if (need_to_find[S[end]] == 0)
            continue;
        if (start == -1)
            start = end;
        has_found[S[end]]++;
        if (has_found[S[end]] <= need_to_find[S[end]]) {
            count++;
        } else if (S[end] == S[start]) {
            while (need_to_find[S[start]] == 0 || has_found[S[start]] > need_to_find[S[start]]) {
                has_found[S[start]]--;
                start++;
            }
        }
        
        if (count == T.length()) {
            if (min.second == 0 || min.second > end - start + 1) {
                min.first = start;
                min.second = end - start + 1;
            }
        }
    }
    return S.substr(min.first, min.second);
}

void Test(const std::string &S, const std::string &T) {
    std::cout << "S is " << S << std::endl;
    std::cout << "T is " << T << std::endl;
    std::cout << "min windows is " << MinWindow(S, T) << std::endl;
}

int main() {
    Test("ADOBECODEBANC", "ABC");
    Test("SADOBECODEBANC", "ABC");
    Test("SADOBECODEBANC", "ABBC");
    Test("SADOBECODEBANC", "ABCF");
    return 0;
}
