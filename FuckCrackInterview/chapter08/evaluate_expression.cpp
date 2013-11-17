/**
 * 9.11 in <Crack the code interview> 5th edition.
 * Given a boolean expression consisting of the symbols 0, 1, &, | and ^, and a desired
 * boolean result.Implement a function to count the number of ways of parenthesizing the 
 * expression such that it evaluates to result
 * EXAMPLE:
 * Expression: 1^0|0|1
 * Desired result: false(0)
 * Output: 2 ways. 1^((0|0)|1) and 1^(0|(0|1))
 */
#include <iostream>
#include <vector>
#include <string>

int GetSubResult(const std::string &cur_operand, const std::string &cur_operator, bool desired_result) {
     int sub_desired_result = -1;
     if (cur_operator == "&") {
         if (desired_result) {
             if (cur_operand == "1")
                 sub_desired_result = 1;
         } else {
             if (cur_operand == "1")
                 sub_desired_result = 0;
             else
                 sub_desired_result = 2;
         }
     } else if (cur_operator == "|") {
         if (desired_result) {
             if (cur_operand == "1")
                 sub_desired_result = 2;
             else
                 sub_desired_result = 1;
         } else {
             if (cur_operand == "0")
                 sub_desired_result = 0;
         }
     } else if (cur_operator == "^") {
         if (desired_result) {
             if (cur_operand == "1")
                 sub_desired_result = 0;
             else
                 sub_desired_result = 1;
         } else {
             if (cur_operand == "1")
                 sub_desired_result = 1;
             else
                 sub_desired_result = 0;
         }
     }
    return sub_desired_result;
}

void Parenthesize(const std::string &expression,  std::vector<std::string> &result, bool desired_result) {
    if (expression.length() == 1) {
        if (!((expression == "1") ^ desired_result))
            result.push_back(expression);
    } else {
        std::string cur_operator, cur_operand, sub_expression;
        cur_operand = expression[0];
        cur_operator = expression[1];
        sub_expression = expression.substr(2);
        int sub_desired_result = GetSubResult(cur_operand, cur_operator, desired_result);
        for (int i = 0; i < 2; i++) {
            if (sub_desired_result == 2 || sub_desired_result == i) {
                std::vector<std::string> sub_result;
                Parenthesize(sub_expression, sub_result, (bool)i);
                for (int j = 0; j < sub_result.size(); j++) {
                    if (sub_expression.length() == 1)
                        result.push_back(cur_operand + cur_operator + sub_result[j]);
                    else
                        result.push_back(cur_operand + cur_operator + "(" + sub_result[j] + ")");
                }
            }
        }

        if (expression.length() > 3) {
            cur_operand = expression[expression.length() - 1];
            cur_operator = expression[expression.length() - 2];
            sub_expression = expression.substr(0, expression.length() - 2);
            int sub_desired_result = GetSubResult(cur_operand, cur_operator, desired_result);
            for (int i = 0; i < 2; i++) {
                if (sub_desired_result == 2 || sub_desired_result == i) {
                    std::vector<std::string> sub_result;
                    Parenthesize(sub_expression, sub_result, (bool)i);
                    for (int j = 0; j < sub_result.size(); j++) {
                        if (sub_expression.length() == 1)
                            result.push_back(sub_result[j] + cur_operator + cur_operand);
                        else
                            result.push_back("(" + sub_result[j] + ")" + cur_operator + cur_operand);
                    }
                }
            }
        }
    }
}

void Test(const std::string &expression, bool expect) {
    std::vector<std::string> result;
    Parenthesize(expression, result, expect);
    std::cout << "Expression: " << expression << std::endl;
    std::cout << "Desired result: " << expect << std::endl;
    std::cout << "Output: " << result.size() << " ways: ";
    for (int i = 0; i < result.size(); i++) 
        std::cout << result[i] << " ";
    std::cout << std::endl;
}

int main() {
    Test("1^0|0&1", false);
    Test("1^0|0&1", true);
    return 0;
}
