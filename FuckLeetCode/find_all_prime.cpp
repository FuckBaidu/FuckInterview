/**
 * Output all primes numbers up to a specified integer n
 * http://leetcode.com/2010/04/finding-prime-numbers.html
 */
#include <math.h>
#include <vector>
#include <iostream>

void FindAllPrimes(int n) {
    assert(n >= 1);
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (!is_prime[i])
            continue;
        for (int j = 2 * i; j <= n; j += i)
            is_prime[j] = false;
    }
    std::cout << "All primes under " << n << " is: "<< std::endl;
    for (int i = 0; i <= n; i++)
        if (is_prime[i])
            std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    FindAllPrimes(50);
    FindAllPrimes(121);
    return 0;
}
