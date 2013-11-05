/**
 * 16.9 in <Crack the code interview>.
 * Write a aligned malloc and free funtions that takes number of bytes 
 * and aligned bytes(which is always power of 2)
 */
#include <stdlib.h>
void *aligned_malloc(size_t required_bytes, size_t alignment) {
    if (required_bytes == 0 || alignment == 0)
        return NULL;
    int offset = sizeof(void*) + alignment - 1;
    void *p1 = malloc(required_bytes + offset);
    if (!p1)
        return NULL;
    void **p2 = (void**)(((size_t)p1 + offset) & ~(alignment - 1));
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *ptr) {
    free(((void**)ptr)[-1]);
}

int main() {
    return 0;
}
