
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

//use constant space
void ZeroMatrix(int **matrix, int m, int n) {
    // use first row and first col as the storage for flags array
    bool need_zero_first_col = false, need_zero_first_row = false;
    for (int col = 0; col < n; col++) {
        if (matrix[0][col] == 0) {
            need_zero_first_row = true;
            break;
        }
    }
    for (int row = 0; row < m; row++) {
        if (matrix[row][0] == 0) {
            need_zero_first_col = true;
            break;
        }
    }
    for (int row = 1; row < m; row++) {
        for (int col = 1; col < n; col++) {
            if (matrix[row][col] == 0) {
                matrix[0][col] = 0;
                matrix[row][0] = 0;
            }
        }
    }

    for (int row = 1; row < m; row++)
        for (int col = 1; col < n; col++)
            if (matrix[0][col] == 0 || matrix[row][0] == 0)
                matrix[row][col] = 0;

    if (need_zero_first_row)
        for (int col = 0; col < n; col++)
            matrix[0][col] = 0;

    if (need_zero_first_col)
        for (int row = 0; row < m; row++)
            matrix[row][0] = 0;
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
