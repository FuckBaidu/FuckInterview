/**
 * 1.1 in <Crack the code interview>.Implement an algorithm to determine if a string has all unique
 * characters, you can not use additional data structures
 */
#include <assert.h>
#include <stdlib.h>
bool IsUniqueChars(const char *str) {
    if (str == NULL)
        return true;
    for ( ; *(str + 1) != '\0'; str++)
        for (const char *cur = str + 1; *cur != '\0'; cur++)
            if (*str == *cur)
                return false;
    return true;
}
int main() {
    assert(IsUniqueChars(NULL) == true);
    assert(IsUniqueChars("abcde") == true);
    assert(IsUniqueChars("abcvxzsade") == false);
    return 0;
}
