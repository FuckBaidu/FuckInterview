/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right
 * which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */
#include <vector>
int MinPathSum(const std::vector< std::vector<int> > &grid) {
    if (grid.empty() || grid[0].empty())
        return 0;
    int m = grid.size(), n = grid[0].size();
    std::vector<int> cur(grid[0]), prev(n);
    for (int i = 1; i < n; i++)
        cur[i] += cur[i - 1];
    for (int i = 1; i < m; i++) {
        std::swap(prev, cur);
        cur[0] = prev[0] + grid[i][0];
        for (int j = 1; j < n; j++)
            cur[j] = std::min(cur[j - 1], prev[j]) + grid[i][j];
    }
    return cur.back();
}

int main() {
    return 0;
}
