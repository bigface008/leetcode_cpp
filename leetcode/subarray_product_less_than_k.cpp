//
// https://leetcode.cn/problems/subarray-product-less-than-k/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        const int N = nums.size();
        int left = 0, right = 0;
        int prod = 1;
        int ans = 0;
        for (; right < N; right++) {
            int x = nums[right];
            prod *= x;
            while (prod >= k && left <= right) {
                prod /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int> &&nums, int k, int expect) {
        auto output = Solution().numSubarrayProductLessThanK(nums, k);
        leetcode_assert(output == expect, "subarray_product_less_than_k nums={} k={} expect={} output={}", nums, k,
                        expect, output);
    };
    f({10, 5, 2, 6}, 100, 8);
}
