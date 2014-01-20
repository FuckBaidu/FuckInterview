/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones
 * and return its area.
 */
#include <vector>
#include <stack>
#include <assert.h>
int MaximalRectangle(const std::vector< std::vector<char> > &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    int m = matrix.size(), n = matrix[0].size(), max_area = 0;
    std::vector<int> count_ones(n, 0);
    for (int i = 0; i < m; i++) {
        std::stack< std::pair <int, int> > stack;
        for (int j = 0; j <= n; j++) {
            if (j < n) {
                if (matrix[i][j] == '1')
                    count_ones[j]++;
                else
                    count_ones[j] = 0;
            }
            int cur_height = j == n ? 0 : count_ones[j];
            while (!stack.empty() && cur_height < stack.top().second) {
                std::pair<int, int> top = stack.top();
                stack.pop();
                int cur_area;
                if (stack.empty())
                    cur_area = top.second * j;
                else
                    cur_area = top.second * (j - stack.top().first - 1);
                if (max_area < cur_area)
                    max_area = cur_area;
            }
            stack.push(std::make_pair(j, cur_height));
        }
    }
    return max_area ;
}

int main() {
    char a[][4] = {{'0', '1', '1', '1'}, {'0', '1', '1', '1'},
                   {'0', '1', '1', '0'}, {'0', '1', '1', '0'}};
    std::vector< std::vector<char> > matrix;
    for (int i = 0; i < 4; i++) {
        std::vector<char> tmp(a[i], a[i] + 4);
        matrix.push_back(tmp);
    }
    assert(MaximalRectangle(matrix) == 8);
    return 0;
}
