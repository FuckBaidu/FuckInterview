/*
 * Let A[1...n] be an array of n distinct numbers. If i < j and A[i] > A[j], then the
 * pair (i, j) is called an inversion of A.
 */
#include <assert.h>
#include <vector>
int Merge(std::vector<int> &A, int begin, int mid, int end) {
    std::vector<int> L(A.begin() + begin, A.begin() + mid + 1), R(A.begin() + mid + 1, A.begin() + end + 1);
    int i = 0, j = 0, k = begin, num = 0;
    while (i < L.size() || j < R.size()) {
        int left = i < L.size() ? L[i] : INT_MIN;
        int right = j < R.size() ? R[j] : INT_MIN;
        int cur;
        if (left <= right) {
            j++;
            cur = right;
        } else {
            i++;
            cur = left;
            num += R.size() - j;
        }
        A[k++] = cur;
    }
    return num;
}

int NumInversions(std::vector<int> &A, int begin, int end) {
    int num = 0;
    if (begin < end) {
        int mid = (begin + end) / 2;
        num += NumInversions(A, begin, mid);
        num += NumInversions(A, mid + 1, end);
        num += Merge(A, begin, mid, end);
    }
    return num;
}

int NumInversions(std::vector<int> &A) {
    return NumInversions(A, 0, A.size() - 1);
}

int main() {
    int a[] = {2, 3, 8, 6, 1};
    std::vector<int> A(a, a + 5);
    assert(NumInversions(A) == 5);
    int b[] = {5, 2, 4, 6, 1, 3};
    std::vector<int> B(b, b + 6);
    assert(NumInversions(B) == 9);
    return 0;
}
