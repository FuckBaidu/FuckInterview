/*
 * count the number of ones of a number which is in binary representation
 */
#include <assert.h>
int CountNumOfOnes(int n) {
    int count = 0;
    while (n) {
        n &= (n -1);
        count++;
    }
    return count;
}

int main() {
    assert(CountNumOfOnes(0) == 0);
    assert(CountNumOfOnes(0xffff) == 16);
    return 0;
}
