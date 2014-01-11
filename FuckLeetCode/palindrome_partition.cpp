/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
 */
#include <string>
#include <vector>
#include <iostream>

bool IsPalindrome(const std::string &s) {
     int begin = 0, end = s.length() - 1;
     while (begin < end) {
         if (s[begin] != s[end])
             return false;
         begin++;
         end--;
     }
     return true;
 }
 
 void Partition(const std::string &s, int start, std::vector<std::string> &path, std::vector< std::vector<std::string> > &result) {
    if (start == s.length()) {
        result.push_back(path);
    } else {
        for (int i = start; i < s.length(); i++) {
            std::string cur = s.substr(start, i - start + 1);
            if (IsPalindrome(cur)) {
                 path.push_back(cur);
                 Partition(s, i + 1, path, result);
                 path.pop_back();
            }
        }
    }
}

std::vector< std::vector<std::string> > Partition(const std::string &s) {
    std::vector<std::string> path;
    std::vector< std::vector<std::string> > result;
    if (!s.empty())
        Partition(s, 0, path, result);
    return result;
}

int main() {
    std::vector< std::vector<std::string> > result = Partition("abaaba");
    std::cout << "Partition for abaaba is:" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}
