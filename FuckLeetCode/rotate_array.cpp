/*
 * Rotate a one-dimensional array of n elements to the right by k steps. 
 * For instance, with n=7 and k=3, the array {a, b, c, d, e, f, g} is rotated to {e, f, g, a, b, c,
 * d}.
 */
#include <iostream>
void ReverseString(char *array, int n) {
    int i = 0, j = n - 1;
    while (i < j)
        std::swap(array[i++], array[j--]);
}

void Rotate(char *array, int n, int k) {
    if (!array || n <= 0)
        return;
    k = k % n;
    if (k == 0)
        return;
    //reverse entire string
    ReverseString(array, n);
    //reverse first half of string
    ReverseString(array, k);
    //reverse second half of string
    ReverseString(array + k, n - k);
}

void Test(char *array, int n, int k) {
    std::cout << "Input:";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    Rotate(array, n, k);
    std::cout << "k:" << k << ",Output:";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}
int main() {
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    Test(a, sizeof(a) / sizeof(char), 7);
    Test(a, sizeof(a) / sizeof(char), 3);
    Test(a, sizeof(a) / sizeof(char), 5);
    return 0;
}
