/**
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */
#include <assert.h>
#include <vector>
std::vector<int> SearchRange(int A[], int n, int target) {
    int begin = 0, end = n, lower_bound = -1, uppder_bound = -1;
    std::vector<int> result;
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        if (target > A[mid])
            begin = mid + 1;
        else
            end = mid;
    }
    if (A[begin] == target)
        lower_bound = begin;
    else
        goto LABEL_EXIT;
    begin = lower_bound, end = n;
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        if (target < A[mid])
            end = mid;
        else
            begin = mid + 1;
    }
    begin--;
    if (A[begin] == target)
        uppder_bound = begin;
    else
        goto LABEL_EXIT;
LABEL_EXIT:
    result.push_back(lower_bound);
    result.push_back(uppder_bound);
    return result;
}

std::vector<int> SearchRange1(int A[], int n, int target) {
    int begin = 0, end = n - 1;
    std::vector<int> result;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (target == A[mid]) {
            int left = mid, right = mid;
            while (left >= 0 && A[left] == A[mid])
                left--;
            left++;
            while (right < n && A[right] == A[mid])
                right++;
            right--;
            result.push_back(left);
            result.push_back(right);
            return result;
        } else if (target < A[mid])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    result.push_back(-1);
    result.push_back(-1);
    return result;
}

int main() {
    std::vector<int> result;
    int a[] = {5, 7, 7, 8, 8, 10};
    result = SearchRange(a, 6, 7);
    assert(result[0] == 1);
    assert(result[1] == 2);
    result = SearchRange1(a, 6, 7);
    assert(result[0] == 1);
    assert(result[1] == 2);
    result = SearchRange(a, 6, 8);
    assert(result[0] == 3);
    assert(result[1] == 4);
    result = SearchRange1(a, 6, 8);
    assert(result[0] == 3);
    assert(result[1] == 4);
    result = SearchRange(a, 6, 9);
    assert(result[0] == -1);
    assert(result[1] == -1);
    result = SearchRange1(a, 6, 9);
    assert(result[0] == -1);
    assert(result[1] == -1);
    return 0;
}
