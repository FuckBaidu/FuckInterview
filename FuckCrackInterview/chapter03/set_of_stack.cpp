/**
 * 3.3 in <Crack the code interview>.
 * In real life, we would likely start a new stack when the previous stack exceeds
 * capacity.Implement a data structure SetOfStack, which should be composed of 
 * serveral stacks, and should create a new stack when the previous stack exceeds
 * capacity.
 */
#include "util.h"
#include <vector>
#define CAPACITY 5

template <class T>
class SetOfStacks : public Stack<T> {
public:
    virtual void push(T element) {
        if (_imp.empty() || _imp.back().size() == CAPACITY) {
           _imp.push_back(LinkedStack<T>());
        }
        LinkedStack<T> &stack = _imp.back();
        stack.push(element);
    }

    virtual T pop() {
        return pop_at(_imp.size() - 1);
    }

    virtual T peek() {
        assert(!_imp.empty);
        return _imp.back().peek();
    }

    T pop_at(int index) {
        assert(index >= 0 && index < _imp.size());
        LinkedStack<T> &stack = _imp[index];
        T value = stack.pop();
        if (stack.empty)
            _imp.erase(_imp.begin() + index);
        return value;
    }
private:
    std::vector< LinkedStack<T> > _imp;
};

int main() {
    return 0;
}
