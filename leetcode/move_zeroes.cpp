//
// https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int N = nums.size();
        int next = 0;
        for (int i = 0; i < N; i++) {
            int x = nums[i];
            if (x == 0) {
                continue;
            }
            nums[next] = x;
            next++;
        }
        for (int i = next; i < N; i++) {
            nums[i] = 0;
        }
    }
};


int main() {
//    auto f = [](vector<int>&& nums, void expect) {
//        auto output = Solution().moveZeroes(nums);
//        leetcode_assert(output == expect, "move_zeroes nums={} expect={} output={}", nums, expect, output);
//    };
//    f();
}
