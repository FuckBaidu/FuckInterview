/*
 * Count the number of words in a string, where a word is defined to be a contiguous sequence of non-space characters.
 * eg: "Hello, my name is john" -> 5
 */
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

int CountNumWords(const char *str) {
    if (str == NULL)
        return 0;
    int word_count = 0;
    bool is_in_word = false;
    const char *cur = str;
    while (*cur) {
        if (isalpha(*cur)) {
            if (!is_in_word)
                word_count++;
            is_in_word = true;
        } else {
            is_in_word = false;
        }
        cur++;
    }
    return word_count;
}

int main() {
    assert(CountNumWords(NULL) == 0);
    assert(CountNumWords("") == 0);
    assert(CountNumWords("Hello, my name is John.") == 5);
    assert(CountNumWords("  Hello, my name is John.  ") == 5);
    return 0;
}
