/**
 * From section 2.2 of <The Beauty of Coding>. To testify if a number is power of two?
 */
#include <assert.h>
bool IsPowerOfTwo(int num) {
    if (num <= 0)
        return false;
    else
        return (num & (num - 1)) == 0;
}

int main() {
    assert(!IsPowerOfTwo(-1));
    assert(!IsPowerOfTwo(0));
    assert(!IsPowerOfTwo(11));
    assert(IsPowerOfTwo(16));
    assert(IsPowerOfTwo(1));
    return 0;
}
