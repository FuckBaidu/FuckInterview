/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return
 * -1.
 *
 *  You may assume no duplicate exists in the array.
 */
#include <assert.h>
int Search(int A[], int n, int target) {
    int begin = 0, end = n - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (A[mid] == target)
            return mid; 
        // first part is sorted
        if (A[begin] <= A[mid]) {
            if (target < A[mid] && target >= A[begin])
                end = mid - 1;
            else
                begin = mid + 1;
        } else {
            if (target > A[mid] && target <= A[end])
                begin = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    assert(Search(a, 7, 3) == -1);
    assert(Search(a, 7, 8) == -1);
    assert(Search(a, 7, -1) == -1);
    for (int i = 0; i < 7; i++)
        assert(Search(a, 7, a[i]) == i);
    return 0;
}
