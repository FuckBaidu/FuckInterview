/**
 * 5.3 in <Crack the code interview>.
 * Given an integer,  print the next smallest and next largest number that
 * have the same number of 1 bits in their binary representation
 */
#include <stdio.h>
unsigned NextSmallest(unsigned num) {
    unsigned i = 0;
    bool found_zero = false;
    bool is_lsb_one = num & 1;
    for (; i < sizeof(unsigned) * 8; i++) {
        if (!(num & (1 << i)) && !found_zero)
            found_zero = true;
        else if ((num & (1 << i)) && found_zero)
            break;
    }
    if (found_zero && i != sizeof(unsigned) * 8)
        num = num & ~(1 << i) | (1 << (i - 1));
    if (is_lsb_one) {
        int j = 0;
        for (; j < i - 1; j++)
            if (!(num & (1 << j)))
                break;
        num |= (1 << i) - 1;
        num &= ~(1 << (i - 1 - j) - 1);
    }
    return num;
}
unsigned NextLargest(unsigned num) {
    unsigned i = 0;
    bool found_one = false;
    bool is_lsb_zero = !(num & 1);
    for (; i < sizeof(unsigned) * 8; i++) {
        if ((num & (1 << i)) && !found_one)
            found_one = true;
        else if (!(num & (1 << i)) && found_one)
            break;
    }
    if (found_one && i != sizeof(unsigned) * 8)
        num = num & ~(1 << (i - 1)) | (1 << i);
    if (is_lsb_zero) {
        int j = 0;
        for (; j < i - 1; j++)
            if ((num & (1 << j)))
                break;
        num &= ~(1 << (i - 1) - 1);
        num |= (1 << i - 1- j) - 1;
    }
    return num;
}

void Test(unsigned num) {
    printf("next smallest of %u is %u\n", num, NextSmallest(num));
    printf("next largest of %u is %u\n", num, NextLargest(num));
}
int main() {
    Test(3);
    Test(5);
    Test(9);
    Test(10);
    Test(12);
    Test(11);
    Test(19);
    return 0;
}
