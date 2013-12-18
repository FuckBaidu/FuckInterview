/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */
#include <vector>
#include <algorithm>
#include <iostream>

// Swap
void GetPermutations(std::vector<int> &num, int start, std::vector<int> &path, std::vector< std::vector<int> > &result) {
    if (start == num.size()) {
        result.push_back(path);
    } else {
        for (int i = start; i < num.size(); i++) {
            bool has_same = false;
            for (int j = start; j < i; j++) {
                if (num[j] == num[i]) {
                    has_same = true;
                    break;
                }
            }
            if (has_same)
                continue;
            std::swap(num[start], num[i]);
            path[start] = num[start];
            GetPermutations(num, start + 1, path, result);
            // Restore
            std::swap(num[start], num[i]);
        }
    }
}

std::vector< std::vector<int> > GetPermutations(std::vector<int> &num) {
    std::vector< std::vector<int> > result;
    std::vector<int> path(num.size());
    if (!num.empty())
        GetPermutations(num, 0, path, result);
    return result;
}

//Remove duplicates + Counts + DFS
void GetPermutations1(std::vector<int> &set, std::vector<int> &counts, std::vector<int> &path, std::vector< std::vector<int> > &result) {
    if (path.size() == path.capacity()) {
        result.push_back(path);
    } else {
        for (int i = 0; i < set.size(); i++) {
            if (counts[i] > 0) {
                path.push_back(set[i]);
                counts[i]--;
                GetPermutations1(set, counts, path, result);
                // Restore
                path.pop_back();
                counts[i]++;
            }
        }
    }
}

std::vector< std::vector<int> > GetPermutations1(std::vector<int> &num) {
    std::vector< std::vector<int> > result;
    if (!num.empty()) {
        std::vector<int> path;
        path.reserve(num.size());
        std::vector<int> counts, set;
        std::sort(num.begin(), num.end());
        int count = 1, cur = num[0];
        for (int i = 1; i < num.size(); i++) {
            if (num[i] != cur) {
                counts.push_back(count);
                set.push_back(cur);
                cur = num[i];
                count = 0;
            }
            count++;
        }
        set.push_back(cur);
        counts.push_back(count);
        GetPermutations1(set, counts, path, result);
    }
    return result;
}

// DFS
void GetPermutations2(std::vector<int> &num, std::vector<int> &visited, std::vector<int> &path, std::vector< std::vector<int> > &result) {
    if (path.size() == path.capacity()) {
        result.push_back(path);
    } else {
        for (int i = 0; i < num.size(); i++) {
            if (visited[i])
                continue;
            if (i > 0 && num[i - 1] == num[i] && visited[i - 1])
                continue;

            path.push_back(num[i]);
            visited[i] = true;
            GetPermutations2(num, visited, path, result);
            // Restore
            visited[i] = false;
            path.pop_back();
        }
    }
}

std::vector< std::vector<int> > GetPermutations2(std::vector<int> &num) {
    std::vector< std::vector<int> > result;
    if (!num.empty()) {
        std::vector<int> path;
        path.reserve(num.size());
        std::sort(num.begin(), num.end());
        std::vector<int> visited(num.size(), 0);
        GetPermutations2(num, visited, path, result);
    }
    return result;
}

void Test(int *array, int len) {
    std::vector<int> input(array, array + len);
    std::cout << "Input:";
    for (int i = 0; i < input.size(); i++)
        std::cout << input[i];
    std::cout << std::endl;
    std::vector< std::vector<int> > result = GetPermutations(input);
    std::cout << "Output1, there are " << result.size() << " permutations:" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j];
        std::cout << std::endl;
    }

    result = GetPermutations1(input);
    std::cout << "Output2, there are " << result.size() << " permutations:" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j];
        std::cout << std::endl;
    }

    result = GetPermutations2(input);
    std::cout << "Output3, there are " << result.size() << " permutations:" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j];
        std::cout << std::endl;
    }
}


int main() {
    int a[] = {1, 2, 2};
    Test(a, 3);
    int b[] = {-1, 2, 0, -1, 1, 0, 1};
    Test(b, sizeof(b) / sizeof(int));
    return 0;
}
