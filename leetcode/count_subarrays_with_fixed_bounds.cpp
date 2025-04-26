//
// https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/?envType=daily-question&envId=2025-04-26
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int N = nums.size();
        long long ans = 0;
        int min_i = -1, max_i = -1, exclude_i = -1;
        for (int i = 0; i < N; i++) {
            int x = nums[i];
            if (x == minK) {
                min_i = i;
            }
            if (x == maxK) {
                max_i = i;
            }
            if (x < minK || x > maxK) {
                exclude_i = i;
            }
            ans += max(min(max_i, min_i) - exclude_i, 0);
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& nums, int minK, int maxK, long long expect) {
        auto output = Solution().countSubarrays(nums, minK, maxK);
        leetcode_assert(output == expect, "count_subarrays_with_fixed_bounds nums={} minK={} maxK={} expect={} output={}", nums, minK, maxK, expect, output);
    };
    f();
}
