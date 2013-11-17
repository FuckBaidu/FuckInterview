/**
 * 19.11 in <Crack the code interview>.
 * Design an algorithm to find all pairs of integers within an array which sum
 * to a specific value
 */
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <set>
#if __GNUC__ > 2
#include <ext/hash_set>
using __gnu_cxx::hash_set;
#else
#include <hash_set>
#endif
void GetSpecificSumPairs(int sum, std::vector<int> &array, std::vector< std::pair<int, int> > &result) {
    hash_set<int> hash_set;
    for (int i = 0; i < array.size(); i++)
        hash_set.insert(array[i]);
    for (int i = 0; i < array.size(); i++) {
        if (hash_set.count(sum - array[i]) != 0) {
            result.push_back(std::make_pair(array[i], sum - array[i]));
            hash_set.erase(array[i]);
        }
    }
}

void GetSpecificSumPairs1(int sum, std::vector<int> &array, std::vector< std::pair<int, int> > &result) {
    std::set<int> set;
    for (int i = 0; i < array.size(); i++)
        set.insert(array[i]);
    for (int i = 0; i < array.size(); i++) {
        if (set.count(sum - array[i]) != 0) {
            result.push_back(std::make_pair(array[i], sum - array[i]));
            set.erase(array[i]);
        }
    }
}

static inline int _Partition(std::vector<int> &a, int begin, int end) {
    std::swap(a[end], a[rand() % (end - begin + 1) + begin]);
    int j = begin - 1;
    for (int i = begin; i < end; i++) {
        if (a[i] < a[end]) {
            j++;
            std::swap(a[j], a[i]);
        }
    }
    j++;
    std::swap(a[j], a[end]);
    return j;
}

static inline void _QuickSort(std::vector<int> &a, int begin, int end) {
    if (begin < end) {
        int pivot = _Partition(a, begin, end);
        _QuickSort(a, begin, pivot - 1);
        _QuickSort(a, pivot + 1, end);
    }
}

void QuickSort(std::vector<int> &a) {
    if (a.size() <= 1)
        return;
    _QuickSort(a, 0, a.size() - 1);
}

void GetSpecificSumPairs2(int sum, std::vector<int> &array, std::vector< std::pair<int, int> > &result) {
    QuickSort(array);
    int i = 0, j = array.size() - 1;
    while (i < j) {
        if (array[i] + array[j] > sum) {
            j--;
        } else {
            if (array[i] + array[j] == sum) {
                result.push_back(std::make_pair(array[i], array[j]));
            }
            i++;
        }
    }
}

void Test(int sum, std::vector<int> &array) {
    std::cout << "Input: ";
    for (int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    std::vector< std::pair<int, int> > result;
    GetSpecificSumPairs(sum, array, result);
    std::cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        std::cout << "(" << result[i].first << "," << result[i].second << ")";
    std::cout << std::endl;

    result.clear();
    GetSpecificSumPairs1(sum, array, result);
    std::cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        std::cout << "(" << result[i].first << "," << result[i].second << ")";
    std::cout << std::endl;

    result.clear();
    GetSpecificSumPairs2(sum, array, result);
    std::cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        std::cout << "(" << result[i].first << "," << result[i].second << ")";
    std::cout << std::endl;
}

int main() {
    int array[] = {3, 4, 9, 7, 1, 5, 0, 2};
    std::vector<int> a(array, array + sizeof(array) / sizeof(int));
    Test(7, a);
    return 0;
}
