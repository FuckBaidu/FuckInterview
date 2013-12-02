/**
 * 8.5 in <Crack the code interview>.
 * Implement a algorithm to print all valid combinations of n-pairs of parentheses
 */
#include <iostream>
#include <vector>
#include <string>

void GenerateParenthesis(char *buf, int left_count, int right_cout, int n,
                         std::vector<std::string> &result) {
    if (left_count == n && right_cout == n) {
        result.push_back(std::string(buf, 2 * n));
    } else {
        if (left_count < n) {
            buf[left_count + right_cout] = '(';
            GenerateParenthesis(buf, left_count + 1, right_cout, n, result);
        }

        if (right_cout < left_count) {
            buf[left_count + right_cout] = ')';
            GenerateParenthesis(buf, left_count, right_cout + 1, n, result);
        }
    }
}

std::vector<std::string> ParenthesesCombination(int n) {
    std::vector<std::string> result;
    char *buf = new char[2 * n];
    GenerateParenthesis(buf, 0, 0, n, result);
    delete[] buf;
    return result;
}

void Test(int n) {
    std::vector<std::string> result = ParenthesesCombination(n);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;
}

int main() {
    Test(4);
    return 0;
}
