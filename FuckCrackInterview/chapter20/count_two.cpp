/**
 * 20.4 in <Crack the code interview>.
 * Write a method to count the 2s between 0 and n
 */
#include <assert.h>
int CountTwos(int n) {
    int times = 1, cur = 0, count = 0;
    while (times <= n) {
        cur = n / times % 10;
        count += n / (10 * times) * times;
        if (cur > 2)
            count += times;
        else if (cur == 2)
            count += n % times + 1;
        times *= 10;
    }
    return count;
}

void Test(int n) {
    int count = 0;
    for (int i = 0; i <= n; i++) {
        int j = i;
        while (j) {
            if (j % 10 == 2)
                count++;
            j /= 10;
        }
    }

    assert(count == CountTwos(n));
}

int main() {
    Test(12);
    Test(1202);
    Test(125);
    return 0;
}
