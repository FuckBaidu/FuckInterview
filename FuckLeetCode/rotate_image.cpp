/**
 * 1.6 in <Crack the code interview>
 * Given an image represented by an NxN matrix. where each pixel in the image is 4 bytes, wirte a
 * method to rotate the image by 90 degrees. Can you do this in place?
 */
#include <stdio.h>
void PrintMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void FreeMatrix(int **matrix, int n) {
   for (int i = 0; i < n; i++)
       delete[] matrix[i];
    delete[] matrix;
}

void GenerateMatrix(int ***ptr, int n) {
   int count = 0;
   int **matrix = new int*[n];
   for (int i = 0; i < n; i++) {
       matrix[i] = new int[n];
       for (int j = 0; j < n; j++)
           matrix[i][j] = count++;
   }
   *ptr = matrix;
}

void RotateMatrix(int **matrix, int n) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}

int main() {
   int n = 4;
   int **matrix = NULL;
   GenerateMatrix(&matrix, n);
   PrintMatrix(matrix, n);
   printf("\n");
   RotateMatrix(matrix, n);
   PrintMatrix(matrix, n);
   printf("\n");
   FreeMatrix(matrix, n);
   n = 9;
   GenerateMatrix(&matrix, n);
   PrintMatrix(matrix, n);
   printf("\n");
   RotateMatrix(matrix, n);
   PrintMatrix(matrix, n);
   printf("\n");
   FreeMatrix(matrix, n);
   return 0;
}
