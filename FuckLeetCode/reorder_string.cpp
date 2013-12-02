/**
 * Given a string of lowercase characters, reoder them such that the same 
 * characters are at least distance d from each other
 * Input: {a, b, b}, distance = 2
 * Output: {b, a, b}
 * http://leetcode.com/2010/05/here-is-another-google-phone-interview.html
 */
#include <iostream>
#include <string>
#include <queue>
#define N 26
struct Stat {
    char a;
    int count;
};

void Sort(Stat stats[]) {
    for (int i = 0; i < N - 1; i++) {
        int j = i + 1;
        Stat tmp = stats[j];
        while (j > 0 && stats[j].count > stats[j - 1].count) {
            stats[j] = stats[j - 1];
            j--;
        }
        stats[j] = tmp;
    }
}

void ReorderString(const std::string &input, int distance) {
    char *output = new char[input.length() + 1];
    memset(output, 0, input.length());
    Stat stats[N];
    for (int i = 0; i < N; i++) {
        stats[i].a = 'a' + i;
        stats[i].count = 0;
    }
    for (int i = 0; i < input.length(); i++)
        stats[input[i] - 'a'].count++;
    Sort(stats);

    std::cout << "Input:" << input << std::endl;
    for (int i = 0; i < N && stats[i].count != 0; i++) {
        char cur_char = stats[i].a;
        int pos = 0, cur_count = stats[i].count, cur_distance = (input.length() + 1)/ cur_count;
        if (cur_distance < distance) {
            std::cout << "No Solution for distance " << distance << std::endl;
            return;
        }
        for (int j = 0; j < cur_count; j++) {
            while (output[pos] != 0 && pos < input.length()) {
                pos++;
            }
            if (pos == input.length()) {
                std::cout << "No Solution for distance " << distance << std::endl;
                return;
            }
            output[pos] = stats[i].a;
            pos += cur_distance;
        }
    }

    std::cout << "Reodered string: " << output << " for distance: " << distance << std::endl;
}


int main() {
    ReorderString("a", 2);
    ReorderString("abb", 2);
    ReorderString("abcba", 3);
    ReorderString("abbba", 3);
    ReorderString("abcba", 2);
    return 0;
}
