/*
 * From section 2.3 of <The Beauty of Coding>. Find the "the gang of buzz":
 * There are three IDs whose posts on BBS has exceeded one quarter of the total ones
 * half of the messages in BBS
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
void FindTheGangOfBuzz(int *ids, int num, int * result) {
    assert(ids != NULL && num >= 6);
    int times[3] = {0, 0, 0};
    for (int i = 0; i < num; i++) {
        bool is_add = false;
        for (int j = 0; j < 3; j++) {
            if (times[j] == 0) {
                result[j] = ids[i];
                times[j] = 1;
                is_add = true;
                break;
            }
        }

        if (is_add)
            continue;

        bool is_equal = false;
        for (int j = 0; j < 3; j++) {
            if (ids[i] == result[j]) {
                times[j]++;
                is_equal = true;
                break;
            }
        }
        if (!is_equal)
            for (int j = 0; j < 3; j++)
                times[j]--;
    }
}

void RandomShuffle(int *ids, int num) {
    assert(ids != NULL && num !=0);
    for (int i = num - 1; i > 0; i--)
        std::swap(ids[i], ids[rand() % (i + 1)]);
}

void GenerateRandomArray(int *ids, int num) {
    assert(ids != NULL && num >= 6);
    for (int i = 0; i < num; i++)
        if (i < num / 4 + 1)
           ids[i] = 1;
        else if (i < num / 4 * 2 + 2)
           ids[i] = 2;
        else if (i < num / 4 * 3 + 3)
           ids[i] = 3;
        else
            ids[i] = rand() % 10 + 4;
    RandomShuffle(ids, num);

    for (int i = 0; i < num; i++)
        printf("%d,", ids[i]);
    printf("\n");
}

int main() {
    int num1[6];
    int result[3];
    GenerateRandomArray(num1, 6);
    FindTheGangOfBuzz(num1, 6, result);
    for (int i = 0; i < 3; i++)
        for (int j = 2; j > i; j--)
            if (result[j] < result[j - 1])
                std::swap(result[j], result[j - 1]);
    for (int i = 0; i < 3; i++)
        assert(result[i] == (i+1));
    int num2[100];
    GenerateRandomArray(num2, 100);
    FindTheGangOfBuzz(num2, 100, result);
    for (int i = 0; i < 3; i++)
        for (int j = 2; j > i; j--)
            if (result[j] < result[j - 1])
                std::swap(result[j], result[j - 1]);
    for (int i = 0; i < 3; i++)
        assert(result[i] == (i+1));
    return 0;
}
