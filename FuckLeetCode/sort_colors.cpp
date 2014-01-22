/* 
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same
 * color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue
 * respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total
 * number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 */
#include <iostream>
void SortColors(int A[], int n) {
    int j = -1, k = -1; 
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            std::swap(A[++j], A[i]);
            if (k != -1)
               std::swap(A[++k], A[i]); 
        } else if (A[i] == 1) {
            if (k == -1)
                k = j;
            std::swap(A[++k], A[i]);
        }
    }
}

void Test(int A[], int n) {
    std::cout << "Input:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    SortColors(A, n);
    std::cout << "Output:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main() {
    int a[] = {2, 0};
    Test(a, 2);
    int b[] = {1, 2, 0};
    Test(b, 3);
    int c[] = {2, 1, 0, 1};
    Test(c, 4);
    return 0;
}
