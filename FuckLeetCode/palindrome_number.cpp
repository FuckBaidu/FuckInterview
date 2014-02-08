/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 */
#include <assert.h>
bool IsPalindrome(int x) {
    if (x < 0)
        return false;
    long long num = x, reverse = 0;
    while (num) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return x == reverse;
}

int main() {
    assert(IsPalindrome(121));
    assert(!IsPalindrome(123));
    return 0;
}
