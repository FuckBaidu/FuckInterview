/**
 * 1.5 in <Crack the code interview> 5th edition.
 * Implement a method to perform string compression using the counts of repeated characters
 * Example:
 * Input: aabcccccaaa
 * Output: a2b1c5a3
 * If the compressed string is not smaller than the original string, you should return the original
 * one
 */
#include <iostream>
#include <string>

std::string Compress(const std::string &original_str) {
    std::string compressed_str;
    char cur;
    int count = 0;
    for (int i = 0; i < original_str.length(); i++) {
        if (original_str[i] != cur || i == 0) {
            if (count != 0)
                compressed_str.push_back('0' + count);
            count = 0;
            cur = original_str[i];
            compressed_str.push_back(cur);
        }
        count++;
    }
    if (count != 0)
        compressed_str.push_back('0' + count);
    if (compressed_str.length() > original_str.length())
        return original_str;
    else
        return compressed_str;
}

void Test(const std::string &str) {
    std::cout << "Compressed string of " << str << " is " << Compress(str) << std::endl;
}

int main() {
    Test("aabcccccaaa");
    Test("abc");
    return 0;
}
