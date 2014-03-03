#include <list>
#include <string>
#include <vector>
#include <pthread.h>
#include <assert.h>

struct Node {
    std::string key;
    std::string value;
    Node (const std::string &k, const std::string &v) : key(k), value(v) { }
};

class LockHelper {
public:
    LockHelper(pthread_spinlock_t *lock) : _lock(lock) {
        pthread_spin_lock(_lock);
    }

    ~LockHelper() {
        pthread_spin_unlock(_lock);
    }
private:
    pthread_spinlock_t *_lock;
};

struct List {
    pthread_spinlock_t lock;
    std::list<Node> impl;
    List() {
        pthread_spin_init(&lock, 0);
    }

    ~List() {
        pthread_spin_destroy(&lock);
    }
};

#define PRIME 100007
static int base = 0;
class HashMap {
public:
    HashMap(int num_bucket) {
        _impl.resize(num_bucket);
    }

    void Set(const std::string &key, const std::string &value) {
        int hash = _HashFunc(key);
        List &list = _impl[hash % _impl.size()];
        LockHelper lock_helper(&list.lock);
        // check if exist
        std::list<Node>::iterator iter = list.impl.begin();
        while (iter != list.impl.end()) {
            if ((*iter).key == key) {
                (*iter).value = value;
                return;
            }
            ++iter;
        }
        // Insert
        Node node(key, value);
        list.impl.push_front(node);
    }

    std::string Get(const std::string &key) {
        int hash = _HashFunc(key);
        List &list = _impl[hash % _impl.size()];
        std::string result;
        LockHelper lock_helper(&list.lock);
        // check if exist
        std::list<Node>::const_iterator iter = list.impl.begin();
        while (iter != list.impl.end()) {
            if ((*iter).key == key) {
                result = (*iter).value;
                break;
            }
            ++iter;
        }
        return result;
    }
private:
    int _HashFunc(const std::string &key) {
        int hash = base;
        for (int i = 0; i < key.length(); i++)
            hash = hash * PRIME + key[i];
        return hash;
    }

    std::vector<List> _impl;
    int _num_bucket;
};

int main() {
    srand(time(NULL));
    base = rand();
    HashMap hash_map(2);
    hash_map.Set("fuck", "you");
    hash_map.Set("love", "me");
    hash_map.Set("hate", "him");
    hash_map.Set("kill", "her");
    assert(hash_map.Get("fuck") == "you");
    assert(hash_map.Get("love") == "me");
    assert(hash_map.Get("hate") == "him");
    assert(hash_map.Get("kill") == "her");
    hash_map.Set("hate", "them");
    assert(hash_map.Get("hate") == "them");
    return 0;
}
