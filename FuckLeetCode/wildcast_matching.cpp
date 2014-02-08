/*
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") ? false
 * isMatch("aa","aa") ? true
 * isMatch("aaa","aa") ? false
 * isMatch("aa", "*") ? true
 * isMatch("aa", "a*") ? true
 * isMatch("ab", "?*") ? true
 * isMatch("aab", "c*a*b") ? false
 */
#include <assert.h>
bool IsMatch(const char *s, const char *p) {
    if (!s || !p)
        return false;
    bool has_star = false;
    const char *s_bak = s, *p_bak = p;
    while (*s) {
        if (*p == '*') {
            has_star = true;
            while (*p == '*')
                p++;
            if (*p == '\0')
                return true;
            s_bak = s;
            p_bak = p;
        } else if (*s != *p && *p != '?') {
            if (!has_star)
                return false;
            s_bak++;
            s = s_bak;
            p = p_bak;
        } else {
            s++;
            p++;
        }
    }
    // remove trailing stars
    while (*p == '*')
        p++;
    return *p == '\0';
}

int main() {
    assert(!IsMatch("aa", "a"));
    assert(IsMatch("aa","aa"));
    assert(!IsMatch("aaa", "aa"));
    assert(IsMatch("aa","*"));
    assert(IsMatch("aa","a*"));
    assert(IsMatch("aa","a**"));
    assert(IsMatch("ab","?*"));
    assert(IsMatch("hi","*?"));
    assert(!IsMatch("aab", "c*a*b"));
    return 0;
}
