/**
 * 19.1 in <Crack the code interview>.
 * Write a function to swap two numbers in place without temporary variables
 */
#include <stdio.h>
void swap(int &a, int &b) {
    b = a ^ b;
    a = a ^ b;
    b = a ^ b;
}

void Test(int a, int b) {
    printf("Before swap: (%d, %d)\n", a, b);
    swap(a, b);
    printf("After swap: (%d, %d)\n", a, b);
}

int main() {
    Test(5, 3);
    return 0;
}
