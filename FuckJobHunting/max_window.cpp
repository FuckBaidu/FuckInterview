/*
 * given a string, find the longest substring which contains two different characters
 * Eg:
 * Input: aabfaaaa
 * Output: 5
**/
#include <iostream>
#include <vector>
bool Exists(char cache[], char c) {
    return cache[0] == c || cache[1] == c;
}
int GetMaxWindow1(const std::string &str) {
    int begin = 0, max = 0, count = 0;
    int index[2] = {-1, -1};
    for (int end = 0; end < str.length(); end++) {
        if (count < 2) {
            if (index[0] == -1)
                index[0] = end;
            else if (index[1] == -1)
                index[1] = end;
            count++;
        } else {
            if (str[end] == str[index[0]]) {
                index[0] = end;
            } else if (str[end] == str[index[1]]) {
                index[1] = end;
            } else {
                begin = index[1];
                index[0] = index[1];
                index[1] = end;
            }
            int cur_len = end - begin + 1;
            if (max < cur_len)
                max = cur_len;
        }
    }
    return max;
}

int GetMaxWindow(const std::string &str) {
    int max = 0, begin = 0, count = 0;
    char cache[2]  = {-1, -1};
    int counts[2] = {0, 0};
    for (int end = 0; end < str.length(); end++) {
        if (!Exists(cache, str[end])) {
            if (count < 2) {
                if (cache[0] == -1) {
                    cache[0] = str[end];
                    counts[0] = 1;
                } else if (cache[1] == -1) {
                    cache[1] = str[end];
                    counts[1] = 1;
                } 
                count++;
            } else {
                char cur_char = str[begin];
                int cur_count = counts[0];
                while (cur_count&& begin < (int)str.length() - 1) {
                    if (str[begin] == cur_char)
                        cur_count--;
                    begin++;
                }
                cache[0] = cache[1];
                cache[1] = str[end];
                counts[0] = counts[1];
                counts[1] = 1;
            }
        } else {
            if (str[end] == cache[0])
                counts[0]++;
            else
                counts[1]++;
        }
        int cur_len = end - begin + 1;
        if (max < cur_len && count == 2)
            max = cur_len;
    }
        return max;
}

void Test(const std::string &str) {
    std::cout << "max length of" << str << " is " << GetMaxWindow1(str)   << std::endl;
}

int main() {
    Test("jgiahgghllpa");
    Test("abababfffffff");
    return 0;
}
