/**
 * 19.4 in <Crack the code interview>.
 * Implement a function to find maximum of two numbers.You should not use if-else
 * clause and any other compare operator
 */
#include <assert.h>
int max(int a, int b) {
    int c = a - b;
    int k = (c >> 31) & 0x1;
    return a - k *c;
}

int main() {
    int result = max(5, 10);
    assert(result == 10);
    result = max(5, 5);
    assert(result == 5);
    return 0;
}
