//
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int maxProfit(vector<int> &prices) {
    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;
    for (int price : prices) {
        buy1 = max(buy1, -price);
        sell1 = max(sell1, buy1 + price);
        buy2 = max(buy2, sell1 - price);
        sell2 = max(sell2, buy2 + price);
    }
    return sell2;
}

int maxProfit_v2(vector<int> &prices) {
//    const int N = prices.size();
//    if (N == 0) {
//        return 0;
//    }
//    vector<int> cash(N, 0);
//    vector<int> hold(N, 0);
//    for (int price : prices) {
//        buy1 = max(buy1, -price);
//        sell1 = max(sell1, buy1 + price);
//        buy2 = max(buy2, sell1 - price);
//        sell2 = max(sell2, buy2 + price);
//    }
//    return sell2;
    return 0;
}

int main() {
    auto f = [](vector<int> &&prices, int expect) {
        auto output = maxProfit_v2(prices);
        leetcode_assert(output == expect, "best_time_to_buy_and_sell_stock_iii prices={} expect={} output={}", prices,
                        expect, output);
    };
    f({3, 3, 5, 0, 0, 3, 1, 4}, 6);
    f({1, 2, 3, 4, 5}, 4);
    f({7, 6, 4, 3, 1}, 0);
}
