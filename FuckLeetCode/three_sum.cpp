/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all
 * unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 * The solution set must not contain duplicate triplets.
 *
 * For example, given array S = {-1 0 1 2 -1 -4},
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 * http://oj.leetcode.com/problems/3sum/
 */
#include <iostream>
#include <vector>
#include <algorithm>

void ThreeSum(std::vector<int> &num, std::vector< std::vector<int> > &results) {
    std::sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
        if (i > 0 && num[i] == num[i - 1])
            continue;
        int cur_sum = (-1) * num[i];
        int begin = i + 1, end = num.size() - 1;
        while (begin < end) {
            if (cur_sum == num[begin] + num[end]) {
                results.push_back(std::vector<int>());
                results.back().push_back(num[i]);
                results.back().push_back(num[begin]);
                results.back().push_back(num[end]);
                do {
                    begin++;
                } while (begin < end && num[begin] == num[begin - 1]);
                do {
                    end--;
                } while (end > begin && num[end] == num[end + 1]);
            } else if (cur_sum < num[begin] + num[end])
                end--;
            else
                begin++;
        }
    }
}

void Test(int *array, int len) {
    std::vector<int> input(array, array + len);
    std::vector< std::vector<int> > results;
    ThreeSum(input, results);
    std::cout << "Input:";
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
    int a[] = {-1, 0, 1, 2, -1, -4};
    Test(a, sizeof(a) /sizeof(int));
    int b[] = {-1, 0, 1,-1, 2, 2, -1, -4};
    Test(b, sizeof(b) /sizeof(int));
    return 0;
}
