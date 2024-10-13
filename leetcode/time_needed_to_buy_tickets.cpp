//
// https://leetcode.com/problems/time-needed-to-buy-tickets
//

#include "leetcode_utils.hpp"
#include <fmt/core.h>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int N = tickets.size();
        int ans = 0;
        list<int> line;
        for (int i = 0; i < N; i++) {
            line.push_back(i);
        }
        return ans;
    }
};

int main() {
    fmt::println("just we");
//    auto f = [](vector<int> &&tickets, int k, int expect) {
//        auto output = Solution().timeRequiredToBuy(tickets, k);
//        leetcode_assert(output == expect, "time_needed_to_buy_tickets tickets={} k={} expect={} output={}", tickets, k,
//                        expect, output);
//    };
//    f();
};
