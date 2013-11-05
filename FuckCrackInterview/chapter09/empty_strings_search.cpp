/**
 * 9.5 in <Crack the code interview>.
 * Given a sorted array of strings which is represented with empty strings,
 * Write a method to find the location of a given string
 */
#include <iostream>
#include <string>
#include <vector>

int FindStringWithEmpty(const std::vector<std::string> &strings, const std::string &key) {
    int result = -1;
    int begin = 0, end = strings.size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (!strings[mid].empty()) {
            int cmp = key.compare(strings[mid]);
            if (cmp == 0) {
                result = mid;
                break;
            } else if (cmp < 0) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        } else {
            int upper = -1, lower = -1;
            for (int i = mid + 1; i < strings.size(); i++) {
                if (!strings[i].empty()) {
                    upper = i;
                    break;
                }
            }
            for (int i = mid - 1; i >= 0; i--) {
                if (!strings[i].empty()) {
                    lower = i;
                    break;
                }
            }
            if (lower != -1 && key.compare(strings[lower]) <= 0) {
                end = lower;
            } else if (upper != -1 && key.compare(strings[upper]) >= 0) {
                begin = upper;
            } else {
                break;
            }
        }
    }
    return result;
}

void Test(const char *str) {
    std::string a[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    std::vector<std::string> test(a, a + 13);
    int index = FindStringWithEmpty(test, str);
    if (index == -1)
        std::cout << "Not Found: " << str << std::endl;
    else
        std::cout << "Found: " << str << " at " << index << std::endl;
}

int main() {
    Test("ball");
    Test("at");
    Test("dad");
    Test("car");
    Test("fuck");
    Test("ballcar");
    return 0;
}
