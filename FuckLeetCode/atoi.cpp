/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see
 * below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You
 * are responsible to gather all the input requirements up front.
 *
 * spoilers alert... click to show requirements for atoi.
 *
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first
 * non-whitespace character is found. Then, starting from this character, takes an optional initial
 * plus or minus sign followed by as many numerical digits as possible, and interprets them as a
 * numerical value.
 *
 * The string can contain additional characters after those that form the integral number, which are
 * ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if
 * no such sequence exists because either str is empty or it contains only whitespace characters, no
 * conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out
 * of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 * http://oj.leetcode.com/problems/string-to-integer-atoi/
 */
#include <ctype.h>
#include <stdio.h>
#include <limits.h>

int atoi(const char *str) {
    if (!str)
        return 0;
    const char *cur = str;
    // Skip space
    while (*cur == ' ')
        cur++;
    // Check sign mark
    bool is_negative = false;
    if (*cur == '-' || *cur == '+') {
        is_negative = (*cur == '-');
        cur++;
    }
    long long result = 0;
    // Add
    while (isdigit(*cur)) {
        result = result * 10 + (*cur - '0');
        cur++;
        // Deal with overflow
        if (result > (long long)INT_MAX + 1 || (!is_negative && result == (long long)INT_MAX + 1))
            return  is_negative ? INT_MIN : INT_MAX;
    }
    if (is_negative)
        result = (-1) * result;
    return (int)result;
}

int main() {
    printf("NULL: %d\n", atoi(NULL));
    printf("Empry: %d\n", atoi(""));
    printf("123: %d\n", atoi("123"));
    printf("1 23: %d\n", atoi("1 23"));
    printf("-123: %d\n", atoi("-123"));
    printf("--1 23:%d\n", atoi("--1 23"));
    printf(" 12 23: %d\n", atoi(" 12 23"));
    printf(" 1!2 23: %d\n", atoi(" 1!2 23"));
    printf("888888888888888888888888888: %d\n", atoi("888888888888888888888888888"));
    printf("000000000000000000000000008: %d\n", atoi("000000000000000000000000008"));
    printf("2147483648: %d\n", atoi("2147483648"));
    printf("++1: %d\n", atoi("++1"));
    printf("-2147483648: %d\n", atoi("-2147483648"));
    return 0;
}
