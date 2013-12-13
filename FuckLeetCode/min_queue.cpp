/*
 * Design a queue that supports push_rear, pop_front, and get_min in O(1). Would that be elegantly
 * possible too?
 */
#include <assert.h>
#include <queue>
#include <deque>

class MinQueue {
public:
    int Front() {
        return _elements.front();
    }

    int PopFront() {
        int value = _elements.front();
        _elements.pop();
        if (value == _mins.front())
            _mins.pop_front();
        return value;
    }

    void PushRear(int value) {
        _elements.push(value);
        while (!_mins.empty() && value < _mins.back())
            _mins.pop_back();
        _mins.push_back(value);
    }

    int GetMin() {
        return _mins.front();
    }
private:
    std::queue<int> _elements;
    std::deque<int> _mins;
};

int main() {
    MinQueue q1;
    q1.PushRear(1);
    q1.PushRear(5);
    q1.PushRear(6);
    q1.PushRear(4);
    q1.PushRear(2);
    assert(q1.GetMin() == 1);
    assert(q1.Front() == 1);
    q1.PopFront();
    assert(q1.Front() == 5);
    assert(q1.GetMin() == 2);
    q1.PopFront();
    assert(q1.Front() == 6);
    assert(q1.GetMin() == 2);
    q1.PopFront();
    assert(q1.Front() == 4);
    assert(q1.GetMin() == 2);
    MinQueue q2;
    q2.PushRear(2);
    q2.PushRear(2);
    q2.PushRear(1);
    q2.PushRear(1);
    q2.PushRear(4);
    q2.PushRear(5);
    assert(q2.GetMin() == 1);
    assert(q2.Front() == 2);
    q2.PopFront();
    assert(q2.Front() == 2);
    assert(q2.GetMin() == 1);
    q2.PopFront();
    assert(q2.Front() == 1);
    assert(q2.GetMin() == 1);
    q2.PopFront();
    assert(q2.Front() == 1);
    assert(q2.GetMin() == 1);
    q2.PopFront();
    assert(q2.Front() == 4);
    assert(q2.GetMin() == 4);
    q2.PopFront();
    assert(q2.Front() == 5);
    assert(q2.GetMin() == 5);
    return 0;
}
