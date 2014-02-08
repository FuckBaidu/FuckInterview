/*
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */
#include <iostream>
int RemoveDuplicates(int A[], int n) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (i + 2 < n && A[i + 1] == A[i] && A[i + 2] == A[i]) 
            i++;
        A[++j] = A[i];
    }
    return j + 1;
}

int main() {
    int a[] = {1,1,1,2,2,3};
    int n = sizeof(a) / sizeof(int);
    std::cout << "input:";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    n = RemoveDuplicates(a, n);
    std::cout << "output:";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}
