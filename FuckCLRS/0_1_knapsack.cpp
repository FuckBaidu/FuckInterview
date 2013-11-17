/*
 * Given a knapsack with maximum capacity W, and a set S consisting of n items
 * Each item i has some weight wi and benefit value bi  (all wi and W are integer values)
 * Problem: How to pack the knapsack to achieve maximum total value of packed items?
 */
#include <iostream>
#include <vector>

struct Item {
    int weight;
    int benefit;
    Item (int _weight, int _benefit) : weight(_weight), benefit(_benefit) { }
};

void GetMaxinumBenefit(int weight, std::vector<Item> &items) {
    int **max_benefits = new int*[items.size() + 1];
    for (int i = 0; i < items.size() + 1; i++) {
        max_benefits[i] = new int[weight + 1];
        max_benefits[i][0] = 0;
    }
    memset(max_benefits[0], 0, sizeof(int) * (weight + 1));
    for (int i = 1; i <= items.size(); i++) {
        for (int w = 1; w <= weight; w++) {
            if (items[i - 1].weight <= w)
                max_benefits[i][w] = std::max(max_benefits[i - 1][w],
                                max_benefits[i - 1][w - items[i - 1].weight] + items[i - 1].benefit);
            else
                max_benefits[i][w] = max_benefits[i - 1][w];
        }
    }
    std::cout << "Max benefit is  " << max_benefits[items.size()][weight] << std::endl;
    std::cout << "We picked items: ";
    int cur_weight = weight;
    for (int i = items.size(); i >= 1; i--) {
        if (max_benefits[i][cur_weight] != max_benefits[i - 1][cur_weight]) {
            std::cout << i - 1 << " ";
            cur_weight = cur_weight - items[i - 1].weight;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < items.size() + 1; i++)
        delete[] max_benefits[i];
    delete[] max_benefits;
}

int main() {
    std::vector<Item> items;
    items.push_back(Item(2, 3));
    items.push_back(Item(4, 5));
    items.push_back(Item(5, 8));
    items.push_back(Item(3, 4));
    items.push_back(Item(9, 10));
    int weight = 20;
    GetMaxinumBenefit(weight, items);
    return 0;
}
