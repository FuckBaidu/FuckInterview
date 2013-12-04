/**
 * Given an array S of n integers, are there elements a, b, c, 
 * and d in S such that a + b + c + d = target
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * lements in a quadruplet (a,b,c,d) must be in non-descending order.  (ie, a <= b <= c <= d)
 * The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 * solution set is:
 * (-1,  0, 0, 1)
 * (-2, -1, 1, 2)
 *  (-2,  0, 0, 2)
 * http://oj.leetcode.com/problems/4sum/
 */
#include <iostream>
#include <vector>
#include <algorithm>

void FourSum(int target, std::vector<int> &num, std::vector< std::vector<int> > &results) {
    std::sort(num.begin(), num.end());
    for (int i = 0; i < (int)num.size() - 3; i++) {
        if (i > 0 && num[i] == num[i - 1])
            continue;
        for (int j = i + 1; j < (int)num.size() - 2; j++) {
            if (j > i + 1 && num[j] == num[j - 1])
                continue;
            int cur_sum = target - (num[i] + num[j]), m = j + 1, n = num.size() - 1;
            while (m < n) {
                if (cur_sum == num[m] + num[n]) {
                    results.push_back(std::vector<int>());
                    results.back().push_back(num[i]);
                    results.back().push_back(num[j]);
                    results.back().push_back(num[m]);
                    results.back().push_back(num[n]);
                    do {
                        m++;
                    } while (m < n && num[m] == num[m - 1]);
                } else if (cur_sum < num[m] + num[n]) {
                    do {
                        n--;
                    } while (n > m && num[n] == num[n + 1]);
                } else {
                    do {
                        m++;
                    } while (m < n && num[m] == num[m - 1]);
                }
            }
        }
    }
}

void Test(int target, int *array, int len) {
    std::vector<int> input(array, array + len);
    std::vector< std::vector<int> > results;
    FourSum(target, input, results);
    std::cout << "Target:"<< target << ",Input:";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    std::cout << "Output:";
    for (int i = 0; i < results.size(); i++) {
        std::cout << "(";
        for (int j = 0; j < results[i].size(); j++) {
            std::cout << results[i][j];
            if (j != results[i].size() - 1)
                std::cout << ",";
        }
        std::cout << ")";
        std::cout << " ";
    }
    std::cout << std::endl;
}

int main() {
    int a[] = {-1, 0, 2, -1, 1, -2, 1, 2, 0, -2};
    Test(0, a, sizeof(a) /sizeof(int));
    int b[] = {};
    Test(0, b, sizeof(b) /sizeof(int));
    return 0;
}
