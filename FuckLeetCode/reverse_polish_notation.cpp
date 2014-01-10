/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 */
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <assert.h>

int EvalRPN(std::vector<std::string> &tokens) {
    int result = 0;
    std::stack<int> stack;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int operand_i, operand_j;
            operand_j = stack.top();
            stack.pop();
            operand_i = stack.top();
            stack.pop();
            if (tokens[i] == "+")
                result = operand_i + operand_j;
            else if (tokens[i] == "-")
                result = operand_i - operand_j;
            else if (tokens[i] == "*")
                result = operand_i * operand_j;
            else if (tokens[i] == "/")
                result = operand_i / operand_j;
            stack.push(result);
        } else {
            int value = atoi(tokens[i].c_str());
            stack.push(value);
        }
    }
    if (!stack.empty())
        result = stack.top();
    return result;
}

int main() {
    std::vector<std::string> a;
    assert(EvalRPN(a) == 0);
    a.push_back("-3");
    assert(EvalRPN(a) == -3);
    a.push_back("1");
    a.push_back("+");
    assert(EvalRPN(a) == -2);

    a.clear();
    a.push_back("4");
    a.push_back("13");
    a.push_back("5");
    a.push_back("/");
    a.push_back("+");
    assert(EvalRPN(a) == 6);
    return 0;
}
