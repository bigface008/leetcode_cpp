//
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int maxProfit(int k, vector<int> &prices) {
    vector<int> buy(k, INT_MIN);
    vector<int> sell(k, 0);
    for (int price : prices) {
        for (int i = 0; i < k; i++) {
            if (i == 0) {
                buy[i] = max(buy[i], -price);
            } else {
                buy[i] = max(buy[i], sell[i - 1] - price);
            }
            sell[i] = max(sell[i], buy[i] + price);
        }
    }
    return sell.back();
}

int main() {
    auto f = [](int k, vector<int> &&prices, int expect) {
        auto output = maxProfit(k, prices);
        leetcode_assert(output == expect, "best_time_to_buy_and_sell_stock_iv expect={} output={}", expect, output);
    };
    f(2, {2, 4, 1}, 2);
    f(2, {3, 2, 6, 5, 0, 3}, 7);
}
