//
// https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/?envType=daily-question&envId=2025-04-28
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int N = nums.size();
        long long ans = 0;
        int left = 0;
        long long curr_sum = 0;
        long long curr_cnt = 0;
        for (int right = 0; right < N; right++) {
            int rv = nums[right];
            curr_sum += rv;
            curr_cnt++;
            while (curr_sum * curr_cnt >= k) {
                int lv = nums[left];
                curr_sum -= lv;
                curr_cnt--;
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& nums, long long k, long long expect) {
        auto output = Solution().countSubarrays(nums, k);
        leetcode_assert(output == expect, "count_subarrays_with_score_less_than_k nums={} k={} expect={} output={}", nums, k, expect, output);
    };
    f();
}
