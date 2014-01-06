/**
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
#include <string>
#include <map>
#include <assert.h>

int RomanToInt(const std::string &s) {
    char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', 'M', 'M'};
    std::map<std::string, int> table;
    int factor = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 9; j++) {
            std::string tmp;
            if (j == 5) {
                tmp.push_back(roman[2 * i + 1]);
            } else if (j == 4 || j == 9) {
                tmp.push_back(roman[2 * i]);
                if (j == 4)
                    tmp.push_back(roman[2 * i + 1]);
                else
                    tmp.push_back(roman[2 * i + 2]);
            } else {
                int cur = j;
                if (cur >= 6) {
                    tmp.push_back(roman[2 * i + 1]);
                    cur -= 5;
                }
                tmp.append(cur, roman[2 * i]);
            }
            table[tmp] = factor * j;
        }
        factor *= 10;
    }
    
    int result = 0, i = 0;
    while (i < s.length()) {
        int len = 1;
        std::string tmp = s.substr(i, len);
        while (table.count(tmp)) {
            len++;
            tmp = s.substr(i, len);
        }
        len--;
        result += table[s.substr(i, len)];
        i += len;
    }
    return result;
}

int main() {
    assert(RomanToInt("DCXXI") == 621);
    return 0;
}
