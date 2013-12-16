/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
#include <assert.h>
#include <iostream>
int ClimbStairs(int n) {
    int len = std::max(3, n + 1);
    int *counts = new int[len];
    counts[0] = 0;
    counts[1] = 1;
    counts[2] = 2;
    for (int i = 3; i <= n; i++)
        counts[i] = counts[i - 1] + counts[i - 2];
    int result = counts[n];
    delete[] counts;
    return result;
}

int main() {
    assert(ClimbStairs(3) == 3);
    assert(ClimbStairs(4) == 5);
    assert(ClimbStairs(5) == 8);
    return 0;
}
