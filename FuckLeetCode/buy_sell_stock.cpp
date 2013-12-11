/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of
 * the stock), design an algorithm to find the maximum profit.
 */
#include <vector>
#include <assert.h>
int MaxProfit(const std::vector<int> &prices) {
    int max_profit = 0, buy = 0, sell = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[sell]) {
            sell = i;
            if (max_profit < prices[sell] - prices[buy])
                max_profit = prices[sell] - prices[buy];
        } else if (prices[i] < prices[buy]) {
            buy = sell = i;
        }
    }
    return max_profit;
}

int main() {
    int a[] = {5, 10, 3, 6, 4, 15, 1, 9, 2};
    std::vector<int> input(a, a + sizeof(a) / sizeof(int));
    assert(MaxProfit(input) == 12);
    return 0;
}
