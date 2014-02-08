/*
 *plement regular expression matching with support for '.' and '*'.

 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.

 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool IsMatch(const char *s, const char *p)

 Some examples:
 IsMatch("aa","a") ? false
 IsMatch("aa","aa") ? true
 IsMatch("aaa","aa") ? false
 IsMatch("aa", "a*") ? true
 IsMatch("aa", ".*") ? true
 IsMatch("ab", ".*") ? true
 IsMatch("aab", "c*a*b") ? true
 */
#include <assert.h>
bool IsMatch(const char *s, const char *p) {
    if (*p != '\0') {
        if (*(p + 1) == '*') {
            while (*s == *p || *p == '.' && *s != '\0') {
                if (IsMatch(s, p + 2))
                    return true;
                s++;
            }
            return IsMatch(s, p + 2);
        } else {
            if (*s == '\0' || *s != *p && *p != '.')
                return false;
            return IsMatch(s + 1, p + 1);
        }
    } else {
        return *s == '\0';
    }
}

int main() {
    assert(IsMatch("aa","a") == false);
    assert(IsMatch("aa","aa") == true);
    assert(IsMatch("aaa","aa") == false);
    assert(IsMatch("aa", "a*") == true);
    assert(IsMatch("aa", ".*") == true);
    assert(IsMatch("ab", ".*") == true);
    assert(IsMatch("aab", "c*a*b") == true);
    assert(IsMatch("ccaabc", "c*a*bc*") == true);
    return 0;
}
