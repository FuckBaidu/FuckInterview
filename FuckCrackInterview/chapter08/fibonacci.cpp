/**
 * 8.1 in <Crack the code interview>.
 * Write a method to generate the nth Fibonacci number
 */
#include <stdio.h>
int Fibonacci(int n) {
    if (n <= 0)
        return -1;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci1(int n) {
    if (n <= 0)
        return -1;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int a = 1, b = 2, c = 0;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

void Test(int n) {
    printf("The %dth Fibonacci number is %d\n", n, Fibonacci(n));
    printf("The %dth Fibonacci number is %d\n", n, Fibonacci1(n));
}

int main() {
    for (int i = 0; i <= 10; i++)
        Test(i);
    return 0;
}
