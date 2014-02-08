/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the
 * array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3
 * steps to the last index.)
 */
#include <assert.h>
#include <algorithm>
int Jump(int A[], int n) {
    int count = 0, cur_max_jump = 0, next_max_jump = 0, i = 0;
      while (i < n) {
        if (cur_max_jump >= n - 1)
            break;
        for (; i <= cur_max_jump; i++)
            if (next_max_jump < i + A[i])
                next_max_jump = i + A[i];
        count++;
        cur_max_jump = std::min(next_max_jump, n - 1);
    }
    return count;
}

int main() {
    int a[] = {2, 3, 1, 1, 4};
    assert(Jump(a, 5) == 2);
    return 0;
}
