/**
 * 9.6 in <Crack the code interview>.
 * Give a matrix in which each row and column is sorted. Write a method to find
 * an element in it
 */
#include <utility>
std::pair<int, int> SearchYouthMatrix(int **matrix, int n, int key) {
    std::pair<int, int> result(-1, -1);
    std::pair<int, int> cur(0, n - 1);
    while (cur.first < n && cur.second >= 0) {
        if (key == matrix[cur.first][cur.second]) {
            result = cur;
            break;
        } else if (key > matrix[cur.first][cur.second]) {
            cur.first++;
        } else {
            cur.second--;
        }
    }
    return result;
}

int main() {
    return 0;
}
