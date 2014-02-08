/*
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 */
#include <assert.h>
#include <algorithm>
int FirstMissingPositive(int A[], int n) {
    for (int i = 0; i < n; i++)
        while (A[i] > 0 && A[i] <= n && A[i] != i + 1 && A[A[i] - 1] != A[i])
            std::swap(A[i], A[A[i] - 1]);
    for (int i = 0; i < n; i++)
        if (A[i] != i + 1)
            return i + 1;
    return n + 1;
}

int main() {
    int a[] = {1, 2, 0};
    assert(FirstMissingPositive(a, 3) == 3);
    int b[] = {2, 4, 1};
    assert(FirstMissingPositive(b, 3) == 3);
    int c[] = {2, 3, 1};
    assert(FirstMissingPositive(c, 3) == 4);
    int d[] = {2, -1, 3};
    assert(FirstMissingPositive(d, 3) == 1);
    return 0;
}
