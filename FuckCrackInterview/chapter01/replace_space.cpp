/*
 * Question 1.5 in <Crack the code interview>. Replace all spaces in the string with "%20"
 */
#include <assert.h>
#include <string.h>
void ReplaceSpaces(char *str) {
    if (str == NULL || *str == '\0')
        return;
    int space_count = 0;
    for (const char *cur = str; *cur != '\0'; cur++)
        if (*cur == ' ')
            space_count++;
    int len = strlen(str);
    int new_len = len + 2 * space_count;
    str[new_len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[new_len - 1] = str[i];
            new_len--;
        } else {
            str[new_len - 1] = '0';
            str[new_len - 2] = '2';
            str[new_len - 3] = '%';
            new_len -= 3;
        }
    }
}

int main() {
    ReplaceSpaces(NULL);
    ReplaceSpaces("");
    char test1[16] = "abcd";
    ReplaceSpaces(test1);
    assert(strcmp(test1, "abcd") == 0);
    char test2[32] = "a b c de  ";
    ReplaceSpaces(test2);
    assert(strcmp(test2, "a%20b%20c%20de%20%20") == 0);
    char test3[32] = "a b c de  f";
    ReplaceSpaces(test3);
    assert(strcmp(test3, "a%20b%20c%20de%20%20f") == 0);
    return 0;
}
