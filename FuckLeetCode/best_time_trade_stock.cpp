/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to buy one share of the stock and sell one share of the stock, design
 * an algorithm to find the best times to buy and sell.
 */
#include <assert.h>
void FindBestBuyAndSellDay(int prices[], int num, int *buy, int *sell) {
    int max = 0, min = 0, profit = 0, max_profit = 0;
    *buy = 0, *sell = 0;
    for (int i = 0; i < num; i++) {
        if (prices[i] > prices[max]) {
            max = i;
            profit = prices[max] - prices[min];
            if (profit > max_profit) {
                *buy = min;
                *sell = max;
                max_profit = profit;
            }
        } else if (prices[i] < prices[min]) {
            min = i;
            max = i;
        }
    }
}

int main() {
    int buy = 0;
    int sell = 0;
    int test1[3] = {1, 3, 2};
    FindBestBuyAndSellDay(test1, sizeof(test1) / sizeof(int), &buy, &sell);
    assert(buy == 0);
    assert(sell == 1);
    int test2[5] = {5, 4, 3, 2, 1};
    FindBestBuyAndSellDay(test2, sizeof(test2) / sizeof(int), &buy, &sell);
    assert(buy == 0);
    assert(sell == 0);
    int test3[10] = {3, 9, 6, 2, 1, 7, 5, 3, 4, 8};
    FindBestBuyAndSellDay(test3, sizeof(test3) / sizeof(int), &buy, &sell);
    assert(buy == 4);
    assert(sell == 9);
    int test4[5] = {2, 8, 1, 4, 9};
    FindBestBuyAndSellDay(test4, sizeof(test4) / sizeof(int), &buy, &sell);
    assert(buy == 2);
    assert(sell == 4);
    return 0;
}
