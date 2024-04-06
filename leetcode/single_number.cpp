//
// Created by 汪喆昊 on 2024/4/5.
// https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int singleNumber(vector<int> &nums) {
    if (nums.empty()) {
        return -1;
    }
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        int output = singleNumber(nums);
        leetcode_assert(output == expect, "single number nums={} expect={} output={}", nums, expect, output);
    };
    f({2, 2, 1}, 1);
    f({4, 1, 2, 1, 2}, 4);
    f({1}, 1);
}
