/**
 * 3.6 in <Crack the code interview>.
 * Sort a stack in ascending order
 */
#define private public
#include "util.h"

void Sort(ArrayStack<int> &stack) {
    ArrayStack<int> helper;
    while (!stack.empty()) {
        int cur = stack.pop();
        int count = 0;
        while (!helper.empty() && helper.peek() < cur) {
            count++;
            stack.push(helper.pop());
        }
        helper.push(cur);
        while (count--)
            helper.push(stack.pop());
    }

    while (!helper.empty())
        stack.push(helper.pop());
}

void Test() {
    printf("Before:\n");
    ArrayStack<int> stack;
    stack.push(2);
    stack.push(5);
    stack.push(3);
    stack.push(1);
    stack.push(4);
    stack.push(1);
    for (int i = 0; i<=stack._top; i++)
        printf("%d ", stack._array[i]);
    printf("\n");
    Sort(stack);
    printf("After:\n");
    for (int i = 0; i<=stack._top; i++)
        printf("%d ", stack._array[i]);
    printf("\n");
}

int main() {
    Test();
    return 0;
}
