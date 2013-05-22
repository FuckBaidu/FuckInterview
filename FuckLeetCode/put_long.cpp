/*
 * Given only putchar (no sprintf, itoa, etc.) write a routine putlong that prints out an unsigned long in decimal.
 */

#include <stdio.h>
#include <string.h>

void PutLong1(unsigned long num) {
    char buf[64];
    int len = 0;
    memset(buf, 0, sizeof(buf));
    do {
       buf[len++] = '0' + num % 10;
       num /= 10;
    } while(num);

    for (int i = len - 1; i >=0; i--)
        putchar(buf[i]);
    putchar('\n');
}

void PutLong2(unsigned long num) {
    if (num >= 10ul)
        PutLong2(num / 10);
    putchar('0' + num % 10);
}

int main() {
    PutLong1(0);
    PutLong1(1234567890ul);
    PutLong2(0);
    putchar('\n');
    PutLong2(1234567890ul);
    putchar('\n');
    return 0;
}
