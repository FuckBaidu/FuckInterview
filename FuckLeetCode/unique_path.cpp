/*
 *A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
  How many possible unique paths are there?
  Above is a 3 x 7 grid. How many possible unique paths are there?
 Note: m and n will be at most 100.
 */
#include <assert.h>
#include <vector>
int UniquePaths(int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    std::vector<int> cur(n, 1), prev(n);
    for (int i = 1; i < m; i++) {
        std::swap(prev, cur);
        cur[0] = 1;
        for (int j = 1; j < n; j++)
            cur[j] = cur[j - 1] + prev[j];
    }
    return cur.back();
}

int main() {
    assert(UniquePaths(3, 3) == 6);
    return 0;
}
