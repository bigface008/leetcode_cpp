//
// https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int sum_at_i = 0;
        for (int num : nums) {
            sum_at_i += (num >> i) & 1;
        }
        sum_at_i %= 3;
        ans |= (sum_at_i << i);
    }
    return ans;
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = singleNumber(nums);
        leetcode_assert(output == expect, "single_number_ii nums={} expect={} output={}", nums, expect, output);
    };
    f({2, 2, 3, 2}, 3);
    f({0, 1, 0, 1, 0, 1, 99}, 99);
}
