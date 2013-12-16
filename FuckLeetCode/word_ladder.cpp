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
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <ext/hash_set>

struct Hash {
    size_t operator()(const std::string &s) const {
        unsigned seed = 131, hash = 0;
        const char *str = s.c_str();
        while (*str)
            hash = hash * seed + *str++;
        return hash;
    }
};

void BuildResult(const std::string &cur, std::map< std::string, std::vector<std::string> > &path,
                 std::vector< std::vector<std::string> > &result) {
    if (path.count(cur) != 0) {
        const std::vector<std::string> &prevs = path[cur];
        if (prevs.empty()) {
            result.push_back(prevs);
            result.back().push_back(cur);
        } else {
            for (int i = 0; i < prevs.size(); i++) {
                std::vector< std::vector<std::string> > tmp_result;
                BuildResult(prevs[i], path, tmp_result);
                for (int j = 0; j < tmp_result.size(); j++)
                    tmp_result[j].push_back(cur);
                result.insert(result.end(), tmp_result.begin(), tmp_result.end());
            }
        }
    }
}

typedef __gnu_cxx::hash_set<std::string, Hash> HashSet;

std::vector<std::vector< std::string> > FindLadders(const std::string &start, const std::string &end,
                                                    const HashSet &dict) {
    std::map< std::string, std::vector<std::string> > path;
    std::queue<std::string> cur, next;
    std::set<std::string> next_strs;
    cur.push(start);
    path[start] = std::vector<std::string>();
    while (!cur.empty()) {
        std::string cur_str = cur.front();
        cur.pop();
        if (cur_str == end)
            break;
        for (int i = 0; i < cur_str.length(); i++) {
            std::string next_str = cur_str;
            for (char j = 'a'; j <= 'z'; j++) {
                next_str.replace(i, 1, 1, j);
                if (next_str == cur_str)
                    continue;
                if (dict.count(next_str) != 0 || next_str == end) {
                    // not visited
                    if (path.count(next_str) == 0) {
                        next.push(next_str);
                        next_strs.insert(next_str);
                        path[next_str] = std::vector<std::string>();
                    }

                    if (next_strs.count(next_str) != 0)
                        path[next_str].push_back(cur_str);
                }
            }
        }

        if (cur.empty()) {
            std::swap(cur, next);
            next_strs.clear();
        }
    }
    std::vector< std::vector<std::string> > result;
    BuildResult(end, path, result);
    return result;
}

int main() {
    HashSet a;
    a.insert("hot");
    a.insert("dot");
    a.insert("dog");
    a.insert("lot");
    a.insert("log");
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
