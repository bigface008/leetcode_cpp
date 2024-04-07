//
// https://leetcode.com/problems/find-peak-element/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

bool valid(vector<int> &nums, int index) {
    if (index == 0) {
        if (nums.size() == 1) {
            return true;
        } else {
            return nums[0] > nums[1];
        }
    } else if (index == nums.size() - 1) {
        if (nums.size() == 1) {
            return true;
        } else {
            return nums[index] > nums[index - 1];
        }
    } else {
        return nums[index] > nums[index - 1] && nums[index] > nums[index + 1];
    }
}

int helper(vector<int> &nums, int index) {
    if (index < 0 || index >= nums.size()) {
        return -1;
    }
    int val = nums[index];
    bool prev_greater = false;
    bool next_greater = false;
    if (index == 0) {
        prev_greater = true;
    } else if (val > nums[index - 1]) {
        prev_greater = true;
    }
    if (index == nums.size() - 1) {
        next_greater = true;
    } else if (val > nums[index + 1]) {
        next_greater = true;
    }
    if (prev_greater && next_greater) {
        return index;
    }
    if (prev_greater && !next_greater) {
        int res_next = helper(nums, index + 1);
        if (res_next != -1) {
            return res_next;
        }
        int res_prev = helper(nums, index - 1);
        if (res_prev != -1) {
            return res_prev;
        }
    } else {
        int res_prev = helper(nums, index - 1);
        if (res_prev != -1) {
            return res_prev;
        }
        int res_next = helper(nums, index + 1);
        if (res_next != -1) {
            return res_next;
        }
    }
    return -1;
}

int findPeakElement(vector<int> &nums) {
    if (nums.empty()) {
        return -1;
    }
    return helper(nums, (nums.size() - 1) / 2);
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = findPeakElement(nums);
        leetcode_assert(output == expect, "find_peak_element nums={} expect={} output={}", nums, expect, output);
    };
    f({1, 2, 3, 1}, 2);
    f({1, 2, 1, 3, 5, 6, 4}, 5);
}
