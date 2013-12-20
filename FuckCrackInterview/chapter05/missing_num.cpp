/**
 * 5.1 in <Crack the code interview>.
 * An array A[1..n] contains all the integers from 0 to n except for one number 
 * which is missing, Find it.The only operation we can use to access them is 
 * "fetching the jth bit of A[i]".
 */
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <time.h>
int FindMissingNumber(int *array, int len) {
    if (array == NULL || len == 0)
        return -1;
    std::vector<int> odds, evens, cur(array, array + len);
    int result = 0, bit = 0;
    while (!cur.empty()) {
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] & 1)
                odds.push_back(cur[i] >> 1);
            else
                evens.push_back(cur[i] >> 1);
        }

        if (odds.size() >= evens.size()) {
            std::swap(cur, evens);
        } else {
            std::swap(cur, odds);
            result |= (1 << bit);
        }
        evens.clear();
        odds.clear();
        bit++;
    }
    return result;
}

void Test(int n) {
    int *array = new int[n];
    int missing = rand() % (n + 1);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j == missing)
            j++;
        array[i] = j++;
    }
    printf("Array[%d] missing number %d\n", n, missing);
    printf("Found missing number %d\n", FindMissingNumber(array, n));

    delete []array;
}

int main() {
    srand(time(NULL));
    Test(5);
    Test(50);
    Test(536);
    Test(9999);
    Test(10000);
    return 0;
}
