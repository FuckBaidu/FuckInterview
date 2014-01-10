/*
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight * line.
 **/
#include <assert.h>
#include <vector>
#include <ext/hash_map>

const double kEpsilon = 0.001;

struct Point {
    int x;
    int y;

    Point(int a, int b) : x(a), y(b) { }
};

struct Line {
    double slope;

    bool operator==(const Line &other) const {
        return slope - other.slope <= kEpsilon;
    }
};

struct LineHash {
    size_t operator()(const Line &line) const {
        return (size_t)(line.slope * 1007);
    }
};

typedef __gnu_cxx::hash_map<Line, int, LineHash> LineHashMap;

int MaxPointsOnLine(const std::vector<Point> &points) {
    int max = 0;
    for (int i = 0; i < (int)points.size(); i++) {
        const Point &start = points[i];
        Line line;
        // count the duplicates of start point
        int num_starts = 1;
        LineHashMap hash_map;
        for (int j = i + 1; j < (int)points.size(); j++) {
            if (points[j].x == start.x && points[j].y == start.y) {
                num_starts++;
            } else {
                if (points[j].x == start.x)
                    line.slope = INT_MAX;
                else
                    line.slope = (double)(points[j].y - start.y) / (points[j].x - start.x);
                hash_map[line]++;
            }
        }
        if (max < num_starts)
            max = num_starts;
        for (LineHashMap::const_iterator iter = hash_map.begin();
             iter != hash_map.end(); ++iter)
            if (max < num_starts + iter->second)
                max = num_starts + iter->second;
    }
    return max;
}

int main() {
    std::vector<Point> a;
    assert(MaxPointsOnLine(a) == 0);
    a.push_back(Point(0, 0));
    assert(MaxPointsOnLine(a) == 1);
    a.push_back(Point(0, 0));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(1, 1));
    assert(MaxPointsOnLine(a) == 3);

    a.clear();
    a.push_back(Point(0, 0));
    assert(MaxPointsOnLine(a) == 1);
    a.push_back(Point(1, 1));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(0, 0));
    assert(MaxPointsOnLine(a) == 3);

    a.clear();
    a.push_back(Point(0, 0));
    assert(MaxPointsOnLine(a) == 1);
    a.push_back(Point(1, 1));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(1, 1));
    assert(MaxPointsOnLine(a) == 3);
    a.push_back(Point(2, 2));
    assert(MaxPointsOnLine(a) == 4);

    a.clear();
    a.push_back(Point(3, 1));
    assert(MaxPointsOnLine(a) == 1);
    a.push_back(Point(4, 1));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(3, 1));
    assert(MaxPointsOnLine(a) == 3);
    a.push_back(Point(5, 1));
    assert(MaxPointsOnLine(a) == 4);

    a.clear();
    a.push_back(Point(1, 3));
    assert(MaxPointsOnLine(a) == 1);
    a.push_back(Point(1, 4));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(1, 3));
    assert(MaxPointsOnLine(a) == 3);
    a.push_back(Point(1, 5));
    assert(MaxPointsOnLine(a) == 4);

    a.clear();
    a.push_back(Point(3, 1));
    assert(MaxPointsOnLine(a) == 1);
    a.push_back(Point(12, 3));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(3, 1));
    assert(MaxPointsOnLine(a) == 3);
    a.push_back(Point(-6, -1));
    assert(MaxPointsOnLine(a) == 4);

    a.clear();
    a.push_back(Point(84, 250));
    assert(MaxPointsOnLine(a) == 1);
    a.push_back(Point(0, 0));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(1, 0));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(0, -70));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(0, -70));
    assert(MaxPointsOnLine(a) == 3);
    a.push_back(Point(-1, -1));
    assert(MaxPointsOnLine(a) == 3);
    a.push_back(Point(21, 10));
    assert(MaxPointsOnLine(a) == 4);
    a.push_back(Point(42, 90));
    assert(MaxPointsOnLine(a) == 5);
    a.push_back(Point(-42, -230));
    assert(MaxPointsOnLine(a) == 6);

    a.clear();
    a.push_back(Point(1, 3));
    assert(MaxPointsOnLine(a) == 1);
    a.push_back(Point(1, 3));
    assert(MaxPointsOnLine(a) == 2);
    a.push_back(Point(1, 3));
    assert(MaxPointsOnLine(a) == 3);
    return 0;
}
