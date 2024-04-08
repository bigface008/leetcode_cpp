//
// https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int kadane(vector<int> &nums) {
    int current_max = nums[0];
    int global_max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        current_max = max(nums[i], current_max + nums[i]);
        global_max = max(global_max, current_max);
    }
    return global_max;
}

int maxSubarraySumCircular(vector<int> &nums) {
    int current_max = 0, current_min = 0, total = 0;
    int global_max = INT_MIN, global_min = INT_MAX;
    for (int n : nums) {
        current_max = max(n, current_max + n);
        current_min = min(n, current_min + n);
        global_max = max(current_max, global_max);
        global_min = min(current_min, global_min);
        total += n;
    }
    return global_max >= 0 ? max(global_max, total - global_min) : global_max;
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = maxSubarraySumCircular(nums);
        leetcode_assert(output == expect, "maximum_sum_circular_subarray nums={} expect={} output={}", nums, expect,
                        output);
    };
    f({1, -2, 3, -2}, 3);
    f({5, -3, 5}, 10);
    f({-3, -2, -3}, -2);
}
