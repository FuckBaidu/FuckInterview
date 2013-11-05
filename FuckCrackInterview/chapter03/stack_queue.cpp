/**
 * 3.5 in <Crack the code interview>.
 * Implement a queue using two stacks
 */
#include "util.h"
template <class T>
class MyQueue {
public:
    void Enqueue(T v) {
        _stack1.push(v);
    }

    T Dequeue() {
        if (_stack2.empty())
            while (!_stack1.empty())
                _stack2.push(_stack1.pop());
        return _stack2.pop();
    }
private:
    ArrayStack<T> _stack1;
    LinkedStack<T> _stack2;
};

template <class T>
class MyStack {
public:
    MyStack() : _cur(0) { }
    void Push(T v) {
        if (!_queue[_cur].empty())
            _queue[1 - _cur].enqueue(_queue[_cur].dequeue());
        _queue[_cur].enqueue(v);
    }

    T Pop() {
        if (_queue[_cur].empty()) {
            _cur = 1 - _cur;
            while (_queue[_cur].size() > 1)
                _queue[1 - _cur].enqueue(_queue[_cur].dequeue());
        }
        return _queue[_cur].dequeue();
    }
private:
    int _cur;
    ArrayQueue<T> _queue[2];
};

void Test() {
    MyQueue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    assert(queue.Dequeue() == 1);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    assert(queue.Dequeue() == 2);
    assert(queue.Dequeue() == 3);
    assert(queue.Dequeue() == 4);
    assert(queue.Dequeue() == 5);

    MyStack<int> stack;
    stack.Push(1);
    stack.Push(2);
    assert(stack.Pop() == 2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    assert(stack.Pop() == 5);
    assert(stack.Pop() == 4);
    assert(stack.Pop() == 3);
    assert(stack.Pop() == 1);
}

int main() {
    Test();
    return 0;
}
