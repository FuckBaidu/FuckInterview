/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given
 * number, target. Return the sum of the three integers. You may assume that each input would have
 * exactly one solution.
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
#include <vector>
#include <algorithm>
#include <assert.h>
int ThreeSumClosest(std::vector<int> &num, int target) {
    int diff = INT_MAX, sum = 0;
    std::sort(num.begin(), num.end());
    for (int i = 0; i < (int)num.size() - 2; i++) {
        int begin = i + 1, end = (int)num.size() - 1;
        while (begin < end) {
            int cur_sum = num[i] + num[begin] + num[end];
            if (cur_sum == target) {
                return target;
            } else {
                if (std::abs(cur_sum - target) < diff) {
                    diff = std::abs(cur_sum - target);
                    sum = cur_sum;
                }
                if (cur_sum > target)
                    end--;
                else
                    begin++;
            }
        }
    }
    return sum;
}

int main() {
    int a[] = {-1, 2, 1, -4};
    std::vector<int> num(a, a + 4);
    assert(ThreeSumClosest(num, 1) == 2);
}
