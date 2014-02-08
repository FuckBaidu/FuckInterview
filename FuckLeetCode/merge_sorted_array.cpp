/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space to hold additional elements from B. The number of elements
 * initialized in A and B are m and n respectively.
 */
#include <iostream>
void Merge(int A[], int m, int B[], int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 || j >= 0) {
        int a = i >= 0 ? A[i] : INT_MIN;
        int b = j >= 0 ? B[j] : INT_MIN;
        if (a > b) {
            A[k--] = a;
            i--;
        } else {
            A[k--] = b;
            j--;
        }
    }
}

int main() {
    int m = 10, n = 5;
    int *a = new int[m];
    int *b = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i * 2;
        b[i] = i * 2 + 1;
    }
    std::cout << "input a:";
    for (int i = 0; i < n; i++) 
        std::cout << a[i] << " ";
    std::cout << std::endl;
    std::cout << "input b:";
    for (int i = 0; i < n; i++) 
        std::cout << b[i] << " ";
    std::cout << std::endl;
    Merge(a, n, b, n);
    std::cout << "output:";
    for (int i = 0; i < m; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}
