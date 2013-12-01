/*
 * Given: A two-dimensional array b (M rows, N columns) of Boolean values ("0" and "1"). Required:
 * Find the largest (most elements) rectangular subarray containing all ones.
 */
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <sys/time.h>

struct Point {
    int x;
    int y;
};

bool IsAllOnes(int **array, const Point &upper_left, const Point &lower_right) {
    for (int i = upper_left.x; i <= lower_right.x; i++)
        for (int j = upper_left.y; j <= lower_right.y; j++)
            if (array[i][j] == 0)
                return false;
    return true;
}

int LargestRectangle1(int **array, int m, int n) {
    int max_size = 0;
    Point upper_left, lower_right;
    for (upper_left.x = 0; upper_left.x < m; upper_left.x++) {
        for (upper_left.y = 0; upper_left.y < n; upper_left.y++) {
            for (lower_right.x = upper_left.x; lower_right.x < m; lower_right.x++) {
                for (lower_right.y = upper_left.y; lower_right.y < n; lower_right.y++) {
                    if (IsAllOnes(array, upper_left, lower_right)) {
                        int size = (lower_right.x - upper_left.x + 1) * (lower_right.y - upper_left.y + 1);
                        if (max_size < size)
                            max_size = size;
                    }
                }
            }
        }
    }
    return max_size;
}

int LargestRectangle2(int **array, int m, int n) {
    int max_size = 0;
    Point upper_left, lower_right;
    for (upper_left.y = 0; upper_left.y < n; upper_left.y++) {
        for (upper_left.x = 0; upper_left.x < m; upper_left.x++) {
            int max_x = m - 1;
            for (lower_right.y = upper_left.y; lower_right.y < n; lower_right.y++)  {
                for (lower_right.x = upper_left.x; lower_right.x <= max_x && max_x >= 0; lower_right.x++) {
                    if (array[lower_right.x][lower_right.y] == 0) {
                        max_x = lower_right.x - 1;
                        break;
                    }
                }
                int size = (max_x - upper_left.x + 1) * (lower_right.y - upper_left.y + 1);
                if (max_size < size)
                    max_size = size;
            }
        }
    }
    return max_size;
}

int LargestRectangle3(int **array, int m, int n) {
    int max_size = 0;
    Point upper_left, lower_right;
    int *count = new int[n];
    memset(count, 0, n * sizeof(int));
    for (upper_left.x = m - 1; upper_left.x >= 0; upper_left.x--) {
        for (upper_left.y = 0; upper_left.y < n; upper_left.y++) {
            if (array[upper_left.x][upper_left.y] == 1)
                count[upper_left.y]++;
            else
                count[upper_left.y] = 0;
        }

        for (upper_left.y = 0; upper_left.y < n; upper_left.y++) {
            int min_count = INT_MAX;
            for (lower_right.y = upper_left.y; lower_right.y < n; lower_right.y++)  {
                if (count[lower_right.y] < min_count)
                    min_count = count[lower_right.y];
                int size = min_count * (lower_right.y - upper_left.y + 1);
                if (max_size < size)
                    max_size = size;
            }
        }
    }
    delete[] count;
    return max_size;
}

int LargestRectangle4(int **array, int m, int n) {
    int max_size = 0;
    int *count = new int[n];
    memset(count, 0, n * sizeof(int));
    for (int x = m - 1; x >= 0; x--) {
        std::stack< std::pair<int, int> > stack;
        stack.push(std::make_pair(-1, -1));
        for (int y = 0; y <= n; y++) {
            std::pair<int, int> cur;
            cur.second = y;
            if (y != n) {
                if (array[x][y] == 1)
                    count[y]++;
                else
                    count[y] = 0;
                cur.first = count[y];
            } else {
                cur.first = 0;
            }

            while (cur.first < stack.top().first) {
                std::pair<int, int> top = stack.top();
                stack.pop();
                int size = (y - stack.top().second - 1) * top.first;
                if (max_size < size)
                    max_size = size;
            }
            stack.push(cur);
        }

    }
    delete[] count;
    return max_size;
}

typedef int (*Func)(int **, int, int);

int main() {
    srand(time(NULL));
    int m = 150, n = 200;
    int **array = new int*[m];
    for (int i = 0; i < m; i++) {
        array[i] = new int[n];
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 3 == 0? 0 : 1;
        }
    }

    Func funcs[] = {LargestRectangle1, LargestRectangle2, LargestRectangle3, LargestRectangle4};
    for (int i = 0; i < sizeof(funcs) / sizeof(Func); i++) {
        struct timeval start, end;
        gettimeofday(&start, NULL);
        int result = funcs[i](array, m, n);
        gettimeofday(&end, NULL);
        std::cout << "Largest rectangle size is " << result << " .Cost " 
            << (end.tv_sec - start.tv_sec) * 100000 + end.tv_usec - start.tv_usec
            << " us" << std::endl;
    }
    for (int i = 0; i < m; i++)
        delete[] array[i];
    delete[] array;
    return 0;
}
