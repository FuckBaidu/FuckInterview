/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the
 * input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]"
 * are not.
 */
#include <string>
#include <assert.h>
#include <stack>
bool IsValid(const std::string &s) {
    std::stack<char> stack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push(s[i]);
        } else {
            if (stack.empty())
                return false;
            if (s[i] == ')' && stack.top() != '(')
                return false;
            else if (s[i] == ']' && stack.top() != '[')
                return false;
            else if (s[i] == '}' && stack.top() != '{')
                return false;   
            stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    assert(!IsValid("([)]"));
    assert(IsValid("([{}]{})"));
    return 0;
}
