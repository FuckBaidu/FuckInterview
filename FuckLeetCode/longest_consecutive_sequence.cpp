/*
 * Given an unsorted array of integers, find the length of the longest consecutive elements
 * sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */
#include <ext/hash_set>
#include <vector>
#include <assert.h>
int LongestConsecutive(std::vector<int> &num) {
    __gnu_cxx::hash_set<int> hash_set;
    int max_len = 0;
    for (int i = 0; i < num.size(); i++)
        hash_set.insert(num[i]);
    for (int i = 0; i < num.size(); i++) {
        int cur_len = 1, cur = num[i];
        if (!hash_set.count(cur))
            continue;
        int j = cur + 1;
        while (hash_set.count(j)) {
            hash_set.erase(j);
            cur_len++;
            j++;
        }
        j = cur - 1;
        while (hash_set.count(j)) {
            hash_set.erase(j);
            cur_len++;
            j--;
        }
        if (max_len < cur_len)
            max_len = cur_len;
    }
    return max_len;
}

int main() {
    int array[] = {4, 2, 10, 9, 7, 3, 8};
    std::vector<int> num(array, array + 7);
    assert(LongestConsecutive(num) == 4);
    return 0;
}
