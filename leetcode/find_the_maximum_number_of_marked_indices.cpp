//
// https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int N = nums.size();
        int i = 0, j = (N + 1) / 2;
        while (j < N) {
            if (nums[i] * 2 <= nums[j]) {
                i++;
            }
            j++;
        }
        return i * 2;
    }
};

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = Solution().maxNumOfMarkedIndices(nums);
        leetcode_assert(output == expect, "find_the_maximum_number_of_marked_indices nums={} expect={} output={}", nums,
                        expect, output);
    };
    f({3, 5, 2, 4}, 2);
}
