/*
 * Given two numbers: A and B, count the number of different ones between A and B in binary
 * representation
 */
#include <assert.h>
int NumOfDiffOnes(int m, int n) {
    int count = 0;
    int diff = (m ^ n);
    while (diff) {
        diff &= (diff - 1);
        count++;
    }
    return count;
}

int main() {
    assert(NumOfDiffOnes(0, 1) == 1);
    assert(NumOfDiffOnes(0xffff, 0x0f0f) == 8);
    return 0;
}
