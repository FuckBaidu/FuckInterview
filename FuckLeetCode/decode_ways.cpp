/*
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */
#include <string>
#include <vector>
#include "assert.h"
int NumDecodings(const std::string &s) {
    if (s.empty())
        return 0;
    std::vector<int> num(s.length(), 0);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0')
            num[i] += i > 0 ? num[i - 1] : 1;
        if (i >= 1 && s[i - 1] != '0') {
            int cur_num = atoi(s.substr(i -1 , 2).c_str());
            if (cur_num <= 26)
                num[i] += i > 1 ? num[i - 2] : 1;
        }
    }
    return num.back();
}

int main() {
    assert(NumDecodings("103") == 1);
    assert(NumDecodings("127") == 2);
    assert(NumDecodings("126") == 3);
    assert(NumDecodings("0") == 0);
    return 0;
}
