/**
 * Problem 1:
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 * Problem 2:
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 * Problem 3:
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include <vector>
int MaxProfit1(std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int max = 0, buy = 0, sell = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < prices[buy])
            buy = i;
        if (max < prices[i] - prices[buy])
            max = prices[i] - prices[buy];
    }
    return max;
}

int MaxProfit2(std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int max = 0, buy = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < prices[i - 1]) {
            max += prices[i - 1] - prices[buy];
            buy = i;
        }
    }
    max += prices.back() - prices[buy];
    return max;
}

int MaxProfit3(std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int max = 0, max_left = 0, buy = 0, sell = prices.size() - 1;
    std::vector<int> max_right(prices.size(), 0);
    for (int i = (int)prices.size() - 1; i >= 0; i--) {
        if (prices[i] > prices[sell])
            sell = i;
        max_right[i] = prices[sell] - prices[i];
    }
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < prices[buy])
            buy = i;
        if (max_left < prices[i] - prices[buy])
            max_left = prices[i] - prices[buy];
        if (max < max_left + max_right[i])
            max = max_left + max_right[i];
    }
    return max;
}

int main() {
    int a[10] = {3, 9, 6, 2, 1, 7, 5, 3, 4, 8};
    std::vector<int> test(a, a + 10);
    assert(MaxProfit1(test) == 7);
    assert(MaxProfit2(test) == 17);
    assert(MaxProfit3(test) == 13);
    return 0;
}
