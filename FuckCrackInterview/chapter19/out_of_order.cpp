/**
 * 17.6 in <Crack the code interview> 5th edition.
 * Given an array of integers, write a method to find indices m and n such that
 * if you sorted the elements between m and n, the entire array would be sorted.
 * Minimise n -m (find the smallest such sequence)
 * Example:
 * Input: 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19
 * Output: (3, 9)
 */
#include <iostream>
#include <vector>

int FindGreaterOrEqual(std::vector<int> &array, int begin, int end, int value) {
    int index = -1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (array[mid] == value) {
            index = mid;
            break;
        } else if (value < array[mid]){
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }

    return index == -1? begin : index + 1;
}

std::pair<int, int> FindMinOutOfOrderSequence(std::vector<int> &array) {
    std::pair<int, int> result(-1, -1);
    if (array.size() != 0) {
        int max = array[0], sorted_end = 0;
        for (int i = 0; i < array.size(); i++) {
            if (max <= array[i]) {
                max = array[i];
                if (result.first == -1 && result.second == -1)
                    sorted_end = i;
            } else {
                result.second = i;
                int out_begin = FindGreaterOrEqual(array, 0, sorted_end, array[i]);
                if (result.first == -1 || out_begin < result.first)
                    result.first = out_begin;
            }
        }
    }
    return result;
}

void Test(int a[], int len) {
    std::vector<int> vec(a, a + len);
    std::pair<int, int> result = FindMinOutOfOrderSequence(vec);
    std::cout << "Input: ";
    for (int i = 0; i < len; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    std::cout << "Output is: (" << result.first << ", " << result.second << ")" << std::endl;
}

int main() {
    int a[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    Test(a, sizeof(a) / sizeof(int));
    int b[] = {1, 2, 6, 8, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    Test(b, sizeof(b) / sizeof(int));
    return 0;
}
