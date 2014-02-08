/*
 * The set [1,2,3,?,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive
 */
#include <string>
#include <iostream>
std::string GetPermutation(int n, int k) {
    std::string result(n, '0');
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        result[i - 1] = '0' + i; 
        factorial *= i;
    }
    k = (k - 1) % factorial;
    for (int i = 0; i < n - 1; i++) {
        factorial /= (n - i);
        int j = k / factorial + i;
        char tmp = result[j];
        while (j > i) {
            result[j] = result[j - 1];
            j--;
        }
        result[i] = tmp;
        k = k % factorial;
    }
    return result;
}

int main() {
    for (int i = 1; i <= 30; i++)
        std::cout << "The " << i << "th permutation of 4 is " << GetPermutation(4, i) << std::endl;
    return 0;
}
