/**
 * Determining Whether A Point Is Inside A Complex Polygon
 */
#include <vector>
#include <iostream>
struct Point {
    int x;
    int y;
};

bool IsInsidePolygon(const std::vector<Point> &vertexs, const Point &point) {
    if (vertexs.size() < 3)
        return false;
    bool is_inside = false;
    for (int i = 0; i < vertexs.size(); i++) {
        Point v1, v2;
        if (i == 0) {
            v1 = vertexs.back();
            v2 = vertexs.front();
        } else {
            v1 = vertexs[i - 1];
            v2 = vertexs[i];
        }
        if ((point.y < v2.y && point.y >= v1.y) || (point.y < v1.y && point.y >= v2.y)) {
            //only check the lines on the left side of point(because both the left 
            //side and right side either have odd numbers of intersection with the y threshold
            //or have even ones.
            if (v1.x + (point.y - v1.y) / (v2.y - v1.y) * (v2.x - v1.x) < point.x)
                is_inside = !is_inside;
        }
    }
    return is_inside;
}

int main() {
    return 0;
}
