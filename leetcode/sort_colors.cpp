//
// https://leetcode.com/problems/sort-colors/?envType=daily-question&envId=2025-05-17
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int N = nums.size();
        int cnt01 = 0, cnt0 = 0;
        for (int i = 0; i < N; i++) {
            int x = nums[i];
            if (x == 0) {
                swap(nums[cnt0], nums[i]);
                if (cnt0 < cnt01) {
                    swap(nums[cnt01], nums[i]);
                }
                cnt0++;
                cnt01++;
            } else if (x == 1) {
                swap(nums[cnt01], nums[i]);
                cnt01++;
            }
        }
    }
};


int main() {
    auto f = [](vector<int>&& nums, vector<int>&& expect) {
        Solution().sortColors(nums);
        leetcode_assert(nums == expect, "sort_colors nums={} expect={}", nums, expect);
    };
    f();
}
