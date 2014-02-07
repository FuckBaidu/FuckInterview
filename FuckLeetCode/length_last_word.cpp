/*
 *Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

 If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
 */
#include <assert.h>
#include <ctype.h>
int LengthOfLastWord(const char *s) {
    if (!s)
        return 0;
    int len = 0;
    const char *begin = s;
    bool is_in_word = false;
    while (*s) {
        if (!isalpha(*s)) {
            if (is_in_word) {
                len = s - begin;
                is_in_word = false;
            }
        } else {
            if (!is_in_word) {
                begin = s;
                is_in_word = true;
            }
        }
        s++;
    }
    if (is_in_word)
        len = s - begin;
    return len;
}

int main() {
    assert(LengthOfLastWord(" hello ") == 5);
    assert(LengthOfLastWord(" hello sdxx! ") == 4);
    return 0;
}
