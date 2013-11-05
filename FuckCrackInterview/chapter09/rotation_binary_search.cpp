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
        int mid = (begin + end) / 2;
        if (A[mid] == key) {
            pos = mid;
            break;
        }

        if (A[begin] <= A[mid] && A[mid] <= A[end]) {
            if (key < A[mid])
                end = mid - 1;
            else
                begin = mid + 1;
        } else {
            if ((key < A[mid] && key >= A[begin]) || (key > A[mid] && key >= A[end]))
                end = mid - 1;
            else
                begin = mid + 1;
        }
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
    return 0;
}
