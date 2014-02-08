/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
#include <stack>
#include <assert.h>
int Trap(int A[], int n) {
    int sum = 0;
    std::stack< std::pair<int, int> > stack;
    for (int i = 0; i < n; i++) {
        std::pair<int, int> cur(i, A[i]);
        while (!stack.empty() && A[i] > stack.top().second) {
            std::pair<int, int> top = stack.top();
            stack.pop();
            if (!stack.empty())
                sum += (i - stack.top().first - 1) * (std::min(A[i], stack.top().second) - top.second);
        }
        stack.push(cur);
    }
    return sum;
}

int main() {
    int a[] = {0,1,0,5,1,0,1,3,2,1,2,1};
    assert(Trap(a, 12) == 9);
    return 0;
}
