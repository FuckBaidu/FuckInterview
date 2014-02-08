/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the
 * array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 */
#include <assert.h>
bool CanJump(int A[], int n) {
    if (!A || n == 0)
        return false;
    int max_jump = 0;
    for (int i = 0; i <= max_jump; i++) {
        if (max_jump < i + A[i])
            max_jump = i + A[i];
        if (max_jump >= n - 1)
            return true;
    }
    return false;
}

int main() {
    int a[] = {2, 3, 1, 1, 4}, b[] = {3, 2, 1, 0, 4};
    assert(CanJump(a, 5));
    assert(!CanJump(b, 5));
    return 0;
}
