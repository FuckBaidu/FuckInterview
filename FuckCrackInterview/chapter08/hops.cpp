/**
 * 9.1 in <Crack the code interview> 5th edition.
 * A child is running up a staircase with n steps, and can hop 1 steps, 
 * 2 steps or 3 steps at a time.Implement a method to count how many possible
 * ways the child can runs up the stairs
 */
#include <iostream>
int NumWays(int n, int steps) {
    if (steps == 1) {
        return 1;
    } else {
        int num_ways = 0;
        for (int i = 0; i * steps <= n; i++)
            num_ways += NumWays(n - i * steps, steps - 1);
        return num_ways;
    }
}

void Test(int n) {
    std::cout << " Stairs " << n << ", Hop ways:" << NumWays(n, 3) << std::endl;;
}

int main() {
    Test(1);
    Test(2);
    Test(3);
    Test(6);
    Test(10);
    return 0;
}
