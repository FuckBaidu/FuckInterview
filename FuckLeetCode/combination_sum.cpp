/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C
 * where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of ti2 mes.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination must be in non-descending order.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7
 * A solution set is:
 * [7]
 * [2, 2, 3]
 */
#include <vector>
#include <iostream>
void CombinationSumHelper(const std::vector<int> &candidates, int idx, int target,
                          std::vector<int> &path, std::vector< std::vector<int> > &results) {
    if (target == 0) {
        results.push_back(path);
        return;
    } else if (target < 0) {
        return;
    } else {
        for (int i = idx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            CombinationSumHelper(candidates, i, target - candidates[i], path, results);
            path.pop_back();
        }
        return;
    }
}

std::vector<std::vector<int> > CombinationSum(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> path;
    std::vector< std::vector<int> > results;
    if (!candidates.empty())
        CombinationSumHelper(candidates, 0, target, path, results);
    return results;
}

void Test(int *array, int len, int target) {
    std::cout << "Target: " << target;
    std::cout << "Candidata:";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    std::vector<int> num(array, array + len);
    std::vector< std::vector<int> > results = CombinationSum(num, target);
    std::cout << "Output:" << std::endl;
    for (int i = 0; i < results.size(); i++) {
        std::cout << "[";
        for (int j = 0; j < results[i].size(); j++)
            std::cout << results[i][j] << (j == results[i].size() - 1 ? "" : ",");
        std::cout << "]" << std::endl;
    }
}

int main() {
    int a[] = {2, 3, 6, 7};
    Test(a, sizeof(a) / sizeof(int), 7);
    return 0;
}
