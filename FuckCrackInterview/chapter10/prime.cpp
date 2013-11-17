#include <iostream>
#include <vector>
#include <map>
#include <math.h>

void ListAllPrime(int n, std::vector<int> &result) {
    if (n <= 10) {
        int a[] = {2, 3, 5, 7};
        for (int i = 0; i < 4 && a[i] <= n ; i++)
            result.push_back(a[i]);
    } else {
        int cur = (int)sqrt(n);
        ListAllPrime(cur, result);
        for (int i = cur + 1; i <= n; i++) {
            bool is_prime = true;
            for (int j = 0; j < result.size(); j++) {
                if (i % result[j] == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime)
                result.push_back(i);
        }
    }
}

#define TEST_BIT(bitmap, n) ((bitmap)[(n) / sizeof(unsigned)] & (1 << (n) % sizeof(unsigned)))
#define SET_BIT(bitmap, n) ((bitmap)[(n) / sizeof(unsigned)] |= (1 << (n) % sizeof(unsigned)))

void ListAllPrime1(int n, std::vector<int> &result) {
    unsigned *bitmap = new unsigned[(n + sizeof(n) - 1) / sizeof(n) + 1];
    memset(bitmap, 0, ((n + sizeof(n) - 1) / sizeof(n) + 1) * sizeof(unsigned));
    int i = 2;
    while (i <= (int)sqrt(n)) {
        for (int j = i + i; j <= n; j += i)
            SET_BIT(bitmap, j);
        i++;
        while (TEST_BIT(bitmap, i))
            i++;
    }
    for (i = 2; i <= n; i++)
        if (!TEST_BIT(bitmap, i))
            result.push_back(i);

    delete []bitmap;
}

void Factorize(int n, std::map<int, int> &result) {
    std::vector<int> factor_table;
    ListAllPrime1(n, factor_table);
    while (n > 1) {
        for (int i = 0; i < factor_table.size(); i++) {
            while (n % factor_table[i] == 0) {
                n /= factor_table[i];
                if (result.count(factor_table[i]))
                    result[factor_table[i]]++;
                else
                    result[factor_table[i]] = 1;
            }
        }
    }
}

void Test(int n) {
    std::vector<int> result;
    ListAllPrime(n, result);
    std::cout << "The primes less than " << n << std::endl;
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;

    result.clear();
    ListAllPrime1(n, result);
    std::cout << "The primes less than " << n << std::endl;
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;

    std::map<int, int> factor;
    Factorize(n, factor);
    std::map<int, int>::const_iterator iter = factor.begin();
    std::cout << "Factorise " << n << std::endl;
    while (iter != factor.end()) {
        std::map<int, int>::const_iterator tmp = iter;
        tmp++;
        for (int i = 0; i < iter->second; i++) {
            std::cout << iter->first;
            if (i != iter->second - 1 || tmp != factor.end())
                std::cout << "*";
        }
        iter++;
    }
    std::cout << std::endl;
}

int main() {
    Test(10);
    Test(120);
    return 0;
}
