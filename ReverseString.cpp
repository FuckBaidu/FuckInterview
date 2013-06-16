/**
 * Question 1.2 in <crack the code interview>. write code to reverse a C-NULL string
 */
#include <assert.h>
#include <string.h>
void ReverseString(char *str) {
    if (str == NULL)
        return;
    char *end = str;
    while (*end && *(end + 1))
        end++;
    while (str < end) {
        char tmp = *str;
        *str = *end;
        *end = tmp;

        str++;
        end--;
    }
}

int main() {
    char str1[] = "a";
    ReverseString(str1);
    assert(strcmp(str1, "a") == 0);
    char str2[] = "";
    ReverseString(str2);
    assert(strcmp(str2, "") == 0);
    ReverseString(NULL);
    char str3[] = "abcd";
    ReverseString(str3);
    assert(strcmp(str3, "dcba") == 0);
    char str4[] = "abcde";
    ReverseString(str4);
    assert(strcmp(str4, "edcba") == 0);
    return 0;
}
