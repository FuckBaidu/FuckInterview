/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers (both index1 and
 * index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */
#include <vector>
#include <ext/hash_map>
#include <assert.h>

typedef __gnu_cxx::hash_map< int, int > HashMap;
std::vector<int> TwoSum(std::vector<int> &numbers, int target) {
    std::vector<int> result;
    HashMap hash_map;
    for (int i = 0; i < numbers.size(); i++)
        hash_map[numbers[i]] = i + 1;
    for (int i = 0; i < numbers.size(); i++) {
        int other = target - numbers[i];
        if (hash_map.count(other) && hash_map[other] != i + 1) {
            result.push_back(i + 1);
            result.push_back(hash_map[other]);            
            break;
        }
    }
    return result;
}

int main() {
    int a[] = {2, 1, 4, 4, 56, 21, 0};
    std::vector<int> numbers(a, a + sizeof(a) / sizeof(int));
    std::vector<int> result = TwoSum(numbers, 8);
    assert(result[0] == 3);
    assert(result[1] == 4);
    result = TwoSum(numbers, 5);
    assert(result[0] == 2);
    assert(result[1] == 4);
    return 0;
}
