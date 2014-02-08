/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i,
 * ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains
 * the most water.
 *
 * Note: You may not slant the container.
 */
#include <vector>
#include <iostream>
int MaxArea(std::vector<int> &height) {
    int max = 0, begin = 0, end = (int)height.size() - 1;
    while (begin < end) {
        int cur = std::min(height[begin], height[end]) * (end - begin);
        if (max < cur)
            max = cur;
        if (height[begin] < height[end])
            begin++;
        else
            end--;
    }
    return max;
}

int main() {
    srand(time(NULL));
    std::vector<int> height;
    for (int i = 0; i < 10; i++)
        height.push_back(rand() % 10);
    std::cout << "heights:";
    for (int i = 0; i < height.size(); i++)
        std::cout << height[i] << " ";
    std::cout << std::endl;
    std::cout << "Max area is:" << MaxArea(height) << std::endl;
    return 0;
}
