/**
 * 17.14 in <Crack the code interview> 5th edition.
 * Desian an algorithm to find the optimal way of "uncatenating" a sequence of words
 * In this case, "optimal" is defined to be the parsing which minimizes the number
 * of unrecognized sequences of characters
 * Eg Input : "jesslookedjustliketimherbrother"
 * Output: "JESS looked just like TIM her brother"
 * This parsing has 7 unrecognized characters: "JESS" and "TIM"
 */
#include <set>
#include <string>
#include <iostream>
void ParseString(const std::string &str, const std::set<std::string> &dict) {
    if (str.empty())
        return;
    int *min_nums = new int[str.length()];
    int *parent = new int[str.length()];
    for (int i = 0; i < str.length(); i++) {
        min_nums[i] = dict.count(str.substr(0, i + 1))? 0 : i + 1;
        parent[i] = -1;
        for (int j = 0; j < i; j++) {
            int cur_num = min_nums[j];
            if (dict.count(str.substr(j + 1, i - j)) == 0)
                cur_num += i - j;
            if (cur_num < min_nums[i]) {
                min_nums[i] = cur_num;
                parent[i] = j;
            }
        }
    }
    std::string output;
    int j = str.length() - 1;
    for (int i = parent[j]; i != -1; i = parent[i]) {
        output.insert(0, " " + str.substr(i + 1, j - i));
        j = i;
    }
    output.insert(0, str.substr(0, j + 1));
    std::cout << "Minimum number of unrecognized sequence of characters: "
        << min_nums[str.length() - 1] << std::endl;
    std::cout << "Parsed output string is :" << output << std::endl;
    delete[] min_nums;
    delete[] parent;
}

int main() {
    std::set<std::string> set;
    set.insert("look");
    set.insert("looked");
    set.insert("just");
    set.insert("like");
    set.insert("her");
    set.insert("brother");
    ParseString("jesslookedjustliketimherbrother", set);

    set.clear();
    set.insert("kill");
    set.insert("ill");
    set.insert("look");
    set.insert("looked");
    ParseString("killooked", set);
    return 0;
}
