/**
 * 5.5 in <Crack the code interview>.
 * Write a function to determine the number of bits required to convert integer A to integer B
 */
#include "stdio.h"
int CountOnes(int num) {
    int count = 0;
    while (num) {
        num &= num - 1;
        count++;
    }

    return count;
}

int NumConvertBits(int a, int b) {
    return CountOnes(a ^ b);
}

void Test(int a, int b) {
    printf("The number of bits required to convert from %d to %d is %d\n", a, b, NumConvertBits(a, b));
}

int main() {
    Test(31, 14);
    Test(18, 11);
    return 0;
}
