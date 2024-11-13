//
// https://leetcode.com/problems/maximum-total-reward-using-operations-ii/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int> &rewardValues) {
        const int N = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());

        bitset<100000> f{1};
        for (int x : rewardValues) {
            int shift = f.size() - x;
            f |= f << shift >> (shift - x);
        }
        for (int i = rewardValues.back() * 2 - 1; ; i--) {
            if (f.test(i)) {
                return i;
            }
        }
    }
};

//class Solution {
//public:
//    int maxTotalReward(vector<int> &rewardValues) {
//        const int N = rewardValues.size();
//        sort(rewardValues.begin(), rewardValues.end());
//        vector<vector<int>> dp(N + 1, vector<int>(4000));
//        for (int i = N - 1; i >= 0; i--) {
//            for (int j = 3999; j >= 0; j--) {
//                int x = rewardValues[i];
//                dp[i][j] = dp[i + 1][j];
//                if (x > j) {
//                    dp[i][j] = max(dp[i][j], dp[i + 1][j + x] + x);
//                }
//            }
//        }
//        return dp[0][0];
//    }
//};

int main() {
    auto f = [](vector<int> &&rewardValues, int expect) {
        auto output = Solution().maxTotalReward(rewardValues);
        leetcode_assert(output == expect,
                        "maximum_total_reward_using_operations_ii rewardValues={} expect={} output={}", rewardValues,
                        expect, output);
    };
    f({1, 1, 3, 3}, 4);
    f({1, 50000});
}
