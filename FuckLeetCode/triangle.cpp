/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to
 * adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the
 * total number of rows in the triangle.
 */
#include <vector>
int MinimumTotal(std::vector< std::vector<int> > &triangle) {
    if (triangle.empty())
        return 0;
    int min = INT_MAX, m = triangle.size();
    std::vector<int> min_path(m);
    min_path[0] = triangle[0][0];
    for (int i = 1; i < m; i++) {
        for (int j = i; j >= 0; j--) {
            if (j == 0)
                min_path[j] = min_path[j] + triangle[i][j];
            else if (j == i)
                min_path[j] = min_path[j - 1] + triangle[i][j];
            else
                min_path[j] = std::min(min_path[j], min_path[j - 1]) + triangle[i][j];
        }
    }
    for (int i = 0; i < min_path.size(); i++)
        if (min > min_path[i])
            min = min_path[i];
    return min;
}

int main() {
    std::vector< std::vector<int> > triangle;
    int tmp[][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    for (int i = 0; i < 4; i++) {
        std::vector<int> vec(tmp[i], tmp[i] + i + 1);
        triangle.push_back(vec);
    }
    assert(MinimumTotal(triangle) == 11);
    return 0;
}
