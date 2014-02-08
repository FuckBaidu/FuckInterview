/*
 * Divide two integers without using multiplication, division and mod operator.
 *
 */
#include <vector>
#include <assert.h>
int Divide(int dividend, int divisor) {
    assert(divisor != 0);
    long long result = 0, dvd = dividend, dvs = divisor;
    int sign = 1;
    if (dvd < 0) {
        dvd = -dvd;
        sign = -sign;
    }
    if (dvs < 0) {
        dvs = -dvs;
        sign = -sign;
    }
    std::vector<long long> table;
    for (long long i = dvs; i <= dvd; i <<= 1)
        table.push_back(i);
    for (int i = (int)table.size() - 1; i >= 0; i--) {
        if (dvd >= table[i]) {
            dvd -= table[i];
            result += (1 << i);                
        }
    }
    result *= sign;
    return (int)result;
}

int main() {
    assert(Divide(2147483647, 3) == 715827882);
    assert(Divide(-2147483648, 1) == -2147483648);
    assert(Divide(5, 2) == 2);
    assert(Divide(1, 1) == 1);
    return 0;
}
