/*
 * There is an array A[N] of N numbers. You have to compose an array Output[N] such that Output[i]
 * will be equal to multiplication of all the elements of A[N] except A[i]. Solve it without
 * division operator and in O(n).
 *
 * For example Output[0] will be multiplication of A[1] to A[N-1] and Output[1] will be
 * multiplication of A[0] and from A[2] to A[N-1].
 *
 * Example:
 * A: {4, 3, 2, 1, 2}
 * OUTPUT: {12, 16, 24, 48, 24}
 * http://leetcode.com/2010/04/multiplication-of-numbers.html
 */
#include <iostream>
void MultiplyArray(const int *input, int n, int *output) {
    if (n <= 0 || input == NULL || output == NULL)
        return;
    // accumulate the multiplication results in output array
    output[0] = 1;
    for (int i = 1; i < n; i++)
        output[i] = output[i - 1] * input[i - 1];
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] = output[i] * right;
        right *= input[i];
    }
}

void Test(int *input, int n) {
    int *output = new int[n];
    std::cout << "Input:";
    for (int i = 0; i < n; i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
    MultiplyArray(input, n, output);
    std::cout << "Output:";
    for (int i = 0; i < n; i++)
        std::cout << output[i] << " ";
    std::cout << std::endl;
    delete[] output;
}

int main() {
    int a[] = {4};
    Test(a, 1);
    int b[] = {4, 3, 2};
    Test(b, 3);
    int c[] = {4, 3, 2, 1, 2};
    Test(c, 5);
    return 0;
}
