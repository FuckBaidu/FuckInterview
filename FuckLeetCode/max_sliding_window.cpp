/*
 * A long array A[] is given to you. There is a sliding window of size w which is moving from the
 * very left of the array to the very right. You can only see the w numbers in the window. Each time
 * the sliding window moves rightwards by one position. Following is an example:
 * The array is [1 3 -1 -3 5 3 6 7], and w is 3.
 *
 * Window position                Max
 * ---------------               -----
 *  [1  3  -1] -3  5  3  6  7      3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 *  Input: A long array A[], and a window width w
 *  Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
 *  Requirement: Find a good optimal way to get B[i]
 */
#include <queue>
#include <deque>
#include <iostream>
#include <iomanip>

class MaxQueue {
public:
    void Pop() {
        int value = _elements.front();
        _elements.pop();
        if (value == _maxs.front())
            _maxs.pop_front();
    }

    void Push(int value) {
        _elements.push(value);
        while (!_maxs.empty() && value > _maxs.back())
            _maxs.pop_back();
        _maxs.push_back(value);
    }

    int Front() const {
        return _elements.front();
    }

    int GetMax() const {
        return _maxs.front();
    }
private:
    std::queue<int> _elements;
    std::deque<int> _maxs;
};

void MaxSlidingWindow(const std::vector<int> &A, int w, std::vector<int> &B) {
    if (A.size() < w)
        return;
    MaxQueue queue;
    for (int i = 0; i < w; i++)
        queue.Push(A[i]);
    B.push_back(queue.GetMax());
    // Start sliding!
    for (int i = w; i < A.size(); i++) {
        queue.Pop();
        queue.Push(A[i]);
        B.push_back(queue.GetMax());
    }
}

int main() {
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int> A(a, a + sizeof(a) / sizeof(int));
    std::vector<int> B;
    int w = 3;
    MaxSlidingWindow(A, w, B);
    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            if (j == i)
                std::cout << "[";
            std::cout << A[j];
            if (j == i + w - 1)
                std::cout << "]";
            std::cout << " ";
        }
        std::cout << std::setw(10) << B[i] << std::endl;
    }
    return 0;
}
