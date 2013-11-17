#include <stdio.h>
int gcd (int m, int n) {
    if (!m || !n)
        return 0;
    int a, b;
    if (m > n) {
        a = m;
        b = n;
    } else {
        a = n;
        b = m;
    }

    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm (int m, int n) {
    if (!m || !n)
        return 0;
    return m * n / gcd(m, n);
}

void Test(int m, int n) {
    printf("gcd(%d, %d) is %d, lcm(%d, %d) is %d\n", m, n, gcd(m, n), m, n, lcm(m, n));
}

int main () {
    Test(15, 20);
    Test(3, 6);
    Test(15, 0);
    return 0;
}
