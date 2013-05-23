/**
 * From section 2.2 of <<The beauty of Coding >>
 * Given a number of N, count how many zeros at the end of N!(factorial)
 * eg: N = 10, N! = 3628800, there are two zeros at the end
 */
#include <assert.h>
#include <sys/time.h>
#include <stdio.h>
int CountTailZerosOfFactorial1(int num) {
    if (num < 5)
        return 0;
    int count = 0;
    for (int i = 1; i <= num /5; i++) {
        int j = i * 5;
        while (j % 5 == 0) {
            count++;
            j /= 5;
        }
    }
    return count;
}

int CountTailZerosOfFactorial2(int num) {
    if (num == 0)
        return 0;
    int count = 0;
    while (num) {
        num /= 5;
        count += num;
    }
    return count;
}

int main() {
    timeval start, end;
    gettimeofday(&start, NULL);
    assert(CountTailZerosOfFactorial1(0) == 0);
    assert(CountTailZerosOfFactorial1(3) == 0);
    assert(CountTailZerosOfFactorial1(10) == 2);
    assert(CountTailZerosOfFactorial1(100) == 24);
    gettimeofday(&end, NULL);
    printf("%llus,%lluus\n", end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    assert(CountTailZerosOfFactorial2(0) == 0);
    assert(CountTailZerosOfFactorial2(3) == 0);
    assert(CountTailZerosOfFactorial2(10) == 2);
    assert(CountTailZerosOfFactorial2(100) == 24);
    gettimeofday(&end, NULL);
    printf("%llus,%lluus\n", end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
    return 0;
}
