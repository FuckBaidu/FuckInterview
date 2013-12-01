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

int LargestHistogram(const std::vector<int> &a) {
    int max_size = 0;
    std::stack< std::pair<int, int> > stack;
    stack.push(std::make_pair(-1, -1));
    for (int i = 0; i <= a.size(); i++) {
        std::pair<int, int> cur;
        if (i == a.size())
            cur.first = 0;
        else
            cur.first = a[i];
        cur.second = i;
        while (cur.first < stack.top().first) {
            std::pair<int, int> top = stack.top();
            stack.pop();
            int cur_size = top.first * (i - stack.top().second - 1);
            if (cur_size > max_size)
                max_size = cur_size;
        }
        stack.push(cur);
    }
    return max_size;
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
