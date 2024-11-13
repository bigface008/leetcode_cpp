//
// https://leetcode.cn/problems/single-element-in-a-sorted-array/description/?envType=daily-question&envId=2024-11-10
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int N = nums.size();
        int start = 0, end = N - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            int x = nums[mid];
            bool isPrevSame = (mid >= 1) ? (nums[mid - 1] == x) : false;
            bool isNextSame = (mid <= N - 2) ? (nums[mid + 1] == x) : false;
            if (!isPrevSame && !isNextSame) {
                return x;
            }
            if (isPrevSame) {
                int prevCnt = mid - 1;
                if (prevCnt % 2 == 0) {
                    start = mid + 1;
                } else {
                    end = mid - 2;
                }
            } else {
                int prevCnt = mid;
                if (prevCnt % 2 == 0) {
                    start = mid + 2;
                } else {
                    end = mid - 1;
                }
            }
        }
        return nums[start];
    }
};

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = Solution().singleNonDuplicate(nums);
        leetcode_assert(output == expect, "single_element_in_a_sorted_array nums={} expect={} output={}", nums, expect, output);
    };
    f();
}
