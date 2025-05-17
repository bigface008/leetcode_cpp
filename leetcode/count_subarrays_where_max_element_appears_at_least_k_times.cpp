//
// https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2025-04-29
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        int max_cnt = 0;
        int left = 0;
        long long ans = 0;
        for (int right = 0; right < N; right++) {
            int rv = nums[right];
            if (rv == max_val) {
                max_cnt++;
            }
            while (max_cnt >= k) {
                int lv = nums[left];
                if (lv == max_val) {
                    max_cnt--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& nums, int k, long long expect) {
        auto output = Solution().countSubarrays(nums, k);
        leetcode_assert(output == expect, "count_subarrays_where_max_element_appears_at_least_k_times nums={} k={} expect={} output={}", nums, k, expect, output);
    };
    f();
}
