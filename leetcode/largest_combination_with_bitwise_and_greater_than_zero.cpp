//
// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/?envType=daily-question&envId=2024-11-07
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> digitOneCnt(32, 0);
        const int N = candidates.size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int x = candidates[i];
            for (int d = 0; d < 32; d++) {
                if ((x & (1 << d)) != 0) {
                    digitOneCnt[d]++;
                    ans = max(ans, digitOneCnt[d]);
                }
            }
        }
//        return *max_element(digitOneCnt.begin(), digitOneCnt.end());
        return ans;
    }
};

int main() {
    auto f = [](vector<int> &&candidates, int expect) {
        auto output = Solution().largestCombination(candidates);
        leetcode_assert(output == expect, "largest_combination_with_bitwise_and_greater_than_zero candidates={} expect={} output={}", candidates, expect, output);
    };
    f();
}
