/*
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations
 * in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the co2 mbination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination must be in non-descending order
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 */
#include <vector>
#include <iostream>
void CombinationSumHelper(std::vector<int> &num, int idx, int target,
                    std::vector<int> &path, std::vector< std::vector<int> > &results) {
    if (target == 0) {
        results.push_back(path);
    } else if (target > 0) {
        for (int i = idx; i < num.size(); i++) {
            path.push_back(num[i]);
            CombinationSumHelper(num, i + 1, target - num[i], path, results);
            path.pop_back();
            while (i < num.size() - 1 && num[i + 1] == num[i])
                i++;
        }
    }
}

std::vector<std::vector<int> > CombinationSum2(std::vector<int> &num, int target) {
    std::sort(num.begin(), num.end());
    std::vector< std::vector<int> > results;
    std::vector<int> path;
    if (!num.empty())
        CombinationSumHelper(num, 0, target, path, results);
    return results;
}

void Test(int *array, int len, int target) {
    std::cout << "Target: " << target;
    std::cout << "Candidata:";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    std::vector<int> num(array, array + len);
    std::vector< std::vector<int> > results = CombinationSum2(num, target);
    std::cout << "Output:" << std::endl;
    for (int i = 0; i < results.size(); i++) {
        std::cout << "[";
        for (int j = 0; j < results[i].size(); j++)
            std::cout << results[i][j] << (j == results[i].size() - 1 ? "" : ",");
        std::cout << "]" << std::endl;
    }
}

int main() {
    int a[] = {1, 2};
    Test(a, sizeof(a) / sizeof(int), 4);
    int b[] = {10, 1, 2, 7, 6, 1, 5};
    Test(b, sizeof(b) / sizeof(int), 8);
    return 0;
}
