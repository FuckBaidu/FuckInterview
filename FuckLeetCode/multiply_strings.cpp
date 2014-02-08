/*
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 */
#include <string>
#include <iostream>
std::string Multiply(const std::string &num1, const std::string &num2) {
    std::string result(num1.length() + num2.length(), '0');
    for (int i = num2.length() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = num1.length() - 1; j >= 0; j--) {
            int cur = (num1[j] - '0') * (num2[i] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = cur % 10 + '0'; 
            carry = cur / 10;
        }
        if (carry)
            result[i] = carry + '0';
    }
    // remove heading zero
    int k = 0;
    while (k < result.length() - 1 && result[k] == '0')
        k++;
    result.erase(0, k);
    return result;
}

int main() {
    std::cout << "1232323223 * 22142142141 = " << Multiply("1232323223", "22142142141") << std::endl;
    std::cout << "1234 * 1234 = " << Multiply("1234", "1234") << std::endl;
    return 0;
}
