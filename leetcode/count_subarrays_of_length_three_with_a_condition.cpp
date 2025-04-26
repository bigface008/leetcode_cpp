//
// https://leetcode.cn/problems/count-subarrays-of-length-three-with-a-condition/?envType=daily-question&envId=2025-04-27
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        const int N = nums.size();
        int ans = 0;
        for (int i = 0; i + 2 < N; i++) {
            int sum = nums[i] + nums[i + 2];
            int b = nums[i + 1];
            if (sum * 2 == b) {
                ans++;
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& nums, int expect) {
        auto output = Solution().countSubarrays(nums);
        leetcode_assert(output == expect, "count_subarrays_of_length_three_with_a_condition nums={} expect={} output={}", nums, expect, output);
    };
    f();
}
