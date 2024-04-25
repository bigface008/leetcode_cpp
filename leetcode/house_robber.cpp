//
// https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int rob(vector<int>& nums) {
    const int N = nums.size();
    if (N < 3) {
        return *max_element(nums.begin(), nums.end());
    }
    vector<int> dp(N, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[0] + nums[2];
    for (int i = 3; i < N; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = rob(nums);
        leetcode_assert(output == expect, "house_robber nums={} expect={} output={}", nums, expect, output);
    };
    f({1,2,3,1}, 4);
    f({2,7,9,3,1}, 12);
}
