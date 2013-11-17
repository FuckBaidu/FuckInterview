/**
 * 19.7 in <Crack the code interview>.
 * You are given an array of integers(both positive and negative). Find the 
 * continuous sequence with the largest sum.
 * Example:
 * Input: {2, -8, 3, -2 , 4, -10}
 * Output: {3, -2, 4};
 */
#include <vector>
#include <iostream>
#include <assert.h>
std::pair<int, int> LargestSum(std::vector<int> &a) {
    assert(a.size() != 0);
    std::pair<int, int> result(0, 0);
    int max_sum = a[0], cur_sum = 0, j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (cur_sum < 0) {
            j = i;
            cur_sum = 0;
        }
        cur_sum += a[i];
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
            result = std::make_pair(j, i);
        }
    }
    return result;
}

void Test(int *array, int len) {
    std::vector<int> a(array, array + len);
    std::cout << "Input: ";
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    std::pair<int, int> result = LargestSum(a);
    std::cout << "Output: ";
    for (int i = result.first; i <= result.second; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main () {
    int a[] = {2, -8, 3, -2 , 4, -10};
    Test(a, sizeof(a) / sizeof(int));
    int b[] = {-2, 8, 3, -2 , 4, -10};
    Test(b, sizeof(b) / sizeof(int));
    int c[] = {-8, -3, -2 , -4, -10};
    Test(c, sizeof(c) / sizeof(int));
    return 0;
}
