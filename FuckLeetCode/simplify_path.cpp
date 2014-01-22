/*
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 */
#include <string>
#include <vector>
#include <iostream>

std::string SimplifyPath(const std::string &path) {
    std::string result(1, '/');
    std::vector<std::string> components;
    bool is_in_word = false;
    int begin = 0;
    for (int end = 0; end <= path.length(); end++) {
        if (path[end] == '/' || end == path.length()) {
            if (is_in_word) {
                std::string cur = path.substr(begin, end - begin);
                if (cur == "..") {
                    if (!components.empty())
                        components.pop_back();
                } else if (cur != "."){
                    components.push_back(cur);
                }
                is_in_word = false;
            }
        } else {
            if (!is_in_word) {
                begin = end;
                is_in_word = true;
            }
        }
    }
    for (int i = 0; i < components.size(); i++) {
        result += components[i];
        if (i != (int)components.size() - 1)
            result += "/";
    }
    return result;
}

void Test(const std::string &path) {
    std::cout << "original path is " << path << std::endl;
    std::cout << "path after simplify is " << SimplifyPath(path) << std::endl;
}

int main() {
    Test("a");
    Test("/home/");
    Test("/../");
    Test("/...");
    Test("/./");
    Test("/abc/...");
    Test("/home//foo/");
    Test("/a/./b/../../c/");
    return 0;
}
