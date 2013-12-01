/*
 * Print all permutations and implement a method to get the next permutation of a string
 */
#include <string>
#include <vector>
#include <iostream>
void Permutation(int pos, char *str, int len, std::vector<std::string> &result) {
    if (pos == len) {
        result.push_back(str);
        return;
    } else {
        for (int i = pos; i < len; i++) {
            if (str[i] == str[pos] && i != pos)
                continue;
            std::swap(str[i], str[pos]);
            Permutation(pos + 1, str, len, result);
            std::swap(str[i], str[pos]);
        }
    }
}

std::string NextPermutation(const std::string &str) {
    char *buf = new char[str.length() + 1];
    buf[str.length()] = '\0';
    memcpy(buf, str.c_str(), str.length());
    if (str.length() <= 1)
        return str;
    int i = str.length() - 2;
    for (; i >= 0; i--) {
        if (str[i] < str[i + 1])
            break;
    }
    if (i == -1)
        return str;
    int j = str.length() - 1;
    for (; j >= 0; j--) {
        if (str[j] > str[i])
            break;
    }
    std::swap(buf[i], buf[j]);
    ++i;
    j = str.length() - 1;
    while (i < j) {
        std::swap(buf[i], buf[j]);
        i++;
        j--;
    }

    std::string result(buf);
    delete[] buf;
    return result;
}

void Test(const std::string &str) {
    char *buf = new char[str.length() + 1];
    buf[str.length()] = '\0';
    memcpy(buf, str.c_str(), str.length());
    std::vector<std::string> result;
    Permutation(0, buf, str.length(), result);
    std::cout << "Permutations of " << str << " is:" <<std::endl;
    for (int i = 0; i < result.size(); i++) 
        std::cout << result[i] << ".Next is " << NextPermutation(result[i]) << std::endl;
    delete[] buf;
}

int main() {
    Test("ABCD");
    Test("AACD");
    Test("AAAD");
    return 0;
}
