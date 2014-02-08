/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int n);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
#include <string>
#include <assert.h>
std::string Convert(const std::string &s, int n) {
    if (n <= 1)
        return s;
    std::string result;
    int zigzag_len = 2 * n - 2;
    for (int i = 0; i < n; i++) {
        int off;
        if (i == 0 || i == n - 1)
            off = zigzag_len;
        else
            off = i * 2;
        for (int j = i; j < s.length(); j += off) {
            result.push_back(s[j]);
            if (i > 0 && i < n - 1)
                off = zigzag_len - off;
        }
    }
    return result;
}

int main() {
    assert(Convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    return 0;
}
