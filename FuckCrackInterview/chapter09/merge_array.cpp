/**
 * 9.1 in <Crack the code interview>.
 * You are given two sorted arrays, A and B, and A has a large enough buffer at
 * the end to hold B. Write a method to merge B into A.
 */
#include "util.h"
void _Merge(int A[], int B[], int m, int n) {
    int k = m + n -1;
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j])
            A[k--] = A[i--];
        else
            A[k--] = B[j--];
    }

    while (j >= 0)
        A[k--] = B[j--];
}

int main() {
    int A[10] = {1, 3, 5, 7, 9, 11, 13};
    int B[3] = {2, 4, 6};
    PrintArray(A, 7);
    PrintArray(B, sizeof(B) / sizeof(int));
    _Merge(A, B, 7, 3);
    PrintArray(A, sizeof(A) / sizeof(int));
    return 0;
}
