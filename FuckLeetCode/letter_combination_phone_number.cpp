/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 *
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
#include <string>
#include <vector>
#include <iostream>
void LetterCombinations(const std::string &digits, int index, std::string &path, std::vector<std::string> &result) {
    static std::string trans_table[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (index == digits.length()) {
        result.push_back(path);
    } else {
        int cur_digit = digits[index] - '0';
        for (int i = 0; i < trans_table[cur_digit].length(); i++) {
            path[index] = trans_table[cur_digit][i];
            LetterCombinations(digits, index + 1, path, result);
        }
    }
}
 

std::vector<std::string> LetterCombinations(const std::string &digits) {
    std::vector<std::string> result;
    std::string path(digits.length(), ' ');
    LetterCombinations(digits, 0, path, result);
    return result;
}

int main() {
    std::string digits = "236";
    std::cout << "Letter combination of " << digits << std::endl;
    std::vector<std::string> result = LetterCombinations(digits);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;
    return 0;
}
