/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */
#include <string>
#include <iostream>
std::string CountAndSay(int n) {
    std::string result(1, '1');
    for (int i = 2; i <= n; i++) {
        std::string tmp;
        char cur = result[0];
        int count = 1;
        for (int j = 1; j < result.length(); j++) {
            if (cur != result[j]) {
                tmp.push_back(count + '0');
                tmp.push_back(cur);
                cur = result[j];
                count = 0;
            }
            count++;
        }
        tmp.push_back(count + '0');
        tmp.push_back(cur);
        result = tmp;
    }
    return result;
}

int main() {
    for (int i = 1; i <= 10; i++)
        std::cout << CountAndSay(i) << std::endl;
    return 0;
}
