//
// https://leetcode.cn/problems/count-of-interesting-subarrays/?envType=daily-question&envId=2025-04-25
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
        const int N = nums.size();
        vector<int> pre_sum(N + 1);
        for (int i = 0; i < N; i++) {
            pre_sum[i + 1] = pre_sum[i] + (nums[i] % modulo == k);
        }
        vector<int> cnt(min(N + 1, modulo));
        long long ans = 0;
        for (int s : pre_sum) {
            if (s >= k) {
                ans += cnt[(s - k) % modulo];
            }
            cnt[s % modulo]++;
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int> &&nums, int modulo, int k, long long expect) {
        auto output = Solution().countInterestingSubarrays(nums, modulo, k);
        leetcode_assert(output == expect, "count_of_interesting_subarrays nums={} modulo={} k={} expect={} output={}",
                        nums, modulo, k, expect, output);
    };
    f({3, 1, 9, 6}, 3, 0, 2);
}
