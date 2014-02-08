/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid
 * (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has
 * length = 4.
 */
#include <stack>
#include <string>
#include <assert.h>
int LongestValidParentheses(const std::string &s) {
    int max = 0, cur = 0;
    std::stack< std::pair<char, int> > stack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push(std::make_pair('(', i));
        } else if (s[i] == ')') {
            if (!stack.empty() && stack.top().first == '(') {
                stack.pop();
                if (stack.empty())
                    cur = i + 1;
                else
                    cur = i - stack.top().second;
                if (max < cur)
                    max = cur;
            } else {
                stack.push(std::make_pair(')', i));
            }
        }
    }
    return max;
}

int main() {
    assert(LongestValidParentheses("(()())") == 6);
    assert(LongestValidParentheses("()())") == 4);
    assert(LongestValidParentheses("(()()") == 4);
    assert(LongestValidParentheses("()(()") == 2);
    return 0;
}
