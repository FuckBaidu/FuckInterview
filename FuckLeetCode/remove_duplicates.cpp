/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and
 * return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 */
#include <assert.h>
#include <iostream>
int RemoveDuplicates(int A[], int n) {
    if (n == 0)
        return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (i < n && A[i] == A[j])
            i++;
        if (i < n)
            A[++j] = A[i];
    }
    return j + 1;
}

int main() {
    int a[] = {1, 1, 2};
    assert(RemoveDuplicates(a, 0) == 0);
    assert(RemoveDuplicates(a, 3) == 2);
    for (int i = 0; i < 2; i++)
        assert(a[i] == i + 1);
    return 0;
    int b[] = {1, 1, 2, 3, 3, 3};
    assert(RemoveDuplicates(b, 6) == 3);
    for (int i = 0; i < 3; i++)
        assert(b[i] == i + 1);
    return 0;
}

