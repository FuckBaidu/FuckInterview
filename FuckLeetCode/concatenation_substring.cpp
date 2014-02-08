/*
 * You are given a string, S, and a list of words, L, that are all of the same length. Find all
 * starting indices of substring(s) in S that is a concatenation of each word in L exactly once and
 * without any intervening characters.
 *
 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 */
#include <string>
#include <vector>
#include <iostream>
#include <map>

std::vector<int> FindSubstring(const std::string &S, const std::vector<std::string> &L) {
    std::vector<int> result;
    if (!S.empty() && !L.empty()) {
        std::map<std::string, int> need_to_find;
        for (int i = 0; i < L.size(); i++)
            need_to_find[L[i]]++;
        int word_len = L[0].length(), total_len = word_len * L.size();
        for (int i = 0; i < word_len; i++) {
            int count = 0;
            std::map<std::string, int> has_found;
            for (int j = i; j < i + total_len; j += word_len) {
                std::string cur = S.substr(j, word_len);
                if (need_to_find.count(cur))
                    if (++has_found[cur] <= need_to_find[cur])
                        count++;
            }
            for (int j = i; j <= (int)S.length() - total_len; j += word_len) {
                if (count == L.size())
                    result.push_back(j);
                // slide the fixed size window to next word
                int k = j + total_len;
                if (k + word_len <= S.length()) {
                    std::string cur = S.substr(j, word_len), next = S.substr(k, word_len);
                    if (need_to_find.count(cur))
                        if (has_found[cur]-- <= need_to_find[cur])
                            count--;
                    if (need_to_find.count(next))
                        if (++has_found[next] <= need_to_find[next])
                            count++;
                }
            }
        }
    }
    return result;
}

void Test(const std::string &source, const std::vector<std::string> &list) {
    std::cout << "Source: " << source << std::endl;
    std::cout << "Word List: ";
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
    std::vector<int> result = FindSubstring(source, list);
    std::cout << "output:";
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::string a[] = {"foo", "bar"};
    std::vector<std::string> l1(a, a + 2);
    Test("barfoothefoobarman", l1);
    Test("barfoobarfoobarman", l1);
    std::string b[] = {"a","b","a"};
    std::vector<std::string> l2(b, b + 3);
    Test("abababab", l2);
    return 0;
}
