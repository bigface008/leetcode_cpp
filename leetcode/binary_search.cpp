//
// https://leetcode.cn/problems/binary-search/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();
        int start = 0, end = N - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int x = nums[mid];
            if (x == target) {
                return mid;
            } else if (x > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};


int main() {
    auto f = [](vector<int>&& nums, int target, int expect) {
        auto output = Solution().search(nums, target);
        leetcode_assert(output == expect, "binary_search nums={} target={} expect={} output={}", nums, target, expect, output);
    };
    f();
}
