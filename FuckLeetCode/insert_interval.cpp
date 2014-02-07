/*
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if
 * necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */
#include <vector>
#include <iostream>
struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) { }
};

void Insert(std::vector<Interval> &intervals, Interval newInterval) {
    int begin = -1, end = 0; // if begin equals -1, then there is no overlap ranges
    for (end = 0; end < intervals.size(); end++) {
        if (newInterval.end < intervals[end].start) {
            break;
        } else {
            if (newInterval.start <= intervals[end].end) {
                if (begin == -1)
                    begin = end;
                newInterval.start = std::min(newInterval.start, intervals[end].start);
                newInterval.end = std::max(newInterval.end, intervals[end].end);
            }
        }
    }
    intervals.insert(intervals.begin() + end, newInterval);
    if (begin != -1)
        intervals.erase(intervals.begin() + begin, intervals.begin() + end);
}

void Test(Interval A[], int n, Interval new_interval) {
    std::vector<Interval> vec(A, A + n);
    std::cout << "Insert (" << new_interval.start << "," << new_interval.end << ")" << std::endl;
    std::cout << "Before: ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << "(" << vec[i].start << "," << vec[i].end << ") ";
    std::cout << std::endl;
    Insert(vec, new_interval);
    std::cout << "After: ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << "(" << vec[i].start << "," << vec[i].end << ") ";
    std::cout << std::endl;
}

int main() {
    Interval a[] = {Interval(1, 2), Interval(3, 5), Interval(8, 10), Interval(12, 16)};
    Test(a, 4, Interval(6, 7));
    Test(a, 4, Interval(4, 5));
    Test(a, 4, Interval(4, 17));
    Test(a, 4, Interval(17, 18));
    Test(a, 4, Interval(5, 9));
    return 0;
}

