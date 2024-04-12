//
// https://leetcode.com/problems/max-consecutive-ones-iii/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int longestOnes(vector<int> &nums, int k) {
    int start = 0, end = 0, max_cnt = 0, cnt = 0, curr_k = k;
    for (; start < nums.size(); start++) {
        for (; end < nums.size(); end++) {
            if (nums[end] == 1) {
                cnt++;
            } else if (curr_k == 0) {
                break;
            } else {
                curr_k--;
                cnt++;
            }
        }
        max_cnt = max(cnt, max_cnt);
        cnt--;
        if (nums[start] == 0) {
            curr_k++;
        }
    }
    return max_cnt;
}

int main() {
    auto f = [](vector<int> &&nums, int k, int expect) {
        auto output = longestOnes(nums, k);
        leetcode_assert(output == expect, "max_consecutive_ones_iii nums={} k={} expect={} output={}", nums, k, expect,
                        output);
    };
    f({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6);
    f({0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10);
}
