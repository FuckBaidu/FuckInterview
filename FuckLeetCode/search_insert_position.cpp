/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return
 * the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 -> 2
 * [1,3,5,6], 2 -> 1
 * [1,3,5,6], 7 -> 4
 * [1,3,5,6], 0 -> 0
 */
#include <assert.h>
int SearchInsert(int A[], int n, int target) {
    int begin = 0, end = n - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (A[mid] == target)
            return mid;
        if (target > A[mid])
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return begin;
}

int main() {
    int a[] = {1, 3, 5, 6};
    assert(SearchInsert(a, 4, 5) == 2);
    assert(SearchInsert(a, 4, 2) == 1);
    assert(SearchInsert(a, 4, 7) == 4);
    assert(SearchInsert(a, 4, 0) == 0);
    return 0;
}
