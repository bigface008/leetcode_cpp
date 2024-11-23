//
// https://leetcode.cn/problems/minimum-size-subarray-sum/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        const int N = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        bool found = false;
        int ans = N;
        for (; right < N; right++) {
            int x = nums[right];
            sum += x;
            while (sum >= target && left <= right) {
                ans = min(ans, right - left + 1);
                found = true;
                sum -= nums[left];
                left++;
            }
        }
        return found ? ans : 0;
    }
};


int main() {
    auto f = [](int target, vector<int> &&nums, int expect) {
        auto output = Solution().minSubArrayLen(target, nums);
        leetcode_assert(output == expect, "minimum_size_subarray_sum target={} nums={} expect={} output={}", target,
                        nums, expect, output);
    };
    f(11, {1, 2, 3, 4, 5}, 3);
}
