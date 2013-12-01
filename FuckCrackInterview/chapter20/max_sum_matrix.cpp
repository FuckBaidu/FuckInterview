/**
 * 20.12 in <Crack the code interview>.
 * Given an NxM matrix of positive and negative integers, write code to find 
 * the sub-matrix with the largest possible sum
 */
#include <limits.h>
#include <stdio.h>
#include <string.h>
int LargestSum(int **matrix, int m, int n) {
    int *sub_sum = new int[n];
    int max_sum = INT_MIN;
    for (int i = 0; i < m; i++) {
        memset(sub_sum, 0, sizeof(int) * n);
        for (int j = i; j < m; j++) {
            int cur_sum = 0;
            for (int k = 0; k < n; k++) {
                sub_sum[k] += matrix[j][k];
                if (cur_sum < 0)
                    cur_sum = 0;
                cur_sum += sub_sum[k];
                if (max_sum < cur_sum)
                    max_sum = cur_sum;
            }
        }
    }
    delete[] sub_sum;
    return max_sum;
}

int main() {
    int array[4][4] = {{0, -2, -7, 0}, {9, 2, -6, 2}, {-4, 1, -4, 1}, {-1, 8, 0, -2}};
    for (int i = 0 ; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
    int **matrix = new int*[4];
    for (int i = 0 ; i < 4; i++) {
        matrix[i] = new int[4];
        memcpy(matrix[i], array[i], sizeof(int) * 4);
    }
    printf("Sum is %d\n", LargestSum(matrix, 4, 4));
    for (int i = 0 ; i < 4; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}
