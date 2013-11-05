/**
 * 8.6 in <Crack the code interview>.
 * Implement the "paint fill" function that one might see on many image editing programs
 * That is, given a screen(represented by two dimensional array of Colors), a point,
 * and a new color, fill in the surrounding area util you hit the boder of the color
 */
#include <queue>
enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NUM,
};
void FillColor(int **points, int n, std::pair<int, int> start_point, int new_color) {
    std::queue< std::pair<int, int> > queue;
    queue.push(start_point);
    int old_color = points[start_point.first][start_point.second];
    while (!queue.empty()) {
        std::pair<int, int> cur_point = queue.front();
        queue.pop();
        for (int i = 0; i < (int)NUM; i++) {
            std::pair<int, int> new_point = cur_point;
            switch ((Direction)i) {
            case UP:
                new_point.second++;
                break;
            case DOWN:
                new_point.second--;
                break;
            case LEFT:
                new_point.first--;
                break;
            case RIGHT:
                new_point.first++;
                break;
            }
            if (new_point.first >= 0 && new_point.first < n
                && new_point.second >= 0 && new_point.second < n
                && points[new_point.first][new_point.second] == old_color)
                queue.push(new_point);
        }
    }
}

int main() {
    return 0;
}
