/*
 * Given two words (start and end), and a dictionary, find all shortest transformation sequence(s)
 * from start to end, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * Return
 * [
 *     ["hit","hot","dot","dog","cog"],
 *     ["hit","hot","lot","log","cog"]
 * ]
 * Note:
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 */
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <assert.h>
#include <ext/hash_set>
#include <ext/hash_map>

struct Hash {
    size_t operator()(const std::string &s) const {
        unsigned seed = 131, hash = 0;
        const char *str = s.c_str();
        while (*str)
            hash = hash * seed + *str++;
        return hash;
    }
};

typedef __gnu_cxx::hash_set<std::string, Hash> HashSet;
typedef __gnu_cxx::hash_map<std::string, std::vector<std::string>, Hash> HashMap;

void BuildResult(const std::string &start, const std::string &end,
                 HashMap &backtrace, std::vector<std::string> &path,
                 std::vector< std::vector<std::string> > &result) {
    if (start == end) {
        std::vector<std::string> tmp(path.rbegin(), path.rend());
        result.push_back(tmp);
    } else {
        std::vector<std::string> &prev = backtrace[end];
        for (int i = 0; i < prev.size(); i++) {
            path.push_back(prev[i]);
            BuildResult(start, prev[i], backtrace, path, result);
            path.pop_back();
        }
    }                    
}

std::vector< std::vector<std::string> > FindLadders(const std::string &start, const std::string &end, HashSet &dict) {
    HashMap backtrace;
    std::queue<std::string> cur_queue, next_queue;
    HashSet visited, next_valid_strs;
    bool has_found = false;
    cur_queue.push(start);
    visited.insert(start);
    while (!cur_queue.empty()) {
        std::string cur = cur_queue.front();
        cur_queue.pop();
        for (int i = 0; i < cur.length(); i++) {
            std::string next(cur);
            for (char j = 'a'; j <= 'z'; j++) {
                next[i] = j;
                if (next == end)
                    has_found = true;
                if (dict.count(next) && !visited.count(next)) {
                    next_queue.push(next);
                    visited.insert(next);
                    next_valid_strs.insert(next);
                }
                if (next == end || next_valid_strs.count(next))
                    backtrace[next].push_back(cur);
            }
        }
        if (cur_queue.empty()) {
            if (has_found)
                break;
            next_valid_strs.clear();
            std::swap(cur_queue, next_queue);
        }
    }
    std::vector<std::string> path;
    std::vector< std::vector<std::string> > result;
    if (has_found) {
        path.push_back(end);
        BuildResult(start, end, backtrace, path, result);
    }
    return result;
}

int LadderLength(std::string start, std::string end, HashSet &dict) {
    int len = 1;
    std::set<std::string> visited;
    std::queue<std::string> cur, next;
    cur.push(start);
    visited.insert(start);
    if (start == end)
        return len;
    while (!cur.empty()) {
        std::string cur_str = cur.front();
        cur.pop();

        for (int i = 0; i < cur_str.length(); i++) {
            std::string next_str = cur_str;
            for (char j = 'a'; j <= 'z'; j++) {
                next_str.replace(i, 1, 1, j);
                if (next_str == end)
                    return len + 1;
                if (dict.count(next_str) != 0 && visited.count(next_str) == 0) {
                    next.push(next_str);
                    visited.insert(next_str);
                }
            }
        }
        if (cur.empty()) {
            std::swap(cur, next);
            len++;
        }
    }
    
    return 0;
}
int main() {
    HashSet a;
    a.insert("hot");
    a.insert("dot");
    a.insert("dog");
    a.insert("lot");
    a.insert("log");
    assert(LadderLength("hit", "cog", a) == 5);
    std::vector< std::vector<std::string> > result;
    result = FindLadders("hit", "cog", a);
    std::cout << "From hit to cog:" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j != result[i].size() - 1)
                std::cout << "->";
        }
        std::cout << std::endl;
    }
    HashSet b;
    b.insert("a");
    b.insert("b");
    b.insert("c");
    assert(LadderLength("a", "c", b) == 2);
    result = FindLadders("a", "c", b);
    std::cout << "From a to c:" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j != result[i].size() - 1)
                std::cout << "->";
        }
        std::cout << std::endl;
    }
    return 0;
}
