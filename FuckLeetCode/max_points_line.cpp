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

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point &other) const {
        return x != other.x || y != other.y;
    }
};

struct PointHash {
    size_t operator()(const Point &point) const {
        return point.x * 97 | point.y * 103;
    }
};

struct Line {
    double slope;
    Point start;

    bool operator==(const Line &other) const {
        return slope - other.slope <= kEpsilon && start == other.start;
    }

    Line(double _slope, const Point &_start) : slope(_slope), start(_start) { }
};

struct LineHash {
    size_t operator()(const Line &line) const {
        return (size_t)line.slope * 97 + (line.start.x * 103 | line.start.y);
    }
};

typedef __gnu_cxx::hash_map<Point, int, PointHash> PointHashMap;
typedef __gnu_cxx::hash_map<Line, int, LineHash> LineHashMap;

int MaxPointsOnLine(const std::vector<Point> &points) {
    int max = 0;
    PointHashMap point_counts;
    LineHashMap line_counts;
    // count the duplicates
    for (int i = 0; i < points.size(); i++) {
        if (point_counts.count(points[i]) == 0)
            point_counts[points[i]] = 0;
        point_counts[points[i]]++;
        if (max < point_counts[points[i]])
            max = point_counts[points[i]];
    }

    // count the line
    for (PointHashMap::const_iterator iter_i = point_counts.begin();
         iter_i != point_counts.end(); ++iter_i) {
        PointHashMap::const_iterator iter_j = iter_i;
        ++iter_j;
        const Point &start = iter_i->first;
        for (; iter_j != point_counts.end(); ++iter_j) {
            const Point &end = iter_j->first;
            double slope;
            if (end.x == start.x)
                slope = INT_MAX;
            else
                slope = (double)(end.y - start.y) / (end.x - start.x);
            Line line(slope, start);
            if (line_counts.count(line) == 0)
                line_counts[line] = iter_i->second;
            line_counts[line] += iter_j->second;
            if (max < line_counts[line])
                max = line_counts[line];
        }
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
    return 0;
}
