//
// https://leetcode.com/problems/longest-increasing-subsequence/
//

#include "leetcode_utils.hpp"

using namespace std;

int lengthOfLIS(vector<int> &nums) {
    const int N = nums.size();
    if (N == 0) {
        return 0;
    }
    int res = 1;
    vector<int> dp(N, 0);
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        int max_prev = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                max_prev = max(max_prev, dp[j]);
            }
        }
        dp[i] = max_prev + 1;
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = lengthOfLIS(nums);
        leetcode_assert(output == expect, "longest_increasing_subsequence nums={} expect={} output={}", nums, expect,
                        output);
    };
    f({10, 9, 2, 5, 3, 7, 101, 18}, 4);
    f({0, 1, 0, 3, 2, 3}, 4);
    f({7, 7, 7, 7, 7, 7, 7}, 1);
}
