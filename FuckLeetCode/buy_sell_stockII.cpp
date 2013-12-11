/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you  * like (ie, buy one and sell one share of the stock multiple times). However, you may not 
 * engage in multiple transactions at the same time (ie, you must sell the stock before you 
 * buy again).
 */
#include <vector>
#include <assert.h>
int MaxProfit(const std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int max_profit = 0, buy = 0, sell = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < prices[i - 1]) {
            max_profit += prices[sell] - prices[buy];
            buy = i;
        }
        sell = i;
    }
    max_profit += prices[sell] - prices[buy]; 
    return max_profit;
}

int main() {
    int a[] = {5, 10, 3, 6, 4, 15, 1, 2, 9};
    std::vector<int> input(a, a + sizeof(a) / sizeof(int));
    assert(MaxProfit(input) == 27);
    return 0;
}
