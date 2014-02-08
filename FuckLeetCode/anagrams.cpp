/*
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 */
#include <vector>
#include <string>
#include <map>
#include <iostream>

std::vector<std::string> Anagrams(const std::vector<std::string> &strs) {
    std::vector<std::string> result;
    // value is index in vector, if value is -1, means no need to add key string to result
    std::map<std::string, int> hash_map;
    for (int i = 0; i < strs.size(); i++) {
        std::string tmp = strs[i];
        std::sort(tmp.begin(), tmp.end());
        if (hash_map.count(tmp)) {
            int index = hash_map[tmp];
            if (index != -1) {
                result.push_back(strs[index]);
                hash_map[tmp] = -1;
            }
            result.push_back(strs[i]);
        } else {
            hash_map[tmp] = i;
        }
    } 
    return result;
}

struct Comparator {
    bool operator()(const std::string &a, const std::string &b) const {
        std::string ta = a, tb = b;
        std::sort(ta.begin(), ta.end());
        std::sort(tb.begin(), tb.end());
        return ta < tb;
    }
} comparator;

int main() {
    std::string a[] = {"abce", "abc", "bcad", "bac", "acb", "abcd"};
    std::vector<std::string> input(a, a + 6);
    std::vector<std::string> output = Anagrams(input);
    std::sort(output.begin(), output.end(), comparator);
    std::cout << "input:";
    for (int i = 0; i < input.size(); i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
    std::cout << "output:";
    for (int i = 0; i < output.size(); i++)
        std::cout << output[i] << " ";
    std::cout << std::endl;
    return 0;
}
