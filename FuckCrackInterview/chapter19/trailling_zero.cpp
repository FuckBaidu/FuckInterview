/**
 * 19.3 in <Crack the code interview>.
 * Write a method which computes the number of trailing zeros in n factorial
 */
#include <stdio.h>
int CountZerosFactorial(int n) {
    int count = 0;
    while (n > 1) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

void Test(int n) {
    printf("the number of trailing zeros in %d factorial is %d\n", n, CountZerosFactorial(n));
}

int main() {
    Test(25);
    Test(125);
    return 0;
}
