/**
 * 8.5 in <Crack the code interview>.
 * Implement a algorithm to print all valid combinations of n-pairs of parentheses
 */
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> ParenthesesCombination(int n) {
    std::vector<std::string> result;
    if (n == 1) {
        result.push_back("()");
    } else {
        std::vector<std::string> tmp = ParenthesesCombination(n - 1);
        for (int i = 0; i < tmp.size(); i++) {
            result.push_back("()" + tmp[i]);
            result.push_back("("+tmp[i]+")");
        }
    }
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
