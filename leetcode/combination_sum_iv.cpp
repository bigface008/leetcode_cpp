//
// https://leetcode.com/problems/combination-sum-iv/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return dfs(target, nums);
    }

private:
    unordered_map<int, int> memo;

    int dfs(int target, vector<int>& nums) {
        if (target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        if (memo.contains(target)) {
            return memo[target];
        }
        int ans = 0;
        for (int x : nums) {
            if (x <= target) {
                ans += dfs(target - x, nums);
            }
        }
        memo[target] = ans;
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& nums, int target, int expect) {
        auto output = Solution().combinationSum4(nums, target);
        leetcode_assert(output == expect, "combination_sum_iv nums={} target={} expect={} output={}", nums, target, expect, output);
    };
    f();
}
