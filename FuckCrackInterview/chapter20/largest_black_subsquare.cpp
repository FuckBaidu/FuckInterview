/**
 * 20.11 in <Crack the code interview>.
 * Imagine you have a square matrix, where each cell is filled with either black or white.
 * Design an algorithm to find the maximum subsquare such that all four borders are filled
 * with black pixels
 */
#include <iostream>
void FindLargestBlackBorder(int **matrix, int n) {
    int **right = new int*[n], **down = new int*[n];
    for (int row = 0; row < n; row++) {
        right[row] = new int[n];
        down[row] = new int[n];
    }
    
    for (int row = 0; row < n; row++) {
        for (int col = n - 1; col >= 0; col--) {
            if (matrix[row][col] == 0) {
                right[row][col] = 0;
            } else {
                if (col == n - 1) {
                    right[row][col] = 1;
                } else {
                    right[row][col] = right[row][col + 1] + 1;
                }
            }
        }
    }
    for (int row = n - 1; row >= 0; row--) {
        for (int col = 0; col < n; col++) {
            if (matrix[row][col] == 0) {
                down[row][col] = 0;
            } else {
                if (row == n - 1) {
                    down[row][col] = 1;
                } else {
                    down[row][col] = down[row + 1][col] + 1;
                }
            }
        }
    }

    int max_border_len = 0;
    std::pair<int, int> upper_left(0, 0);
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (matrix[row][col] == 1) {
                int cur_border_len = std::min(right[row][col], down[row][col]);
                while (cur_border_len > max_border_len) {
                    std::pair<int, int> upper_right(row, col + cur_border_len - 1),
                        lower_right(row + cur_border_len - 1, col + cur_border_len - 1),
                        lower_left(row + cur_border_len - 1, col);
                    if (matrix[lower_right.first][lower_right.second] == 1
                            && right[lower_left.first][lower_left.second]
                            - right[lower_right.first][lower_right.second] + 1
                            == cur_border_len && down[upper_right.first][upper_right.second]
                            - down[lower_right.first][lower_right.second] + 1 == cur_border_len) {
                        max_border_len = cur_border_len;
                        upper_left = std::make_pair(row, col);
                        break;
                    }
                    cur_border_len--;
                }
            }
        }
    }

    if (max_border_len == 0) {
        std::cout << "Not Found." << std::endl;
    } else {
        std::cout << "The largest sub square matrix with black borders is." << std::endl;
        for (int row = upper_left.first; row < upper_left.first + max_border_len; row++) {
            for (int col = upper_left.second; col < upper_left.second + max_border_len; col++) {
                if (matrix[row][col] == 1)
                    std::cout << "B ";
                else
                    std::cout << "W ";
            }
            std::cout << std::endl;
        }
    }

    for (int row = 0; row < n; row++) {
        delete[] right[row];
        delete[] down[row];
    }
    delete[] right;
    delete[] down;
}

int main() {
    srand(time(NULL));
    int n = 20;
    int **matrix = new int*[n];
    for (int row = 0; row < n; row++) {
        matrix[row] = new int[n];
        for (int col = 0; col < n; col++) {
            matrix[row][col] = rand() % 3 == 0? 0 : 1;
        }
    }
    std::cout << "The Original matrix:" << std::endl;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (matrix[row][col] == 1)
                std::cout << "B ";
            else
                std::cout << "W ";
        }
        std::cout << std::endl;
    }
    FindLargestBlackBorder(matrix, n);
    for (int row = 0; row < n; row++)
        delete[] matrix[row];
    delete[] matrix;
    return 0;
}
