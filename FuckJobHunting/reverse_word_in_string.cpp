/**
 * Reverse each word in the string
 */
#include <stdio.h>
void Reverse(char *str) {
    if (!str)
        return;
    char *begin = str, *end = str, *next = str;
    while (*begin != '\0') {
        while (*begin == ' ')
            begin++;
        end = begin;
        while (*end != ' ' && *end != '\0')
            end++;
        next = end;
        end--;
        while (begin < end) {
            char tmp = *begin;
            *begin = *end;
            *end = tmp;
            begin++;
            end--;
        }
        begin = next;
    }
}

void Test(char *str) {
    printf("%s\n", str);
    Reverse(str);
    printf("%s\n", str);
}

int main() {
    char a[] = "";
    Test(a);
    char b[] = " fuck you ";
    Test(b);
    char c[] = "fuck your mom";
    Test(c);
    return 0;
}
