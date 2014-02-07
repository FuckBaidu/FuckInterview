/**
 * 9.6 in <Crack the code interview>.
 * Give a matrix in which each row and column is sorted. Write a method to find
 * an element in it
 */
#include <iostream>
std::pair<int, int> SearchYouthMatrix(int **matrix, int n, int key) {
    std::pair<int, int> result(-1, -1);
    std::pair<int, int> cur(0, n - 1);
    while (cur.first < n && cur.second >= 0) {
        if (key == matrix[cur.first][cur.second]) {
            result = cur;
            break;
        } else if (key > matrix[cur.first][cur.second]) {
            cur.first++;
        } else {
            cur.second--;
        }
    }
    return result;
}

bool SearchYouthMatrix(int **matrix, int left, int right, int up, int down,
                       int target, std::pair<int, int> &result) {
    if (left > right || up > down)
        return false;
    int mid_col = left + (right - left) / 2, begin_row = up, end_row = down;
    while (begin_row <= end_row) {
        int mid_row = begin_row + (end_row - begin_row) / 2;
        if (matrix[mid_row][mid_col] == target) {
            result.first = mid_row;
            result.second = mid_col;
            return true;
        } else if (target < matrix[mid_row][mid_col]) {
            end_row = mid_row - 1;
        } else {
            begin_row = mid_row + 1;
        }
    }
    return SearchYouthMatrix(matrix, left, mid_col - 1, begin_row, down, target, result)
           || SearchYouthMatrix(matrix, mid_col + 1, right, up, end_row, target, result);
}

// Still O(n)
bool SearchYouthMatrix(int **matrix, int m, int n, int target, std::pair<int, int> &result) {
    return SearchYouthMatrix(matrix, 0, n - 1, 0, m -1, target, result);
}

void Test(int **matrix, int m, int n, int target) {
    std::pair<int, int> result;
    bool res = SearchYouthMatrix(matrix, m, n, target, result);
    if (!res)
        std::cout << "Not found:" << target << std::endl;
    else
        std::cout << "Found:" << target << ",at (" << result.first << "," << result.second << ")" << std::endl;
}

int main() {
    int **matrix = new int*[3];
    for (int i = 0; i < 3; i++)
        matrix[i] = new int[4];
    int a[] = {1, 3, 5, 7}, b[] = {10, 11, 16, 20}, c[] = {23, 30, 34, 50};
    memcpy(matrix[0], a, 4 * sizeof(int));
    memcpy(matrix[1], b, 4 * sizeof(int));
    memcpy(matrix[2], c, 4 * sizeof(int));
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            Test(matrix, 3, 4, matrix[i][j]);
    Test(matrix, 3, 4, 17);
    Test(matrix, 3, 4, 22);
    Test(matrix, 3, 4, 32);
    Test(matrix, 3, 4, 60);
    return 0;
}
