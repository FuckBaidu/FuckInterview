/*
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */
#include <assert.h>
#include <limits.h>
int Reverse(int x) {
    long long num = x, reverse = 0;
    while (num) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    if (reverse < INT_MIN)
        return INT_MIN;
    else if (reverse > INT_MAX)
        return INT_MAX;
    else
        return (int)reverse;
}

int main() {
    assert(Reverse(123) == 321);
    assert(Reverse(-123) == -321);
    assert(Reverse(INT_MAX) == INT_MAX);
    return 0;
}
