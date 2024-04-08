//
// https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int maxSubArray(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int current_max = nums[0];
    int global_max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        current_max = max(nums[i], current_max + nums[i]);
        global_max = max(global_max, current_max);
    }
    return global_max;
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = maxSubArray(nums);
        leetcode_assert(output == expect, "maximum_subarray nums={} expect={} output={}", nums, expect, output);
    };
    f({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
    f({1}, 1);
    f({5, 4, -1, 7, 8}, 23);
}
