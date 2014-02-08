/*
 * Find the contiguous subarray within an array (containing at least one number) which has the
 * largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
#include <assert.h>
#include <limits.h>
int MaxSubArray(int A[], int n) {
    int max_sum = INT_MIN,  cur_sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (cur_sum < 0)
            cur_sum = 0;
        cur_sum += A[i];
        if (max_sum < cur_sum)
            max_sum = cur_sum;
    }
    return max_sum;
}

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    assert(MaxSubArray(a, 9) == 6);
    return 0;
}
