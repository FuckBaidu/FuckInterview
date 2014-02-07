/*
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 */
#include <vector>
#include <assert.h>
int UniquePathsWithObstacles(std::vector< std::vector<int> > &obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty())
        return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<int> cur(n, 0), prev(n);
    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1)
            break;
        cur[i] = 1;
    }
    for (int i = 1; i < m; i++) {
         std::swap(prev, cur);
         cur[0] = obstacleGrid[i][0] == 1 ? 0 : prev[0];
         for (int j = 1; j < n; j++)
             if (obstacleGrid[i][j] == 1)
                 cur[j] = 0;
             else
                 cur[j] = cur[j - 1] + prev[j];
    }
    return cur.back();
}

int main() {
    int a[][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    std::vector< std::vector<int> > grid;
    for (int i = 0; i < 3; i++) {
        std::vector<int> tmp(a[i], a[i] + 3);
        grid.push_back(tmp);
    }
    assert(UniquePathsWithObstacles(grid) == 2);
    return 0;
}
