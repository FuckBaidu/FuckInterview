/**
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
#include <string>
#include <map>
#include <iostream>
#include <vector>

int RomanToInt(const std::string &s) {
    std::map<char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    int result = 0;
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        if (i < (int)s.length() - 1 && map[s[i]] < map[s[i + 1]]) {
            result -= map[s[i]];
        } else {
            result += map[s[i]];
        }
    }
    return result;
}

std::string IntToRoman(int num) {
    assert(num >= 1 && num <= 3999);
    std::map<int, char> table;
    table[1] = 'I';
    table[5] = 'V';
    table[10] = 'X';
    table[50] = 'L';
    table[100] = 'C';
    table[500] = 'D';
    table[1000] = 'M';
    std::string result;
    int factor = 1;
    while (num) {
        char one = table[factor], five = table[factor * 5], ten = table[factor * 10];
        int cur = num % 10;
        if (cur >= 1 && cur <= 3) {
            result.append(cur, one);
        } else if (cur == 4) {
            result.append(1, five);
            result.append(1, one);
        } else if (cur >= 5 && cur <= 8) {
            result.append(cur - 5, one);
            result.append(1, five);
        } else if (cur == 9) {
            result.append(1, ten);
            result.append(1, one);
        }
        num /= 10;
        factor *= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int cur;
        do {
            cur = rand() % 4000;
        } while (cur == 0);
        std::cout << "input:" << cur << std::endl;
        std::string roman = IntToRoman(cur);
        std::cout << "Int to Roman:" << roman << std::endl;
        std::cout << "Roman to int:" << RomanToInt(roman) << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
