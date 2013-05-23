/**
 * From section 2.2 of <<The beauty of Coding >>
 * Given a number of N, find the lowest one of N!(factorial) in binary representation
 * eg: N = 3, N! = 0x6, the last one is at position 1
 */
#include <assert.h>
#include <sys/time.h>
#include <stdio.h>
int FindLastOne1(int num) {
    if (num == 0)
        return -1;
    int pos = 0;
    for (int i = 1; i <= (num >> 1); i++) {
        int j = i * 2;
        while (j % 2 == 0) {
            pos++;
            j >>= 1;
        }
    }
    return pos;
}

int FindLastOne2(int num) {
    if (num == 0)
        return -1;
    int pos = 0;
    while (num) {
        num >>= 1;
        pos += num;
    }
    return pos;
}

int main() {
    timeval start, end;
    gettimeofday(&start, NULL);
    assert(FindLastOne1(0) == -1);
    assert(FindLastOne1(3) == 1);
    assert(FindLastOne1(10) == 8);
    assert(FindLastOne1(100) == 97);
    gettimeofday(&end, NULL);
    printf("%llus,%lluus\n", end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    assert(FindLastOne2(0) == -1);
    assert(FindLastOne2(3) == 1);
    assert(FindLastOne2(10) == 8);
    assert(FindLastOne2(100) == 97);
    gettimeofday(&end, NULL);
    printf("%llus,%lluus\n", end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
    return 0;
}
