/**
 * 8.7 in <Crack the code interview>.
 * Give an infinite number of quarters(25cents), dimes(10 cents), nickels(5 cents)
 * and pennies(1 cent).Write code to calculate the number of ways of representing n cents
 */
#include <iostream>
#include <vector>
enum Money{
    Quarter = 25,
    Dime = 10,
    Nickel = 5,
    Penny = 1,
};
#define NUM 4

void RepresentNCents(int n, std::vector<Money> &result) {
    if (n == 0) {
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
    } else {
        for (int i = 0; i < (int)NUM; i++) {
            Money cur;
            switch (i) {
            case 0:
                cur = Quarter;
                break;
            case 1:
                cur = Dime;
                break;
            case 2:
                cur = Nickel;
                break;
            case 3:
                cur = Penny;
                break;
            }
            if (n >= cur) {
                std::vector<Money> tmp = result;
                tmp.push_back(cur);
                RepresentNCents(n - (int)cur, tmp);
            }
        }
    }
}

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

int main() {
    std::vector<Money> result;
    RepresentNCents(34, result);
    BestRepresentNCents(34);
    return 0;
}
