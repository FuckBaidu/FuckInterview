/**
 * 20.5 in <Crack the code interview>.
 * You have a large text file contains words. Given two words, find the shortest
 * distance between them in the file (in terms of number of words)
 */
#if __GNUC__ > 2
#include <ext/hash_map>
using __gnu_cxx::hash_map;
#else
#include <hash_map>
#endif
#include <fstream>
#include <string>
#include <stdlib.h>
#include <assert.h>

static const char *kPath = "./shortest_distance_of_two_words.cpp";
struct Hash{
    size_t operator()(const std::string& s) const {
        unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;

        const char *str = s.c_str();
        while (*str)
        {
            hash = hash * seed + (*str++);
        }

        return (hash & 0x7FFFFFFF);
    }
};
typedef hash_map<std::string, std::vector<int>, Hash> HashMap;

int GetDistance(const std::string &a, const std::string &b, HashMap &hash_map) {
    if (hash_map.count(a) == 0 || hash_map.count(b) == 0)
        return INT_MAX;
    std::vector<int> &a_pos = hash_map[a], &b_pos = hash_map[b];
    int distance = INT_MAX;
    int i = 0, j = 0;
    while (i < a_pos.size() && j < b_pos.size()) {
        int cur_distance = abs(a_pos[i] - b_pos[j]);
        if (cur_distance < distance)
            distance = cur_distance;
        if (a_pos[i] < b_pos[j])
            i++;
        else
            j++;
    }
    return distance;
}

void BuildHashMap(HashMap &hash_map) {
    std::ifstream ifs;
    ifs.open(kPath);
    if (ifs.is_open()) {
        int count = 0;
        std::string cur;
        while (!ifs.eof()) {
            ifs >> cur;
            if (hash_map.count(cur) == 0)
                hash_map[cur] = std::vector<int>();
            std::vector<int> &vec = hash_map[cur];
            vec.push_back(count);
            count++;
        }
    }
}

int main() {
    HashMap hash_map;
    BuildHashMap(hash_map);
    assert(GetDistance("the", "file", hash_map) == 1);
    return 0;
}
