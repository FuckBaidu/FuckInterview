/*
 * Given an array of integers, every element appears three times except for one. Find that single one.
   Note:
   Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
http://oj.leetcode.com/problems/single-number-ii/
 */
#include <ext/hash_map>
#include <iostream>

int SingleNumber(int A[], int n) {
    int result = 0;
    for (int i = 0; i < sizeof(int) * 8; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1)
                count++;
        }
        if (count % 3 != 0)
            result |= (1 << i);
    }
    return result;
}

int SingleNumber1(int A[], int n) {
    __gnu_cxx::hash_map<int, int> counts;
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += A[i];
        if (counts.count(A[i]) == 0)
            counts[A[i]] = 0;
        counts[A[i]]++;
        if (counts[A[i]] == 3)
            result -= 3 * A[i];
    }
    return result;
}

void Test(int A[], int n) {
    std::cout << "Input:";
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    std::cout << "Single one:" << SingleNumber(A, n) << std::endl;
}

int main() {
    int a[] = {2, 5, 2, 2};
    Test(a, sizeof(a)/sizeof(int));
    int b[] = {0, 1, 1, 99, 0, 1, 0};
    Test(b, sizeof(b)/sizeof(int));
    return 0;
}
