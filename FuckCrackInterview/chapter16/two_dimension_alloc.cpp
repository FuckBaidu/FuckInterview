/**
 * 16.10 in <Crack the code interview>.
 * Implement a function to allocates a two dimensional array.Minimize the number
 * of calls of malloc.Make sure that memory is accessible by the notation arr[i][j]
 */
#include <stdlib.h>
template <class T>
void *AllocTwoDimessionalArray(int row, int col) {
    if (row <= 0 || col <= 0)
        return NULL;
    T *buf = (T*)malloc(row * sizeof(T*) + row * col * sizeof(T));
    T **rows = (T**)buf;
    for (int i = 0; i < row; i++) {
        rows[i] = (T*)((char*)buf + row * sizeof(T*) + i * col * sizeof(T));
    }
    return buf;
}

int main() {
    return 0;
}
