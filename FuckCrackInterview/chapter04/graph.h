#ifndef  __GRAPH_H_
#define  __GRAPH_H_
#include <vector>
#include <algorithm>
template <class T>
struct Node;
template <class T>
struct Adj {
    Node<T> *node;
    Adj *next;
    Adj() : next(NULL), node(NULL) {}
};

template <class T>
struct Node {
    T value;
    Adj<T> head;
    bool operator==(const Node<T> &other) {
        return value == other.value;
    }
    Node(T _value) : value(_value) {}
};

template <class T>
class Graph {
public:
    void AddNode(T value) {
        Node<T> node(value);
        if (std::find(_nodes.begin(), _nodes.end(), node) == _nodes.end())
            _nodes.push_back(node);
    }

    void AddEdge(std::pair<T, T> edge) {
        int src_index = -1, dst_index = -1;
        for (int i = 0; i < _nodes.size(); i++) {
            if (_nodes[i] == edge.first)
                src_index = i;
            if (_nodes[i] == edge.second)
                dst_index = i;
        }
        if (src_index == -1 || dst_index == -1)
            return;
        Node<T> *src = &_nodes[src_index];
        Node<T> *dst = &_nodes[dst_index];
        for (Adj<T> *adj = src->head.next; adj != NULL; adj = adj->next)
            if (adj->node == dst)
                return;
       Adj<T> *adj = new Adj<T>;
       adj->node = dst;
       adj->next = src->head.next;
       src->head.next = adj;
    }

    const std::vector< Node<T> >& GetNodes() { return _nodes;}
private:
    std::vector< Node<T> > _nodes;
};
#endif  //__GRAPH_H_
