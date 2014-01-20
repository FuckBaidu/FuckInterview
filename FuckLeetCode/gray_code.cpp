/*
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the code, print the
 * sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about
 * that.
 */
#include <vector>
#include <iostream>

std::vector<int> GrayCode(int n) {
    std::vector<int> result(1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = (int)result.size() - 1; j >= 0; j--)
            result.push_back(result[j] | (1 << (i - 1)));
    return result;
}

void Test(int n) {
    std::vector<int> result = GrayCode(n);
    std::cout << "n = " << n << std::endl;
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " - " << i << std::endl;
}

int main() {
    Test(3);
    Test(5);
    return 0;
}
