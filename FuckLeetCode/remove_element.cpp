/*
 * Given an array and a value, remove all instances of that value in place and return the new
 * length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
#include <iostream>
int RemoveElement(int A[], int n, int elem) {
    int j = -1;
    for (int i = 0; i < n; i++)
        if (A[i] != elem)
            A[++j] = A[i];
    return j + 1;
}

int main() {
    srand(time(NULL));
    int n = 10;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = rand() % 3 + 1;
    std::cout << "input:";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    for (int i = 1; i <= 3; i++) {
        std::cout << "Remove " << i << ":";
        n = RemoveElement(a, n, i);
        for (int j = 0; j < n; j++)
            std::cout << a[j] << " ";
        std::cout << std::endl;
    }
}
