/**
 * 8.7 in <Crack the code interview>.
 * Give an infinite number of quarters(25cents), dimes(10 cents), nickels(5 cents)
 * and pennies(1 cent).Write code to calculate the number of ways of representing n cents
 */
#include <iostream>
#include <vector>
#include <set>
#define NUM 4
enum Money{
    Quarter = 25,
    Dime = 10,
    Nickel = 5,
    Penny = 1,
};

void BestRepresentNCents(int n) {
    std::vector<Money> result;
    while (n) {
        Money cur;
        if (n >= (int)Quarter)
            cur = Quarter;
        else if (n >= (int)Dime)
            cur = Dime;
        else if (n >= (int)Nickel)
            cur = Nickel;
        else if (n >= (int)Penny)
            cur = Penny;
        result.push_back(cur);
        n -= (int)cur;
    }
    int counts[(int)NUM];
        memset(counts, 0, sizeof(counts));
    for (int i = 0; i < result.size(); i++) {
        int index = 0;
        switch ((Money)result[i]) {
            case Quarter:
                index = 0;
                break;
            case Dime:
                index = 1;
                break;
            case Nickel:
                index = 2;
                break;
            case Penny:
                index = 3;
                break;
        }
        counts[index]++;
    }
    std::cout << counts[0] << " quarters," << counts[1] << " dimes," << counts[2]
        << " nickels," << counts[3] << " pennies" << std::endl;
}

void MakeChanges(int n, int *counts, Money cur_change) {
    if (cur_change == Penny) {
        counts[3] = n;
        std::cout << counts[0] << " quarters," << counts[1] << " dimes," << counts[2]
            << " nickels," << counts[3] << " pennies" << std::endl;
    } else {
        int index = 0;
        Money next_change;
        switch (cur_change) {
        case Quarter:
            index = 0;
            next_change = Dime;
            break;
        case Dime:
            index = 1;
            next_change = Nickel;
            break;
        case Nickel:
            index = 3;
            next_change = Penny;
            break;
        }
        for (int i = 0; (int)cur_change * i <= n; i++) {
            counts[index] = i;
            MakeChanges(n - (int)cur_change * i, counts, next_change);
        }
    }
}

void MakeChanges(int n) {
    int counts[NUM];
    memset(counts, 0, sizeof(counts));
    MakeChanges(n, counts, Quarter);
}

int main() {
    MakeChanges(34);
    BestRepresentNCents(34);
    return 0;
}
