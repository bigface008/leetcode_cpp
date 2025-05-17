//
// https://leetcode.cn/problems/find-numbers-with-even-number-of-digits/?envType=daily-question&envId=2025-04-30
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int cnt = 0;
            while (x > 0) {
                x /= 10;
                cnt++;
            }
            if (cnt % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& nums, int expect) {
        auto output = Solution().findNumbers(nums);
        leetcode_assert(output == expect, "find_numbers_with_even_number_of_digits nums={} expect={} output={}", nums, expect, output);
    };
    f();
}
