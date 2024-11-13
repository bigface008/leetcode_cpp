//
// https://leetcode.com/problems/maximum-xor-for-each-query/description/?envType=daily-question&envId=2024-11-08
//

#include "leetcode_utils.hpp"

using namespace std;

// 1 1 0
// 0 0 0
// 1 0 1
// 0 1 1

class Solution {
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        const int N = nums.size();
        int mask = (1 << maximumBit) - 1;
        vector<int> ans(N, 0);
        int cur = 0;
        for (int i = 0; i < N; i++) {
            cur ^= nums[i];
            ans[N - 1 - i] = ~cur & mask;
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        const int N = nums.size();
        vector<int> ans(N, 0);
        vector<int> preXor(N + 1, 0);
        int xorVal = 0;
        for (int i = 0; i < N; i++) {
            int x = nums[i];
            xorVal ^= x;
            preXor[i + 1] = xorVal;
        }
        for (int q = 0; q < N; q++) {
            int val = preXor[N - q] ^ preXor[0];
            int res = 0;
            for (int d = 0; d < maximumBit; d++) {
                if ((val & (1 << d)) == 0) {
                    res += 1 << d;
                }
            }
            ans[q] = res;
        }
        return ans;
    }
};

int main() {
    auto f = [](vector<int> &&nums, int maximumBit, vector<int> &&expect) {
        auto output = Solution().getMaximumXor(nums, maximumBit);
        leetcode_assert(output == expect, "maximum_xor_for_each_query nums={} maximumBit={} expect={} output={}", nums,
                        maximumBit, expect, output);
    };
    f({0, 1, 1, 3}, 2, {0, 3, 2, 3});
}
