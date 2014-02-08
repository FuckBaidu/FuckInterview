/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
#include <string>
#include <vector>
#include <iostream>
std::string LongestCommonPrefix(const std::vector<std::string> &strs) {
    std::string result;
    if (!strs.empty()) {
        int len;
        result = strs[0];
        for (len = 1; len <= result.length(); len++) {
            bool need_to_break = false;
            for (int i = 1; i < strs.size(); i++) {
                if (len > strs[i].length()) {
                    need_to_break = true;
                    break;
                }
                if (result[len - 1] != strs[i][len - 1]) {
                    need_to_break = true;
                    break;
                }
            }
            if (need_to_break)
                break;
        }
        len--;
        result = result.substr(0, len);
    }
    return result;
}

int main() {
    std::string a[] = {"abcd", "abce", "abc"};
    std::vector<std::string> strs(a, a + 3);
    std::string result = LongestCommonPrefix(strs);
    std::cout << "input:";
    for (int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << " ";
    std::cout << std::endl;
    std::cout << "longest common prefix:" << result << std::endl;
    return 0;
}
