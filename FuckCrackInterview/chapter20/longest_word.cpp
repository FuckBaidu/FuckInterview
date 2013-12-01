/**
 * 20.10 in <Crack the code interview>.
 * Write a program to find the longest word which is made of other words in the
 * list of words
 */
#include <iostream>
#include <vector>
#include <string>
#include <ext/hash_set>
#include <algorithm>
bool Compare(const std::string &left, const std::string &right) {
    if (left.length() == right.length()) {
        return left.compare(right) < 0;
    } else {
        return left.length() < right.length();
    }
}

unsigned int MurmurHash2(const void * key, int len, unsigned int seed) {
    // 'm' and 'r' are mixing constants generated offline.
    // They're not really 'magic', they just happen to work well.

    const unsigned int m = 0x5bd1e995;
    const int r = 24;

    // Initialize the hash to a 'random' value

    unsigned int h = seed ^ len;

    // Mix 4 bytes at a time into the hash

    const unsigned char * data = (const unsigned char *)key;

    while(len >= 4)
    {
        unsigned int k = *(unsigned int *)data;

        k *= m; 
        k ^= k >> r; 
        k *= m; 
        h *= m; 
        h ^= k;

        data += 4;
        len -= 4;
    }
    // Handle the last few bytes of the input array

    switch(len)
    {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
            h *= m;
    };

    // Do a few final mixes of the hash to ensure the last few
    // bytes are well-incorporated.

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

struct Hash{
    size_t operator()(const std::string& s) const {
        return MurmurHash2(s.c_str(), s.length(), 12305);
    }
};

bool IsMakeOfOthers(const std::string &str, const __gnu_cxx::hash_set<std::string, Hash> &hash_set) {
    for (int i = 1; i < str.length(); i++) {
        std::string prefix = str.substr(0, i);
        if (hash_set.count(prefix)) {
            std::string suffix = str.substr(i, str.length() - i);
            if (hash_set.count(suffix))
                return true;
            else if (IsMakeOfOthers(suffix, hash_set))
                return true;
        }
    }
    return false;
}

int FindLongestWord(std::vector<std::string> &strs) {
    int index = -1;
    if (strs.size() != 0) {
        std::sort(strs.begin(), strs.end(), Compare);
        __gnu_cxx::hash_set<std::string, Hash> hash_set;
        for (int i = 0; i < strs.size(); i++)
            hash_set.insert(strs[i]);
        for (int i = strs.size() - 1; i >= 1; i--) {
            if (IsMakeOfOthers(strs[i], hash_set)) {
                index = i;
                break;
            }
        }
    }
    return index;
}

void Test(std::vector<std::string> &strs) {
    std::cout << "Input:" << std::endl;
    for (int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << std::endl;
    int index = FindLongestWord(strs);
    if (index == -1)
        std::cout << "Can't find the word which matches the requirement" << std::endl;
    else
        std::cout << "The longest word is: " << strs[index] << std::endl;
}

int main() {
    std::vector<std::string> strs;
    strs.push_back("cat");
    strs.push_back("cats");
    strs.push_back("catsdogcats");
    strs.push_back("catxdogcatsrat");
    strs.push_back("dog");
    strs.push_back("dogcatsdog");
    strs.push_back("hippopotamuses");
    strs.push_back("rat");
    strs.push_back("ratcatdogcat");
    Test(strs);
    strs.clear();
    strs.push_back("test");
    strs.push_back("testing");
    strs.push_back("tester");
    strs.push_back("testingtester");
    strs.push_back("testertest");
    Test(strs);
    return 0;
}
