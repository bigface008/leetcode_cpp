//
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int longestSubarray(vector<int> &nums) {
    int start = 0, end = 0, cnt = 0, max_cnt = 0;
    bool can_delete_zero = true;
    for (; start < nums.size(); start++) {
        for (; end < nums.size(); end++) {
            if (nums[end] == 1) {
                cnt++;
            } else if (can_delete_zero) {
                can_delete_zero = false;
            } else {
                break;
            }
        }
        if (can_delete_zero) {
            cnt--; // must delete one element.
        }
        max_cnt = max(max_cnt, cnt);
        if (nums[start] == 0) {
            can_delete_zero = true;
        } else {
            cnt--;
        }
    }
    return max_cnt;
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = longestSubarray(nums);
        leetcode_assert(output == expect,
                        "longest_subarray_of_1s_after_deleting_one_element nums={} expect={} output={}", nums, expect,
                        output);
    };
    f({1, 1, 0, 1}, 3);
    f({0, 1, 1, 1, 0, 1, 1, 0, 1}, 5);
    f({1, 1, 1}, 2);
}
