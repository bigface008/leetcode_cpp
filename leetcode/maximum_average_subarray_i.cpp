//
// https://leetcode.cn/problems/maximum-average-subarray-i/description/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        const int N = nums.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < N; i++) {
            sum = sum + nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }
};


int main() {
    auto f = [](vector<int> &&nums, int k, double expect) {
        auto output = Solution().findMaxAverage(nums, k);
        leetcode_assert(output == expect, "maximum_average_subarray_i nums={} k={} expect={} output={}", nums, k,
                        expect, output);
    };
    f({1, 12, -5, -6, 50, 3}, 4, 12.75);
}
