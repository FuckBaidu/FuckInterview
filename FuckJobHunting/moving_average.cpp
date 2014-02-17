/*
 * Given a sequence of n values x1, x2, ..., xn and a window size k>0, the k-th moving average of
 * the given sequence is defined as follows:
 * The moving average sequence has n-k+1 elements as shown above.
 *
 * The moving averages with k=4 of a ten-value sequence (n=10) is shown below
 *
 *    i     1   2   3   4   5   6   7   8   9 10
 *    =====  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==
 *    Input  10  20  30  40  50  60  70  80  90 100
 *    y1     25 = (10+20+30+40)/4
 *    y2         35 = (20+30+40+50)/4
 *    y3             45 = (30+40+50+60)/4
 *    y4                 55 = (40+50+60+70)/4
 *    y5                     65 = (50+60+70+80)/4
 *    y6                         75 = (60+70+80+90)/4
 *    y7                             85 = (70+80+90+100)/4
 *    Thus, the moving average sequence has n-k+1=10-4+1=7 values.
 *
 *    give a windows size of k and a integer sequence, implement a NextAverage(int input) function to get the average
 */
#include <queue>
#include <assert.h>
class AverageGenerator {
public:
    AverageGenerator(int k) : _windows_size(k), _sum(0) {
        assert(k > 0);
    }

    double NextAverage(int input) {
        if (_queue.size() == _windows_size) {
            _sum -= _queue.front();
            _queue.pop();
        }
        _queue.push(input);
        _sum += input;
        return (double)_sum / _queue.size();
    }
private:
    int _sum;
    int _windows_size;
    std::queue<int> _queue;
};

int main() {
    AverageGenerator gen(5);
    assert(gen.NextAverage(1) == 1);
    assert(gen.NextAverage(2) == 1.5);
    assert(gen.NextAverage(3) == 2);
    assert(gen.NextAverage(4) == 2.5);
    assert(gen.NextAverage(5) == 3);
    assert(gen.NextAverage(6) == 4);
    return 0;
}

