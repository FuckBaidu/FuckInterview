/*
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
#include <vector>
#include <assert.h>
int Candy(std::vector<int> &ratings) {
    int sum = 0;
    std::vector<int> candies(ratings.size(), 1);
    // Check the ascending sequence
    for (int i = 1; i < ratings.size(); i++)
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    // Check the descending sequence
    for (int i = ratings.size() - 2; i >= 0; i--)
        if (ratings[i] > ratings[i + 1])
            candies[i] = std::max(candies[i + 1] + 1, candies[i]);
    for (int i = 0; i < candies.size(); i++)
        sum += candies[i];
    return sum;
}

int main() {
    int a[] = {58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
    std::vector<int> vec(a, a + sizeof(a) / sizeof(int));
    assert(Candy(vec) == 208);
    return 0;
}

