/*
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.

 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,2], a solution is:
 * 
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 */
#include <vector>
#include <iostream>
void GetSubSets(const std::vector<int> &S, int start, std::vector<int> &result, std::vector< std::vector<int> > &results) {
    if (start == S.size())
        return;
    for (int i = start; i < S.size(); i++) {
        result.push_back(S[i]);
        results.push_back(result);
        GetSubSets(S, i + 1, result, results);
        result.pop_back();
        while (i < S.size() - 1 && S[i + 1] == S[i])
            i++;
    }
}

std::vector< std::vector<int> > SubsetsWithDup(std::vector<int> &S) {
    std::vector< std::vector<int> > results;
    if (!S.empty()) {
        std::sort(S.begin(), S.end());
        // add empty set
        std::vector<int> result;
        results.push_back(result);
        GetSubSets(S, 0, result, results);
    }
    return results;
}

int main() {
    std::vector<int> a;
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    a.push_back(2);
    std::vector< std::vector<int> > result = SubsetsWithDup(a);
    std::cout << "Input:" << std::endl;
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "Output: size = " << result.size() << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}
