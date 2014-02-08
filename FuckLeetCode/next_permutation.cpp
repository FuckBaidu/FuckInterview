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
            while (i < len - 1 && str[i + 1] == str[i])
                i++;
        }
    }
}

std::string NextPermutation(const std::string &str) {
    std::string result = str;
    int i = (int)result.length() - 2;
    for ( ; i >= 0; i--)
        if (result[i] < result[i + 1])
            break;
    if (i != -1) {
        int j = i + 1;
        while (j < result.size() && result[j] > result[i])
            j++;
        std::swap(result[i], result[--j]);
    }
    std::reverse(result.begin() + i + 1, result.end());
    return result;
}

void Test(const std::string &str) {
    char *buf = new char[str.length() + 1];
    buf[str.length()] = '\0';
    memcpy(buf, str.c_str(), str.length());
    std::sort(buf, buf + str.length());
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
    Test("121");
    Test("1201303");
    return 0;
}
