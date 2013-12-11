/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include <vector>
#include <assert.h>
//1-D Dynamic Programming
int MaxProfit(const std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    // ith element reprensent the maximum profit we can get when buying the stock on day i.
    std::vector<int> max_second_profits;
    max_second_profits.resize(prices.size());
    int max = prices.back();
    for (int i = prices.size() - 1; i >= 0; i--) {
        if (max < prices[i])
            max = prices[i];
        max_second_profits[i] = max - prices[i];
    }
    int max_first_profit = 0, max_profit = 0, buy = 0, sell = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < prices[buy]) {
            buy = i;
        }
        sell = i;
        if (max_first_profit < prices[sell] - prices[buy])
            max_first_profit = prices[sell] - prices[buy];
        if (max_profit < max_first_profit + max_second_profits[i])
            max_profit = max_first_profit + max_second_profits[i];
    }
    return max_profit;
}

int main() {
    int a[] = {5, 10, 3, 6, 4, 15, 1, 2, 9};
    std::vector<int> input(a, a + sizeof(a) / sizeof(int));
    assert(MaxProfit(input) == 27);
    return 0;
}
