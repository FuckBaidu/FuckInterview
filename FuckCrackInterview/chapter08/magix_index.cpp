/**
 * 9.3 in <Crack the code interview> 5th edition.
 * A magix index in an array[0...n-1] is defined to be an index such that
 * A[i] == i.Given a sorted array. Write a method to find a magix index in array A
 */
#include <iostream>
#include <vector>

int FindMagicIndex(std::vector<int> &a, int begin, int end) {
    int index = -1;
    if (begin <= end) {
        int mid = (begin + end) / 2;
        if (a[mid] == mid)
            index = mid;
        if (index == -1)
            index = FindMagicIndex(a, std::max(a[mid], begin + 1), end);
        if (index == -1)
            index = FindMagicIndex(a, begin, std::min(a[mid], end - 1));
    }
    return index;
}

void Test(int *a, int len) {
    std::vector<int> vec(a, a + len);
    int index = FindMagicIndex(vec, 0, len - 1);
    std::cout << "Array is:";
    for (int i = 0; i < len; i++)
        std::cout << " " << a[i];
    std::cout << std::endl;
    std::cout << "Magic Index is: " << index << std::endl;
}

int main() {
    int a[] = {1, 2, 4, 5, 6, 6};
    Test(a, sizeof(a) / sizeof(int));
    int b[] = {1, 2, 4, 5, 6, 6, 6, 6};
    Test(b, sizeof(b) / sizeof(int));
    return 0;
}
