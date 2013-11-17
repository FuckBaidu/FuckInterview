/**
 * 20.2 in <Crack the code interview>.
 * Write a method to shuffle a deck of cards, it must be a perfect shuffle
 * - in other words, each 52! permutation of the deck has to be equally likely.
 * Assume that you have a random number generator which is perfect
 */
#include <vector>
#include <iostream>
#include <stdlib.h>

void Shuffle(std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++)
        std::swap(vec[i], vec[rand() % (vec.size() - i) + i]);
}

void Test(std::vector<int> &vec) {
    std::cout << "Input: ";
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = i;
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    Shuffle(vec);
    std::cout << "output: ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> a(10, 0);
    Test(a);
    return 0;
}
