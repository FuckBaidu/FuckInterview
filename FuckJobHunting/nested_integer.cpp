/*
 * Given a nested list of integers, returns the sum of all integers in the list weighted by their
 * depth
 *
 * For example, given the list {{1,1},2,{1,1}} the function should return 10 (four 1's at depth 2,
 * one *2 at depth 1)
 *
 * Given the list {1,{4,{6}}} the function should return 27 (one 1 at depth 1, one 4 at depth 2, and
 * *one 6 at depth 3)
 */
#include <string>
#include <assert.h>
int SumNestedInteger(const std::string &s) {
    int sum = 0, depth = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            depth++;
        } else if (s[i] == '}') {
            depth--;
        } else if (isdigit(s[i])) {
            sum += (s[i] - '0') * depth;
        }
    }
    return sum;
}

int main() {
    assert(SumNestedInteger("{{1,1},2,{1,1}}") == 10);
    assert(SumNestedInteger("{1,{4,{6}}}") == 27);
    return 0;
}
