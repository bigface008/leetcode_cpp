//
// https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maximumCount(vector<int> &nums) {
        const int N = nums.size();
        int start = 0, end = N - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= 0) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        int pos1 = start;
        end = N - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > 0) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return max(pos1, N - start);
    }
};


int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = Solution().maximumCount(nums);
        leetcode_assert(output == expect,
                        "maximum_count_of_positive_integer_and_negative_integer nums={} expect={} output={}", nums,
                        expect, output);
    };
    f({-2, -1, -1, 1, 2, 3}, 3);
}
