#include <stdio.h>
int BinarySearch(int *array, int len, int value) {
    if (!array || len == 0)
        return -1;
    int low = 0, index = -1, high = len - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (value == array[mid]) {
            index = mid;
            break;
        } else if (value < array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high; // If not found, return the maximum of elements smaller than 'value'
    //return low; // If not found, return the minimum of elements larger than 'value'
    //return index; // If not found, return -1
}

void Test(int *array, int len, int value) {
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
    int index = BinarySearch(array, len, value);
    printf("%d is at %d\n", value, index);
}

int main() {
    int a1[] = {1, 2, 3, 4, 6, 7};
    Test(a1, sizeof(a1) / sizeof(int), 5);
    int a2[] = {3, 4, 6, 7, 8};
    Test(a2, sizeof(a2) / sizeof(int), 5);
    int a3[] = {3, 5, 6, 7, 8};
    Test(a3, sizeof(a3) / sizeof(int), 5);
    int a4[] = {6, 7, 8, 9};
    Test(a4, sizeof(a4) / sizeof(int), 5);
    int a5[] = {1, 2, 3, 4};
    Test(a5, sizeof(a5) / sizeof(int), 5);
    return 0;
}

