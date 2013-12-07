/*
 * Implement the following function, FindSortedArrayRotation, which takes as its input an array of
 * unique integers that has been sorted in ascending order, then rotated by an unknown amount X
 * where 0 <= X <= (arrayLength - 1). An array rotation by amount X moves every element array[i] to
 * array[(i + X) % arrayLength]. FindSortedArrayRotation discovers and returns X by examining the
 * array
 */
#include <iostream>
int FindSortedArrayRotation(int *array, int len) {
    if (!array || len < 2)
        return -1;
    int begin = 0, end = len - 1;
    while (begin <= end && array[begin] >= array[end]) {
        int mid = begin + (end - begin) / 2;
        if (array[mid] > array[mid + 1])
            return mid + 1;
        else {
            if (array[mid] > array[begin])
                begin = mid + 1;
            else if (array[mid] < array[begin])
                end = mid - 1;
            else
                begin++;
        }
    }

    return -1;
}

void Test(int *array, int len) {
    std::cout << "Array: ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    int point = FindSortedArrayRotation(array, len);
    if (point == -1)
        std::cout << "No rotation at all" << std::endl;
    else
        std::cout << "Rotation point's index:" << point <<  std::endl;
}

int main() {
    int a[] = {1};
    Test(a, sizeof(a) / sizeof(int));
    int b[] = {1, 2};
    Test(b, sizeof(b) / sizeof(int));
    int c[] = {2, 1};
    Test(c, sizeof(c) / sizeof(int));
    int d[] = {1, 2, 3};
    Test(d, sizeof(d) / sizeof(int));
    int e[] = {2, 3, 1};
    Test(e, sizeof(e) / sizeof(int));
    int f[] = {3, 1, 2};
    Test(f, sizeof(f) / sizeof(int));
    int g[] = {3, 4, 5, 1, 2};
    Test(g, sizeof(g) / sizeof(int));
    int h[] = {3, 4, 5, 6, 1, 2};
    Test(h, sizeof(h) / sizeof(int));
    int i[] = {1, 3, 1, 1, 1};
    Test(i, sizeof(i) / sizeof(int));
    int m[] = {1, 1, 1, 3, 1};
    Test(m, sizeof(m) / sizeof(int));
    return 0;
}
