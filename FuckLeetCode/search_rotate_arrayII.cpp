/*
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Write a function to determine if a given target is in the array.
 */
#include <assert.h>
bool Search(int A[], int n, int target) {
    int begin = 0, end = n - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2; // in case of overflow
        if (A[mid] == target)
            return true;

        // first part is sorted
        if (A[begin] < A[mid]) {
            if (target < A[mid] && target >= A[begin])
                end = mid - 1;
            else
                begin = mid + 1;
        } else if (A[begin] > A[mid]){
            if (target > A[mid] && target <= A[end])
                begin = mid + 1;
            else
                end = mid - 1;
        } else
            begin++;
    }
    return false;
}

int main() {
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    assert(!Search(a, 7, 3));
    assert(!Search(a, 7, 8));
    assert(!Search(a, 7, -1));
    for (int i = 0; i < 7; i++)
        assert(Search(a, 7, a[i]));
    int b[] = {1, 1, 3, 1};
    assert(Search(b, 4, 3));
    int c[] = {3, 1};
    assert(Search(c, 2, 3));
    int d[] = {1, 3, 5};
    assert(Search(d, 3, 1));
    int e[] = {1, 3, 1, 1, 1};
    assert(Search(e, 5, 3));
    return 0;
}
