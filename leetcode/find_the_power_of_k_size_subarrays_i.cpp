//
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/?envType=daily-question&envId=2024-11-16
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int> &nums, int k) {
        const int N = nums.size();
        dp.resize(N);
        fill(dp.begin(), dp.end(), -1);
        vector<int> ans(N - k + 1, 0);
        for (int i = k - 1; i < N; i++) {
            if (dfs(nums, i) >= k) {
                ans[i - k + 1] = nums[i];
            } else {
                ans[i - k + 1] = -1;
            }
        }
        return ans;
    }

private:
    vector<int> dp;

    int dfs(vector<int> &nums, int idx) {
        if (idx == 0) {
            return 1;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int ans = 0;
        if (nums[idx] == nums[idx - 1] + 1) {
            ans = 1 + dfs(nums, idx - 1);
        } else {
            ans = 1;
        }
        dp[idx] = ans;
        return ans;
    }
};

class Solution2 {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int N = nums.size();
//        bool valid = true;
//        for (int i = 1; i < k; i++) {
//            if (nums[i - 1] + 1 != nums[i]) {
//                valid = false;
//                break;
//            }
//        }
//        vector<int> ans(N - k + 1, 0);
//        ans[0] = valid ? nums[k - 1] : -1;
//        for (int i = k; i < N; i++) {
//            int curr = nums[i];
//            int prev = nums[i - k];
//            if (curr != nums[i - 1] + 1) {
//                ans[i - k + 1] = -1;
//            }
//        }
//        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& nums, int k, vector<int> expect) {
        auto output = Solution().resultsArray(nums, k);
        leetcode_assert(output == expect, "find_the_power_of_k_size_subarrays_i nums={} k={} expect={} output={}", nums, k, expect, output);
    };
    f();
}
