/*
 * Implement pow(x, n).
 */
#include <math.h>
#include <assert.h>
double Pow(double x, int n) {
    if (n == 0)
        return 1;
    // use long long in case of INT_MIN
    long long exponent = n;
    bool is_neagtive = (exponent < 0);
    if (is_neagtive)
        exponent = -1 * exponent;
    double result = 1;
    // Eg.: 7 = 2^2 + 2^1 + 2^0;
    while (exponent != 0) {
        if (exponent & 1)
            result *= x;
        x *= x;
        exponent >>= 1;
    }
    if (is_neagtive)
        result = 1 / result;
    return result;
}


int main() {
    assert(Pow(34.00515, -3) == pow(34.00515, -3));
    assert(Pow(0.00001, 2147483647) == pow(0.00001, 2147483647));
    assert(Pow(1.00000, -2147483648) == pow(1.00000, -2147483648));
    return 0;
}
