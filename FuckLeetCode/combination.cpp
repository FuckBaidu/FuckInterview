/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */
#include <iostream>
#include <vector>
void CombinationHelper(int cur, int n, int idx, std::vector<int> &result, std::vector< std::vector<int> > &results) {
    if (idx == result.size()) {
        results.push_back(result);
        return;
    }
    for (int i = cur; i <= n; i++) {
        result[idx] = i;
        CombinationHelper(i + 1, n, idx + 1, result, results);
    }
}

std::vector<std::vector<int> > Combination(int n, int k) {
    std::vector<int> result;
    result.resize(k);
    std::vector< std::vector<int> > results;
    CombinationHelper(1, n, 0, result, results);
    return results;
}

void Test(int n, int k) {
    std::cout << "n: " << n << ",k: " << k << std::endl;
    std::vector< std::vector<int> > results = Combination(n, k);
    std::cout << "Output:" << std::endl;
    for (int i = 0; i < results.size(); i++) {
        std::cout << "[";
        for (int j = 0; j < results[i].size(); j++)
            std::cout << results[i][j] << (j == results[i].size() - 1 ? "" : ",");
        std::cout << "]" << std::endl;
    }
}

int main() {
    Test(4, 2);
    Test(5, 3);
    return 0;
}
