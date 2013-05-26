/*
 * From section 2.3 of <The Beauty of Coding>. Find the "the king of buzz" who has post more than
 * half of the messages in BBS
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
int FindTheKingOfBuzz(int *ids, int num) {
    assert(ids != NULL && num !=0);
    int candidate;
    int times = 0;
    for (int i = 0; i < num; i++) {
        if (times == 0) {
            candidate = ids[i];
            times++;
        } else {
            if (ids[i] == candidate)
                times++;
            else
                times--;
        }
    }
    return candidate;
}

void RandomShuffle(int *ids, int num) {
    assert(ids != NULL && num !=0);
    for (int i = num - 1; i > 0; i--)
        std::swap(ids[i], ids[rand() % (i + 1)]);
}

void GenerateRandomArray(int *ids, int num) {
    assert(ids != NULL && num !=0);
    int num_ones = num /2 + 1;
    for (int i = 0; i < num_ones; i++)
        ids[i] = 1;
    for (int i = num_ones; i < num; i++)
        ids[i] = rand() % 5 + 2;
    RandomShuffle(ids, num);
}

int main() {
    int num1[1];
    GenerateRandomArray(num1, 1);
    assert(FindTheKingOfBuzz(num1, 1) == 1);
    int num2[2];
    GenerateRandomArray(num2, 2);
    assert(FindTheKingOfBuzz(num2, 2) == 1);
    int num5[5];
    GenerateRandomArray(num5, 5);
    assert(FindTheKingOfBuzz(num5, 5) == 1);
    int num100[100];
    GenerateRandomArray(num100, 100);
    assert(FindTheKingOfBuzz(num100, 100) == 1);
    return 0;
}
