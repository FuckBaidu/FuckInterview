/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and
 * ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an
 * interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */
#include <assert.h>
#include <ctype.h>
#include <string>
bool IsPalindrome(std::string s) {
    bool result = true;
    int begin = 0, end = s.length() - 1;
    while (begin < end) {
        while (begin < end && !isalnum(s[begin]))
            begin++;
        while (end > begin && !isalnum(s[end]))
            end--;
        if (begin < end && tolower(s[begin]) != tolower(s[end])) {
            result = false;
            break;
        }
        begin++;
        end--;
    }
    return result;
}

int main () {
    assert(IsPalindrome("A man, a plan, a canal -- Panama"));
    assert(!IsPalindrome(".`8wi'4X;6zJz6;4X'iw8`."));
    assert(IsPalindrome("    "));
    return 0;
}
