//
// https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

bool increasingTriplet(vector<int> &nums) {
    if (nums.size() < 3) {
        return false;
    }
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int n : nums) {
        if (n <= min1) {
            min1 = n;
        } else if (n <= min2) {
            min2 = n;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    auto f = [](vector<int> &&nums, bool expect) {
        auto output = increasingTriplet(nums);
        leetcode_assert(output == expect, "increasing_triplet_subsequence nums={} expect={} output={}", nums, expect,
                        output);
    };
    f({1, 2, 3, 4, 5}, true);
    f({5, 4, 3, 2, 1}, false);
    f({2, 1, 5, 0, 4, 6}, true);
}
