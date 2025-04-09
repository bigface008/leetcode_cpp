//
// https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/?envType=daily-question&envId=2025-04-09
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> num_set;
        for (int x : nums) {
            num_set.insert(x);
        }
        int min_val = *num_set.begin();
        if (min_val < k) {
            return -1;
        } else if (min_val == k) {
            return num_set.size() - 1;
        } else {
            return num_set.size();
        }
    }
};


int main() {
    auto f = [](vector<int>&& nums, int k, int expect) {
        auto output = Solution().minOperations(nums, k);
        leetcode_assert(output == expect, "minimum_operations_to_make_array_values_equal_to_k nums={} k={} expect={} output={}", nums, k, expect, output);
    };
    f();
}
