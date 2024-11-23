//
// https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        int dp = nums[0];
        int ans = nums[0];
        for (int i = 1; i < N; i++) {
            if (dp >= 0) {
                dp += nums[i];
            } else {
                dp = nums[i];
            }
            ans = max(ans, dp);
        }
        return ans;
    }
};

// 这是一道比较典型的题，有多种DP解法

// 这种方法把dp[i]定义为以i结尾的数组中和的最大值。所以你需要额外一个整型值来记录全局最大值。
// 注：nums[i]可以为负数，所以dp[i]确实可能会小于nums[i]+dp[i-1]，但是注意定义！dp[i]是
// 必须以i结尾！所以这个状态转移方程是没问题的！
int maxSubArrayV0(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        if (dp[i - 1] >= 0) {
            dp[i] = nums[i] + dp[i - 1];
        } else {
            dp[i] = nums[i];
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// 这种标准解法就是上面这个DP方法的简化版。注意，DP里，如果dp[i]只依赖于dp[i-1]，那就可以不
// 需要dp数组，用一个变量来代替。
int maxSubArray(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int current_max = nums[0];
    int global_max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        current_max = max(nums[i], current_max + nums[i]);
        global_max = max(global_max, current_max);
    }
    return global_max;
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = maxSubArray(nums);
        leetcode_assert(output == expect, "maximum_subarray nums={} expect={} output={}", nums, expect, output);
    };
    f({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
    f({1}, 1);
    f({5, 4, -1, 7, 8}, 23);
}
