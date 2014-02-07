/*
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */
#include <iostream>
void Solve(int n, long long col, long long ld, long long rd, int &count) {
    long long bitmask = (1LL << n) - 1;
    if (col == bitmask) {
        count++;
    } else {
        long long pos_set = bitmask & ~(col | ld | rd);
        while (pos_set) {
            long long pos = pos_set & (0 - pos_set);
            pos_set &= ~pos;
            Solve(n, col | pos, (ld | pos) << 1, (rd | pos) >> 1, count);
        }
    }
}

int NQueens(int n) {
    int count = 0;
    if (n > 0) {
        Solve(n, 0, 0, 0, count);
    }
    return count;
}

int main() {
    for (int i = 1; i <= 16; i++)
        std::cout << i << " queens, there are " << NQueens(i) << " ways" << std::endl;
    return 0;
}
