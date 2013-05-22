/*
 * Print a string in reverse order
 */
#include <stdio.h>
void ReversePrintString(const char *str) {
    if (str == NULL)
        return;
    if (*str != '\0') {
        ReversePrintString(str + 1);
        putchar(*str);
    }
}

int main() {
    ReversePrintString(NULL);
    putchar('\n');
    ReversePrintString("fuck");
    putchar('\n');
    return 0;
}
