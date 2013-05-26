/*
 * Frome section 2.4 of <The Beauty of Coding>.Given a decimal number N, count how many ones in the
 * sequence [1, N].
 * eg: N = 2, then sequence is (1, 2), the number of ones is 1.
 *     N = 12, then sequence is (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12), there are five ""1" in the
 *     sequence
 */
#include <assert.h>
int CountOnes(int num) {
    if (num <= 0)
        return 0;

    int count = 0;
    int cur = 0, low = 0, high = 0, factor = 1;
    while (num) {
        cur = num % 10;
        high = num / 10;
        switch (cur) {
        case 0:
            count += high * factor;
            break;
        case 1:
            count += (high * factor + low + 1);
            break;
        default:
            count += (high + 1) * factor;
            break;
        }
        low += cur * factor;
        factor *= 10;
        num = high;
    }
    return count;
}

int main() {
    assert(CountOnes(1) == 1);
    assert(CountOnes(9) == 1);
    assert(CountOnes(12) == 5);
    assert(CountOnes(99) == 20);
    assert(CountOnes(100) == 21);
    assert(CountOnes(111) == 36);
    assert(CountOnes(9999) == 4000);
    return 0;
}
