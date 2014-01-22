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
void Solve(int n, int k, std::vector<int> &path, std::vector< std::vector<int> > &result) {
    if (path.size() == k) {
        result.push_back(path);
    } else {
        int start = path.empty() ? 1 : path.back() + 1;
        for (int i = start; i <= n - k + 1 + path.size(); i++) {
            path.push_back(i);
            Solve(n, k, path, result);
            path.pop_back();
        }
    }
}

std::vector< std::vector<int> > Combination(int n, int k) {
    std::vector< std::vector<int> > result;
    if (k > 0 && k <= n) {
        std::vector<int> path;
        Solve(n, k, path, result);
    }
    return result;
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
