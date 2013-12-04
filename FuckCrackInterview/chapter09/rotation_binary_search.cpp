/**
 * 9.3 in <Crack the code interview>.
 * Given a sorted array of n integers that has been rotated an unknown number of times,
 * give an O(logn) algorithm that find elements in the array
 */
#include <iostream>
int RotationBinarySearch(int *A, int len, int key) {
    int begin = 0, end = len - 1;
    int pos = -1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2; // in case of overflow
        if (A[mid] == key) {
            pos = mid;
            break;
        }
        // first part is sorted
        if (A[begin] < A[mid]) {
            if (A[begin] <= key && key < A[mid])
                end = mid - 1;
            else
                begin = mid + 1;
        } else if (A[begin] > A[mid]) {
            // second part is sorted
            if (A[mid] < key && key <= A[end])
                begin = mid + 1;
            else
                end = mid - 1;
        } else
            begin++;
    }
    return pos;
}

void Test(int *A, int len, int n) {
    int index = RotationBinarySearch(A, len, n);
    if (index == -1)
        std::cout << "Not Found " << n << std::endl;
    else
        std::cout << "Found " << n << " at " << index << std::endl;
}

int main() {
    int A[] = {15, 16, 19, 20, 25, 2, 3, 4, 5, 7, 10, 12};
    Test(A, sizeof(A) / sizeof(int), 13);
    Test(A, sizeof(A) / sizeof(int), 5);
    Test(A, sizeof(A) / sizeof(int), 7);
    Test(A, sizeof(A) / sizeof(int), 16);
    Test(A, sizeof(A) / sizeof(int), 19);
    Test(A, sizeof(A) / sizeof(int), 1);
    int b[] = {5, 1, 3};
    Test(b, 3, 3);
    Test(b, 3, 5);
    int c[] = {1, 1, 3, 1};
    Test(c, 4, 3);
    int d[] = {1, 3, 5};
    Test(d, 3, 1);
    int e[] = {1, 1, 1, 3, 1};
    Test(e, 5, 3);
    int f[] = {1, 3, 1, 1, 1};
    Test(f, 5, 3);
    return 0;
}
