/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed
 * parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */
#include <string>
#include <vector>
#include <iostream>
void GenerateParenthesis(int n , int num_left, int num_right, std::string &path, std::vector<std::string> &result) {
    if (num_left == n && num_right == n) {
        result.push_back(path);
    } else {
        // num_left > num_right && num_left <n || num_left == num_right
        if (num_left < n) {
            path[num_left + num_right + 1] = '(';
            GenerateParenthesis(n, num_left + 1, num_right, path, result);
        }
        // only if num_left > num_right
        if (num_left > num_right) {
            path[num_left + num_right + 1] = ')';
            GenerateParenthesis(n, num_left, num_right + 1, path, result);
        }
    }
}

std::vector<std::string> GenerateParenthesis(int n) {
    std::vector<std::string> result;
    if (n > 0) {
        std::string path(2 * n, ' ');
        GenerateParenthesis(n, 0, 0, path, result);
    }
    return result;
}

int main() {
    std::cout << "n = 4:" << std::endl;
    std::vector<std::string> result = GenerateParenthesis(4);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;
    return 0;
}
