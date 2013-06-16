/**
 * 1.1 in <Crack the code interview>.Implement an algorithm to determine if a string has all unique
 * characters
 */
#include <assert.h>
#include <stdlib.h>
#define TEST_BIT(bitmap, nr) ((bitmap) & (1 << (nr)))
#define SET_BIT(bitmap, nr) ((bitmap) |= (1 << (nr)))

bool HasUniqueChars(const char *str) {
    if (str == NULL)
        return true;
    int bitmap = 0;
    const char *cur = str;
    for (cur = str; *cur != '\0'; cur++) {
        if (TEST_BIT(bitmap, *cur))
            return false;
        else
            SET_BIT(bitmap, *cur);
    }
    return true;
}
int main() {
    assert(HasUniqueChars(NULL) == true);
    assert(HasUniqueChars("abcde") == true);
    assert(HasUniqueChars("abcvxzsade") == false);
    return 0;
}
