/*
 * Given an array of words and a length L, format the text such that each line has exactly L
 * characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each
 * line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces
 * on a line do not divide evenly between words, the empty slots on the left will be assigned more
 * spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between
 * words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 */
#include <vector>
#include <string>
#include <iostream>
std::vector<std::string> FullJustify(std::vector<std::string> &words, int L) {
    std::vector<std::string> result;
    int i = 0;
    while (i < words.size()) {
        int word_len = words[i].size(), space_len = 0, j = i + 1, total_len;
        while (j < words.size() && (total_len = word_len + space_len + 1 + words[j].size()) <= L) {
            word_len += words[j].size();
            space_len++;
            j++;
        }
        space_len = L - word_len;
        std::string output = words[i];       
        bool is_left_justified = false;
        if (i == j - 1 || j == words.size())
            is_left_justified  = true;
        // only one word in the line
        for (int k = i + 1; k < j; k++) {
            int cur_space_len;
            if (is_left_justified) {
                cur_space_len = 1;
            } else {
                cur_space_len = space_len / (j - k);
                if (space_len % (j - k))
                    cur_space_len++;
            }
            output.append(cur_space_len, ' ');
            output += words[k];
            space_len -= cur_space_len;
        }
        // the trailing space for left justified
        if (space_len)
            output.append(space_len, ' ');
        result.push_back(output);
        i = j;
    }
    return result;
}

void Test(std::string A[], int n, int L) {
    std::vector<std::string> input(A, A + n);
    std::vector<std::string> output = FullJustify(input, L);
    std::cout << "Input: ";
    for (int i = 0; i < input.size(); i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
    std::cout << "output: " << std::endl;
    for (int i = 0; i < output.size(); i++) {
        std::cout << output[i] << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::string a[] = {"What","must","be","shall","be."};
    Test(a, 5, 12);
    std::string b[] = {"a","b","c","d","e"};
    Test(b, 5, 3);
    std::string c[] = {"Listen","to","many,","speak","to","a","few."};
    Test(c, 7, 6);
    std::string d[] = {"This", "is", "an", "example", "of", "text", "justification."};
    Test(d, 7, 16);
    return 0;
}
