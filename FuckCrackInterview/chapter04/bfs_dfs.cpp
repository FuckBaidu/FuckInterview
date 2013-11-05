/**
 * 4.2 in <Crack the code interview>.
 * Given a directed graph, design an algorithm to find out whether 
 * there is a route between two nodes
 */
#include "graph.h"
#include <queue>
#include <set>
#include <stack>
#include <assert.h>
template <class T>
class Base {
public:
    virtual bool HasRoute(const Node<T> *n1, const Node<T> *n2) = 0;
};

template <class T>
class BFS : public Base<T> {
public:
    virtual bool HasRoute(const Node<T> *src, const Node<T> *dst) {
        if (src == dst)
            return true;
        std::queue<const Node<T>*> queue;
        std::set<const Node<T>*> set;
        queue.push(src);
        while (!queue.empty()) {
            const Node<T> *node = queue.front();
            queue.pop();
            for (Adj<T> *adj = node->head.next; adj != NULL; adj = adj->next) {
                if (set.count(adj->node) == 0) {
                    if (adj->node == dst)
                        return true;
                    queue.push(adj->node);
                    set.insert(adj->node);
                }
            }
        }
        return false;
    }
};

template <class T>
class DFS : public Base<T> {
public:
    virtual bool HasRoute(const Node<T> *src, const Node<T> *dst) {
        if (src == dst)
            return true;
        std::stack<const Node<T>*> stack;
        std::set<const Node<T>*> set;
        stack.push(src);
        while (!stack.empty()) {
            const Node<T> *node = stack.top();
            stack.pop();
            for (Adj<T> *adj = node->head.next; adj != NULL; adj = adj->next) {
                if (set.count(adj->node) == 0) {
                    if (adj->node == dst)
                        return true;
                    stack.push(adj->node);
                    set.insert(adj->node);
                }
            }
        }
        return false;
    }
};

int main() {
    Graph<int> graph;
    for (int i = 0; i < 10; i++)
        graph.AddNode(i);
    graph.AddEdge(std::make_pair(0, 1));
    graph.AddEdge(std::make_pair(0, 2));
    graph.AddEdge(std::make_pair(0, 3));
    graph.AddEdge(std::make_pair(2, 5));
    graph.AddEdge(std::make_pair(5, 7));
    graph.AddEdge(std::make_pair(5, 8));
    graph.AddEdge(std::make_pair(5, 9));
    graph.AddEdge(std::make_pair(4, 6));
    Base<int> *algo[2];
    algo[0] = new BFS<int>;
    algo[1] = new DFS<int>;
    const std::vector< Node<int> > &nodes = graph.GetNodes();
    for (int i = 0; i < 2; i++) {
        assert(algo[i]->HasRoute(&nodes[4], &nodes[6]));
        assert(algo[i]->HasRoute(&nodes[0], &nodes[9]));
        assert(!algo[i]->HasRoute(&nodes[0], &nodes[6]));
        assert(!algo[i]->HasRoute(&nodes[2], &nodes[6]));
        assert(algo[i]->HasRoute(&nodes[2], &nodes[7]));
        assert(!algo[i]->HasRoute(&nodes[1], &nodes[7]));
    }
    return 0;
}
