/*
 * Given a matrix (2D array) of m x n elements (m rows, n columns), write a function that prints the
 * elements in the array in a spiral manner
 * http://leetcode.com/2010/05/printing-matrix-in-spiral-order.html
 */
#include <iostream>
#define N_MAX 10
void PrintSpiral(int matrix[][N_MAX], int m, int n) {
    if (matrix == NULL || m == 0 || n == 0)
        return;
    bool is_forward = true;
    int start_row = 0, start_col = 0;
    int loop_count = std::min(m, n);
    for (int i = 0; i < loop_count; i++) {
        if (is_forward) {
            //Go right first then down
            int end_col = start_col + n - 1;
            int end_row = start_row + m - 1;
            while (start_col <= end_col) {
                std::cout << matrix[start_row][start_col] << " ";
                start_col++;
            }
            start_col--;
            start_row++;
            while (start_row <= end_row) {
                std::cout << matrix[start_row][start_col] << " ";
                start_row++;
            }
            start_row--;
            start_col--;
        } else {
            //Go left first then up
            int end_col = start_col - n + 1;
            int end_row = start_row - m + 1;
            while (start_col >= end_col) {
                std::cout << matrix[start_row][start_col] << " ";
                start_col--;
            }
            start_col++;
            start_row--;
            while (start_row >= end_row) {
                std::cout << matrix[start_row][start_col] << " ";
                start_row--;
            }
            start_row++;
            start_col++;
        }
        is_forward = !is_forward;
        m--;
        n--;
    }
    std::cout << std::endl;
}

void Test(int matrix[][N_MAX], int m, int n) {
    std::cout << "Matrix is:" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Print in spiral:" << std::endl;
    PrintSpiral(matrix, m, n);
}

int main() {
    int a[1][N_MAX] = {{1}};
    Test(a, 1, 1);
    int b[1][N_MAX] = {{1, 2}};
    Test(b, 1, 2);
    int c[3][N_MAX] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Test(c, 3, 3);
    int d[5][N_MAX] = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24}, {25, 26, 27, 28, 29, 30}};
    Test(d, 5, 6);
    return 0;
}
