/*
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of
 * the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * Visually, the graph looks like the following:
 *     1
      / \
     /   \
    0 --- 2
         / \
         \_/
 */
#include <vector>
#include <queue>
#include <ext/hash_map>
struct Node {
     int label;
     std::vector<Node *> neighbors;
     Node(int x) : label(x) {};
};

struct Hash {
    size_t operator()(Node * const &ptr) const {
        return (long)ptr;
    }
};

Node *CloneGraph(Node *node) {
    if (!node)
        return NULL;
    std::queue<Node*> queue;
    __gnu_cxx::hash_map<Node*, Node*, Hash> hash_map;
    Node *root = new Node(node->label);
    root->neighbors = node->neighbors;
    queue.push(root);
    hash_map[node] = root;
    while (!queue.empty()) {
        Node *cur = queue.front();
        queue.pop();
        for (int i = 0; i < cur->neighbors.size(); i++) {
            Node *adj = cur->neighbors[i];
            if (hash_map.count(adj)) {
                // visited
                cur->neighbors[i] = hash_map[adj];
            } else {
                // not visit
                Node *new_node = new Node(adj->label);
                new_node->neighbors = adj->neighbors;
                cur->neighbors[i] = new_node;
                hash_map[adj] = new_node;
                queue.push(new_node);
            }
        }
    }
    return root;
}
int main() {
    return 0;
}
