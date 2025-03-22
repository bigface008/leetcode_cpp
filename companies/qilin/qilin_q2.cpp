//
// Created by 汪喆昊 on 2025/3/21.
//

#include "leetcode_utils.hpp"

using namespace std;

// https://leetcode.cn/problems/steps-to-make-array-non-decreasing/?envType=company&envId=70capital&favoriteSlug=70capital-more-than-six-months
class Solution {
public:
    int totalSteps(vector<int> &nums) {
        stack<pair<int, int>> stk;
        int ans = 0;
        for (int x : nums) {
            int cnt = 0;
            while (!stk.empty() && stk.top().first <= x) {
                cnt = max(cnt, stk.top().second);
                stk.pop();
            }
            cnt = stk.empty() ? 0 : (cnt + 1);
            ans = max(ans, cnt);
            stk.emplace(x, cnt);
        }
        return ans;
    }
};

//class Solution {
//public:
//    int totalSteps(vector<int> &nums) {
//        stack<int> stk;
//        const int N = nums.size();
//        int ans = 0;
//        for (int i = N - 1; i >= 0; i--) {
//            int x = nums[i];
//            while (!stk.empty() && nums[stk.top()] < x) {
//                stk.pop();
//            }
//            if (stk.empty()) {
//                ans = max(ans, N - 1 - i);
//            } else {
//                ans = max(ans, stk.top() - i - 1);
//            }
//            stk.push(i);
//        }
//        return ans;
//    }
//};

void check(vector<int> &&nums, int expect) {
    int output = Solution().totalSteps(nums);
    leetcode_assert(output == expect, "nums={} output={} expect={}", nums, output, expect);
}

// 7,   14,   4,   14,   13,   2,   6,   13
//      2:4        4:13  5:2
//                 6:6
//                 7:13


// 7  14  14 6 13
// 7  14  14 13
// 7  14  14

int main() {
//        check({5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11}, 3);
    check({7, 14, 4, 14, 13, 2, 6, 13}, 3);
};
