/*
 * A histogram is a polygon composed of a sequence of rectangles aligned at a common base line. The
 * rectangles have equal widths but may have different heights. For example, the histogram that consists
 * of rectangles with the heights 2, 1, 4, 5, 1, 3, 3, measured in units where 1 is the width of the rectangles.
 * Find the largest rectangle under the histogram.
 * Input: 7 2 1 4 5 1 3 3
 * Output: 8
 */
#include <vector>
#include <stack>
#include <iostream>

int LargestHistogram(const std::vector<int> &height) {
    int max_area = 0;
    std::stack< std::pair<int, int> > stack;
    for (int i = 0; i <= height.size(); i++) {
        int cur_height = i == height.size() ? INT_MIN : height[i];
        while (!stack.empty() && cur_height < stack.top().second) {
            std::pair<int, int> top = stack.top();
            stack.pop();
            int cur_area;
            if (stack.empty())
                cur_area = top.second * i;
            else
                cur_area = top.second * (i - stack.top().first - 1);
            if (max_area < cur_area)
                max_area = cur_area;
        }
        stack.push(std::make_pair(i, cur_height));
    }
    return max_area;
}

int main() {
    std::vector<int> a;
    a.push_back(7);
    a.push_back(2);
    a.push_back(1);
    a.push_back(4);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(3);
    std::cout << "Largest histogram size is: " << LargestHistogram(a) << std::endl;
    a.clear();
    a.push_back(4);
    a.push_back(1000);
    a.push_back(1000);
    a.push_back(1000);
    a.push_back(1000);
    std::cout << "Largest histogram size is: " << LargestHistogram(a) << std::endl;
    a.clear();
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    std::cout << "Largest histogram size is: " << LargestHistogram(a) << std::endl;
    a.clear();
    a.push_back(5);
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    std::cout << "Largest histogram size is: " << LargestHistogram(a) << std::endl;

    return 0;
}
