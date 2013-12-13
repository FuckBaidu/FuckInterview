/**
 * 3.2 in <Crack the code interview>.
 * How would you design a stack which, in addition to push and pop, also has a
 * funtion min which returns the mininum element? All functions should operates
 * in O(1) time
 */
#include "util.h"
template <class T>
struct MinStackElement{
    T cur_value;
    T min_value;
};

template <class T>
class MinStack : public Stack<T> {
public:
    virtual T pop() {
        return _imp.pop().cur_value;
    }

    virtual void push(T value) {
        MinStackElement<T> e;
        if (_imp.empty() || value < _imp.peek().min_value)
            e.min_value = value;
        else
            e.min_value = _imp.peek().min_value;
        e.cur_value = value;
        return _imp.push(e);
    }

    virtual T peek() {
        return _imp.peek().cur_value;
    }

    virtual T min() {
        return _imp.peek().min_value;
    }

    virtual bool empty() {
        return _imp.empty();
    }
private:
    ArrayStack< MinStackElement<T> > _imp;
};

template <class T>
class MinStack1 : public Stack<T> {
public:
    virtual T pop() {
        T value = _elements.pop();
        if (value == _min.peek())
            _min.pop();
        return value;
    }

    virtual void push(T value) {
        if (_min.empty() || value <= _min.peek())
            _min.push(value);
        _elements.push(value);
    }

    virtual T peek() {
        return _elements.peek();
    }

    virtual T min() {
        return _min.peek();
    }

    virtual bool empty() {
        return _elements.empty();
    }
private:
    ArrayStack<T> _elements;
    ArrayStack<T> _min;
};

void Test() {
    MinStack1<int> stack;
    stack.push(5);
    assert(stack.peek() == 5);
    assert(stack.min() == 5);
    stack.push(7);
    assert(stack.peek() == 7);
    assert(stack.min() == 5);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    assert(stack.peek() == 1);
    assert(stack.min() == 1);
    assert(stack.pop() == 1);
    assert(stack.peek() == 2);
    assert(stack.min() == 2);
    assert(stack.pop() == 2);
    assert(stack.peek() == 3);
    assert(stack.min() == 3);
}

int main() {
    Test();
    return 0;
}
