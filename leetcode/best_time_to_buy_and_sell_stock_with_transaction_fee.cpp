//
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int maxProfit(vector<int> &prices, int fee) {
    const int N = prices.size();
    if (N == 0) {
        return 0;
    }
    vector<vector<int>> dp(N + 1, vector<int>(2, 0));
    for (int i = N - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            if (buy) {
                profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            } else {
                profit = max(prices[i] + dp[i + 1][1] - fee, dp[i + 1][0]);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int maxProfit_v2(vector<int> &prices, int fee) {
    const int N = prices.size();
    if (N == 0) {
        return 0;
    }
    vector<int> cash(N, 0);
    vector<int> hold(N, 0);
    cash[0] = 0;
    hold[0] = -prices[0];
    int ans = 0;
    for (int i = 1; i < N; i++) {
        cash[i] = max(cash[i - 1], hold[i - 1] + prices[i] - fee);
        hold[i] = max(hold[i - 1], cash[i - 1] - prices[i]);
        ans = max({ans, cash[i], hold[i]});
    }
    return ans;
}

int main() {
    auto f = [](vector<int> &&prices, int fee, int expect) {
        auto output = maxProfit_v2(prices, fee);
        leetcode_assert(output == expect,
                        "best_time_to_buy_and_sell_stock_with_transaction_fee prices={} fee={} expect={} output={}",
                        prices, fee, expect, output);
    };
    f({1, 3, 2, 8, 4, 9}, 2, 8);
    f({1, 3, 7, 5, 10, 3}, 3, 6);
}
