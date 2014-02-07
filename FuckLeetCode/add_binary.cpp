/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */
#include <string>
#include <iostream>

std::string AddBinary(const std::string &a, const std::string &b) {
    std::string result;
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    while (i >= 0 || j >= 0) {
        int first = i >= 0 ? a[i] - '0' : 0, second = j >= 0 ? b[j] - '0' : 0;
        int sum = first + second + carry;
        carry = sum >> 1;
        sum &= 1;
        result.push_back(sum + '0');
        i--;
        j--;
    }
    if (carry)
        result.push_back('1');
    std::reverse(result.begin(), result.end());
    return result;
}

void Test(const std::string &a, const std::string &b) {
    std::cout << a << " + " << b << " = " << AddBinary(a, b) << std::endl;
}

int main() {
    Test("1011", "11");
    Test("1011", "1111");
    return 0;
}
