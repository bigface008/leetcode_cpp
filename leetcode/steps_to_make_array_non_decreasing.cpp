//
// https://leetcode.cn/problems/steps-to-make-array-non-decreasing/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int totalSteps(vector<int> &nums) {
        int N = nums.size();
        vector<int> temp(N, 0);
        vector<bool> isDeleted(N, false);

        int ans = 0;
        while (true) {
            for (int i = 0; i < N - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    isDeleted[i + 1] = true;
                }
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = Solution().totalSteps(nums);
        leetcode_assert(output == expect, "steps_to_make_array_non_decreasing nums={} expect={} output={}", nums,
                        expect, output);
    };
    f({10, 6, 5, 10, 15}, 1);
    //    f({10, 1, 2, 3, 4, 5, 6, 1, 2, 3}, 0);
}
