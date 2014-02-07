/*
 * Problem 1:
 *Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

 For example,
 Given the following matrix:

 [
   [ 1, 2, 3 ],
   [ 4, 5, 6 ],
   [ 7, 8, 9 ]
 ]
    You should return [1,2,3,6,9,8,7,4,5]

    Problem 2:
    Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

    For example,
    Given n = 3,

    You should return the following matrix:
    [
     [ 1, 2, 3 ],
     [ 8, 9, 4 ],
     [ 7, 6, 5 ]
    ]
 */
#include <vector>
#include <iostream>
std::vector<int> SpiralOrder(std::vector< std::vector<int> > &matrix) {
    std::vector<int> result;
    if (!matrix.empty() && !matrix[0].empty()) {
        int m = matrix.size(), n = matrix[0].size(), row = 0, col = 0;
        bool is_reverse = false;
        for (int i = 0; i < std::min(m, n); i++) {
            int step = is_reverse ? -1 : 1;
            int end_row = is_reverse ? i / 2 :  m - i / 2;
            int end_col = is_reverse ? i / 2 - 1:  n - i / 2;
            while (col != end_col) {
                result.push_back(matrix[row][col]);
                col += step;
            }
            col -= step;
            row += step;
            while (row != end_row) {
                result.push_back(matrix[row][col]);
                row += step;
            }
            col -= step;
            row -= step;
            is_reverse = !is_reverse;
        }
    }
    return result;
}

std::vector< std::vector<int> > GenerateMatrix(int n) {
    std::vector< std::vector<int> > result(n, std::vector<int>(n));
    int row = 0, col = 0, num = 1;
    bool is_reverse = false;
    for (int i = 0; i < n; i++) {
        int step = is_reverse ? -1 : 1;
        int end_row = is_reverse ? i / 2 :  n - i / 2;
        int end_col = is_reverse ? i / 2 - 1:  n - i / 2;
        while (col != end_col) {
            result[row][col] = num++;
            col += step;
        }
        col -= step;
        row += step;
        while (row != end_row) {
            result[row][col] = num++; 
            row += step;
        }
        col -= step;
        row -= step;
        is_reverse = !is_reverse;
    }
    return result;
}

int main() {
    int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector< std::vector<int> > matrix;
    std::cout << "Input:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::vector<int> tmp(a[i], a[i] + 3);
        matrix.push_back(tmp);
        for (int j = 0; j < 3; j++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
    std::vector<int> output = SpiralOrder(matrix);
    std::cout << "Output:" << std::endl;
    for (int i = 0; i < output.size(); i++)
        std::cout << output[i] << " ";
    std::cout << std::endl;

    matrix = GenerateMatrix(4);
    std::cout << "Generate matrix n == 4"<< std::endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}
