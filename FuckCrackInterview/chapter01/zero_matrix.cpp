
/**
 * 1.7 in <Crack the code interview>.Write an algorithm such that if an element in an MxN matrix is
 * 0, its entire row and column is set to 0.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void FreeMatrix(int **matrix, int m, int n) {
   for (int i = 0; i < m; i++)
       delete[] matrix[i];
    delete[] matrix;
}

void GenerateMatrix(int ***ptr, int m, int n) {
    int count = 0;
    int **matrix = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            if (rand() % 79)
                matrix[i][j] = count++;
            else
                matrix[i][j] = 0;
    }
    *ptr = matrix;
}

void ZeroMatrix(int **matrix, int m, int n) {
    bool *zero_row = new bool[m];
    bool *zero_col = new bool[n];
    memset(zero_row, sizeof(bool) * m, 0);
    memset(zero_col, sizeof(bool) * n, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!matrix[i][j]) {
                zero_row[i] = true;
                zero_col[j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (zero_row[i] || zero_col[j])
                matrix[i][j] = 0;
        }
    }
}

int main() {
   int m = 6, n = 4;
   int **matrix = NULL;
   GenerateMatrix(&matrix, m, n);
   PrintMatrix(matrix, m, n);
   printf("\n");
   ZeroMatrix(matrix, m, n);
   PrintMatrix(matrix, m, n);
   printf("\n");
   FreeMatrix(matrix, m,  n);
   m = 12;
   n = 9;
   GenerateMatrix(&matrix, m, n);
   PrintMatrix(matrix, m, n);
   printf("\n");
   ZeroMatrix(matrix, m, n);
   PrintMatrix(matrix, m, n);
   printf("\n");
   FreeMatrix(matrix, m,  n);
   return 0;
}
