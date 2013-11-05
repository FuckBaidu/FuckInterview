/**
 * 16.5 in <Crack the code interview>.
 * Write a function to find out whether a machine is big-endian or little-endian
 */
#include <stdio.h>
int main() {
    int i = 1;
    if (*(char *)&i)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");
    return 0;
}
