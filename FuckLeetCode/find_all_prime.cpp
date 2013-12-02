/**
 * Output all primes numbers up to a specified integer n
 * http://leetcode.com/2010/04/finding-prime-numbers.html
 */
#include <math.h>
#include <vector>
#include <iostream>

void FindAllPrimes(int n) {
    bool *is_prime = new bool[n + 1];
    for (int i = 0; i <= n; i++)
        is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= (int)sqrt(n); i++) {
        int cur = i;
        if (!is_prime[cur])
            continue;
        while (cur <= n) {
            cur = cur + i;
            is_prime[cur] = false;
        }
    }
    std::cout << "All primes under " << n << " is: "<< std::endl;
    for (int i = 0; i <= n; i++)
        if (is_prime[i])
            std::cout << i << " ";
    std::cout << std::endl;
    delete[] is_prime;
}

int main() {
    FindAllPrimes(50);
    FindAllPrimes(121);
    return 0;
}
