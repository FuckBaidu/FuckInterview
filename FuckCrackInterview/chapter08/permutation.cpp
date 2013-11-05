/**
 * 8.4 in <Crack the code interview>.
 * Write a method to compute all the permutations of a string
 */
#include <iostream>
#include <vector>
#include <string>

int count = 0;
std::vector<std::string> ComputePermutation(const std::string &str) {
    count++;
    std::vector<std::string> result;
    for (int i = 0; i < str.length(); i++) {
        std::string substr = str, cur(1, str[i]);
        substr.erase(i, 1);
        if (substr.length() > 1) {
            std::vector<std::string> sub_result = ComputePermutation(substr);
            for (int j = 0; j < sub_result.size(); j++)
                result.push_back(cur + sub_result[j]);
        } else {
            result.push_back(cur + substr);
        }
    }
    return result;
}

void Test(const std::string &str) {
    std::vector<std::string> result = ComputePermutation(str);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;
}

int main() {
    Test("abc");
    std::cout << count << std::endl;
    return 0;
}
