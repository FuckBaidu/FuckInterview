/**
 * 20.10 in <Crack the code interview>.
 * Given two words of equal length that are in a dictionary, write a method 
 * to transform one word into another by changing only one letter at a time.
 * The new word you get in each step must be in the dictionary
 * Eg: Input: DAMP, LIKE
 *     Output: DAMP->LAMP->LIME->LIKE
 */
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <ext/hash_set>

struct Hash {
    size_t operator()(const std::string &str) const {
        unsigned long hash = 5381;
        for (int i = 0; i < str.length(); i++)
            hash = (hash << 5) + hash + str[i];
        return hash;
    }
};
typedef __gnu_cxx::hash_set<std::string, Hash> HashSet;

void PrintPath(const std::string &from, const std::string &to, std::map<std::string, std::string> &back_track_map) {
    if (from != to) {
        PrintPath(from, back_track_map[to], back_track_map);
        std::cout << "->";
    }
    std::cout << to;
}

void Transform(const std::string &from, const std::string &to, const HashSet &dict) {
    if (dict.count(from) && dict.count(to)) {
        std::queue<std::string> queue;
        std::map<std::string, std::string> back_track_map;
        queue.push(from);
        back_track_map[from] = "";
        while (!queue.empty()) {
            std::string cur = queue.front();
            queue.pop();
            if (cur == to) {
                PrintPath(from, to, back_track_map);
                std::cout << std::endl;
                return;
            } else {
                for (int i = 0; i < cur.length(); i++) {
                    for (char j = 'A'; j <= 'Z'; j++) {
                        std::string new_word = cur;
                        new_word.replace(i, 1, 1, j);
                        if (dict.count(new_word) && !back_track_map.count(new_word)) {
                            queue.push(new_word);
                            back_track_map[new_word] = cur;
                        }
                    }
                }
            }
        }
    }
    std::cout << "There is no path from " << from << " to " << to << std::endl;
}

int main() {
    HashSet dict;
    dict.insert("DAMP");
    dict.insert("LIKE");
    dict.insert("LIMP");
    dict.insert("DAME");
    dict.insert("DAKP");
    dict.insert("LIME");
    Transform("DAMP", "LIKE", dict);
    dict.insert("LAMP");
    Transform("DAMP", "LIKE", dict);
    dict.insert("DIKE");
    Transform("DAMP", "DIKE", dict);
    return 0;
}
