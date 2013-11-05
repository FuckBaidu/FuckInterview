#ifndef  __UTIL_H_
#define  __UTIL_H_
#include <iostream>
#include <assert.h>

template <class T>
class Stack {
public:
    Stack() : _size(0) {}
    virtual ~Stack() {}
    virtual T pop() = 0;
    virtual T peek() = 0;
    virtual bool empty() { return _size == 0; }
    virtual void push(T element) = 0;
protected:
    int _size;
};

#define ARRAYSIZE 1024
template <class T>
class ArrayStack : public Stack<T> {
public:
    ArrayStack() : _top(-1) {}
    virtual T pop() {
        assert(_top != -1);
        Stack<T>::_size--;
        return _array[_top--];
    }

    virtual T peek() {
        assert(_top != -1);
        return _array[_top];
    }

    virtual void push(T element) {
        assert(_top != ARRAYSIZE);
        Stack<T>::_size++;
        _array[++_top] = element;
    }
private:
    int _top;
    T _array[ARRAYSIZE];
};

template <class T>
struct Node {
    T value;
    Node *next;
    Node(T _value) : value(_value), next(NULL) {}
};

template <class T>
void FreeList(Node<T> *head) {
    Node<T> *cur;
    while (head != NULL) {
        cur = head;
        head = head->next;
        delete cur;
    }
}

template <class T>
class LinkedStack : public Stack<T> {
public:
    LinkedStack() : _head(NULL) {}
    virtual ~LinkedStack() {
        FreeList(_head);
    }

    virtual T pop() {
        assert(_head);
        Node<T> *cur = _head;
        _head = _head->next;
        T value = cur->value;
        free(cur);
        Stack<T>::_size--;
        return value;
    }

    virtual T peek() {
        assert(_head);
        return _head->value;
    }

    virtual void push(T element) {
        Node<T> *cur = new Node<T>(element);
        cur->next = _head;
        _head = cur;
        Stack<T>::_size++;
    }
private:
    Node<T> *_head;
};

template <class T>
class Queue {
public:
    Queue() : _size(0) {}
    virtual ~Queue() {}
    virtual void enqueue(T v) = 0;
    virtual T dequeue() = 0;
    virtual bool empty() { return _size == 0; }
    virtual int size() { return _size; }
protected:
    int _size;
};

template <class T>
class ArrayQueue : public Queue<T> {
public:
    ArrayQueue() : _head(0), _tail(0), _tag(0) {}
    virtual T dequeue() {
        assert(_head != _tail || _tag != 0);
        Queue<T>::_size--;
        T value = _array[_head];
        _head = (_head + 1) % ARRAYSIZE;
        if (_tail == _head)
            _tag = 0;
        return value;
    }

    virtual void enqueue(T element) {
        assert(_head != _tail || _tag != 1);
        Queue<T>::_size++;
        _array[_tail] = element;
        _tail = (_tail + 1) % ARRAYSIZE;
        if (_tail == _head)
            _tag = 1;
    }

private:
    int _head;
    int _tail;
    int _tag;
    T _array[ARRAYSIZE];
};

template <class T>
class LinkedQueue : public Queue<T> {
public:
    LinkedQueue() : _head(NULL), _tail(NULL) { }
    virtual ~LinkedQueue() {
        FreeList(_head);
    }

    virtual T dequeue() {
        assert(_head);
        Node<T> *cur = _head;
        _head = _head->next;
        T value = cur->value;
        free(cur);
        Queue<T>::_size--;
        if (!_head)
            _tail = NULL;
        return value;
    }

    virtual void enqueue(T value) {
        Node<T> *cur = new Node<T>(value);
        if (!_tail) {
            _tail = cur;
            _head = _tail;
        } else {
            _tail->next = cur;
            _tail = cur;
        }
        Queue<T>::_size++;
    }
private:
    Node<T> *_head;
    Node<T> *_tail;
};

#endif  //__UTIL_H_
