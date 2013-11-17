/**
 * 8.2 in <Crack the code interview>
 * Imagine a robot sitting on the upper left corner of an N * N grid.
 * The robot can only move on two directions: down and right.How many possible
 * paths are there for the robots
 */
#include <iostream>
int NumWays(int cur_x, int cur_y, int x, int y) {
    if (cur_x == x || cur_y == y)
        return 1;
    else
        return NumWays(cur_x + 1, cur_y, x, y) + NumWays(cur_x, cur_y + 1, x, y);
}
int main() {
    std::cout << "There are " << NumWays(0, 0, 1, 1) << " ways from (0,0) to (1,1)" << std::endl;
    std::cout << "There are " << NumWays(0, 0, 2, 2) << " ways from (0,0) to (2,2)" << std::endl;
    return 0;
}
