/*
 * Given two sorted arrays A, B of size m and n respectively. Find the k-th smallest element in the
 * union of A and B. You can assume that there are no duplicate elements.
 */
#include <assert.h>
#include <algorithm>
int FindKthNumber(int A[], int m, int B[], int n, int k, int begin, int end) {
    if (begin > end) {
        // Not found in A, go to search array B
        return FindKthNumber(B, n, A, m, k, std::max(0, k - 1 - m), std::min(n - 1, k - 1));
    } else {
        int i = begin + (end - begin) / 2;
        int j = k - 1 - i;
        if (j > 0 && A[i] < B[j - 1])
            return FindKthNumber(A, m, B, n, k, i + 1, end);
        else if (j < n && A[i] > B[j])
            return FindKthNumber(A, m, B, n, k, begin, i - 1);
        else
            return A[i];
    }
}

int FindKthNumber(int A[], int m, int B[], int n, int k) {
    if ((m == 0 && n == 0) || k <= 0 || k > m + n)
        return -1;
    // narrow the begin and end to accelerate the find process
    return FindKthNumber(A, m, B, n, k, std::max(0, k - 1 - n), std::min(m - 1, k - 1));
}

double FindMedian(int A[], int m, int B[], int n) {
    int k = (m + n + 1) / 2;
    double median = FindKthNumber(A, m, B, n, k);
    if (!((m + n) & 1)) {
        double median_1 = FindKthNumber(A, m, B, n, k + 1);
        median = (median + median_1) / 2;
    }
    return median;
}

double FindMedian1(int A[], int m, int B[], int n, int begin, int end) {
    int mid = (m + n - 1) / 2;
    if (begin > end) {
        return FindMedian1(B, n, A, m, std::max(0, mid - m), std::min(n - 1, mid));
    } else {
        int i = begin + (end - begin) / 2;
        int j = mid - i;
        if (j > 0 && A[i] < B[j - 1]) {
            return FindMedian1(A, m, B, n, i + 1, end);
        } else if (j < n && A[i] > B[j]) {
            return FindMedian1(A, m, B, n, begin, i - 1);
        } else {
            if ((m + n) & 1) {
                return A[i];
            } else {
                int other;
                if (i < m - 1 && j < n)
                    other = std::min(A[i + 1], B[j]);
                else if (j == n)
                    other = A[i + 1];
                else
                    other = B[j];
                return ((double)A[i] + other) / 2;
            }
        }
    }
}
double FindMedian1(int A[], int m, int B[], int n) {
    if (m == 0 && n == 0)
        return -1;
    int mid = (m + n - 1) / 2;
    return FindMedian1(A, m, B, n, std::max(0, mid - n), std::min(m - 1, mid));
}

int main() {
    int empty[] = {};
    int a1[] = {4, 5, 6}, a2[] = {4, 5, 6, 7};
    int b1[] = {1, 2 ,3};
    assert(FindMedian1(empty, 0, empty, 0) == -1);
    assert(FindMedian(empty, 0, empty, 0) == -1);
    assert(FindMedian1(empty, 0, a1, 3) == 5);
    assert(FindMedian(empty, 0, a1, 3) == 5);
    assert(FindMedian1(empty, 0, a2, 4) == 5.5);
    assert(FindMedian(empty, 0, a2, 4) == 5.5);
    assert(FindMedian1(a2, 4, b1, 3) == 4);
    assert(FindMedian(a2, 4, b1, 3) == 4);
    assert(FindMedian1(a1, 3, b1, 3) == 3.5);
    assert(FindMedian(a1, 3, b1, 3) == 3.5);
    assert(FindMedian1(b1, 3, a2, 4) == 4);
    assert(FindMedian(b1, 3, a2, 4) == 4);
    int a3[] = {1, 5, 7, 8, 9, 10, 11}, b2[] = {2, 5}, b3[]= {2, 3, 8, 10, 12};
    assert(FindMedian1(a3, 7, b2, 2) == 7);
    assert(FindMedian(a3, 7, b2, 2) == 7);
    assert(FindMedian1(a3, 7, b3, 5) == 8);
    assert(FindMedian(a3, 7, b3, 5) == 8);

    return 0;
}
