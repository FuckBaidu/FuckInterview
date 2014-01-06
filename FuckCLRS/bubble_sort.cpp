#include <stdio.h>
#include <assert.h>
#include <algorithm>

void PrintArray(int arr[], int len) {
    assert(len >= 0);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void BubbleSort(int arr[], int len) {
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    PrintArray(arr, sizeof(arr) / sizeof(int));
    BubbleSort(arr, sizeof(arr) / sizeof(int));
    PrintArray(arr, sizeof(arr) / sizeof(int));
    return 0;
}
