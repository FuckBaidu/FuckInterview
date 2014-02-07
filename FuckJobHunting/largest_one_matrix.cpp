/*
 * Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
 * For example, consider the below binary matrix.
 * 0  1  1  0  1
 * 1  1  0  1  0
 * 0  1  1  1  0
 * 1  1  1  1  0
 * 1  1  1  1  1
 * 0  0  0  0  0
 * The maximum square sub-matrix with all set bits is

 * 1  1  1
 * 1  1  1
 * 1  1  1
 */
#include <iostream>
void FindLargestSquareMatrix(int **matrix, int m, int n) {
    int **auxiliary = new int*[m];
    for (int i = 0; i < m; i++) {
        auxiliary[i] = new int[n];
        memset(auxiliary[i], 0, sizeof(int) * n);
    }
    
    int max_edge_len = 0;
    std::pair<int, int> max_sub_lower_right(0, 0);
    for (int i = 0; i < m; i++) {
        auxiliary[i][0] = matrix[i][0];
        if (matrix[i][0] == 1)
            max_edge_len = 1;
    }
    for (int i = 0; i < n; i++) {
        auxiliary[0][i] = matrix[0][i];
        if (matrix[0][i] == 1)
            max_edge_len = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                auxiliary[i][j] = 0;
            } else {
                int min = auxiliary[i - 1][j];
                min = std::min(auxiliary[i - 1][j - 1], min);
                min = std::min(auxiliary[i][j - 1], min);
                auxiliary[i][j] = min + 1;
                if (max_edge_len < auxiliary[i][j])
                    max_edge_len = auxiliary[i][j];
            }
        }
    }

    for (int i = 0; i < max_edge_len; i++) {
        for (int j = 0; j < max_edge_len; j++)
            std::cout << "1 ";
        std::cout << std::endl;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            std::cout << auxiliary[i][j] << " ";
        std::cout << std::endl;
    }
    for (int i = 0; i < m; i++)
        delete[] auxiliary[i];
    delete[] auxiliary;
}

int main() {
    int tmp[6][5] = {{0,1,1,0,1}, {1,1,0,1,0}, {0,1,1,1,0}, {1,1,1,1,0}, {1,1,1,1,1}, {0,0,0,0,0}};
    int **matrix = new int*[6];
    for (int i = 0; i < 6; i++) {
        matrix[i] = new int[5];
        memcpy(matrix[i], tmp[i], sizeof(int) * 5);
    }
    FindLargestSquareMatrix(matrix, 6, 5);
    for (int i = 0; i < 6; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}
