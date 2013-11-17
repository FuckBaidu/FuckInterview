/**
 * 20.1 in <Crack the code interview>.
 * write a function that adds two numbers.You should not use + or any other
 * arithmetic operator
 */
#include <stdio.h>
int add(int a, int b) {
    int carry = 0, sum = 0, result = 0;
    for (int i = 0; i < sizeof(int) * 8; i++) {
        sum = ((a >> i) & 1) ^ ((b >> i) & 1) ^ carry;
        carry = (((a >> i) & 1) & ((b >> i) & 1)) | (carry & ((a >> i) & 1)) | (carry & ((b >> i) & 1));
        result |= (sum << i);
    }
    return result;
}

void Test(int a, int b) {
    printf("%d + %d = %d\n", a, b, add(a, b));
}

int main() {
    Test(5, 7);
    Test(113, 286);
    return 0;
}
