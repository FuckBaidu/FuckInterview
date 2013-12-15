/*
 *Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: 
 get and set.

 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
                   it should invalidate the least recently used item before inserting a new item.
http://oj.leetcode.com/problems/lru-cache/
 */
#include <ext/hash_map>
#include <assert.h>

struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int _key, int _value) : key(_key), value(_value){
        prev = this;
        next = this;
    }
};

class LRUCache{
public:
    LRUCache(int capacity) {
        _size = 0;
        _capacity = capacity;
        _head = new Node(0, 0);
    }
    
    int Get(int key) {
        if (_map.count(key) != 0) {
            Node *node = _map[key];
            // drop node off the list
            node->prev->next = node->next;
            node->next->prev = node->prev;
            // insert after head
            node->prev = _head;
            node->next = _head->next;
            _head->next->prev = node;
            _head->next = node;
            return node->value;
        } else {
            return -1;
        }
    }
    
    void Set(int key, int value) {
        Node *node;
        if (_map.count(key) != 0) {
            node = _map[key];
            // Update it
            node->value = value;
        } else {
            if (_size == _capacity) {
                node = _head->prev;
                _map.erase(node->key);
                // Update it
                node->key = key;
                node->value = value;
            } else {
                node = new Node(key, value);
                _size++;
            }
        }
        // Remove from list
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        // Insert after head
        node->prev = _head;
        node->next = _head->next;
        _head->next->prev = node;
        _head->next = node;
        _map[key] = node;
    }
private:
    __gnu_cxx::hash_map<int, Node*> _map;
    Node *_head;
    int _size;
    int _capacity;
};

int main() {
    LRUCache a(2);
    a.Set(2, 1);
    a.Set(1, 1);
    a.Set(2, 3);
    a.Set(4, 1);
    assert(a.Get(1) == -1);
    assert(a.Get(2) == 3);
    assert(a.Get(4) == 1);

    return 0;
}
