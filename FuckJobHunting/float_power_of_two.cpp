/*
 * check if a float is a power of 2
 */
#include <assert.h>

bool IsPowerOfTwo(float f) {
    int *i = (int *)&f;
    int s = *i >> 31;
    int e = (*i >> 23) & 0xff;
    int m = *i & 0x7fffff;
    return !s && e && !m;
}

int main() {
    assert(IsPowerOfTwo(2));
    assert(IsPowerOfTwo(0.5));
    assert(!IsPowerOfTwo(0.3));
    assert(!IsPowerOfTwo(0));
    return 0;
}
