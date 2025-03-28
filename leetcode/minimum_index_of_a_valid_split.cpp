//
// https://leetcode.com/problems/minimum-index-of-a-valid-split/?envType=daily-question&envId=2025-03-27
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int N = nums.size();
        unordered_map<int, int> cntMap;
        int dominant = -1;
        for (int x : nums) {
            cntMap[x]++;
            if (cntMap[x] > cntMap[dominant]) {
                dominant = x;
            }
        }
        int maxCnt = cntMap[dominant];
        vector<int> pre(N + 1, 0);
        for (int i = 0; i < N; i++) {
            pre[i + 1] = pre[i] + (nums[i] == dominant ? 1 : 0);
        }
        for (int i = 0; i < N; i++) {
            int prevCnt = pre[i + 1] - pre[0];
            int postCnt = maxCnt - prevCnt;
            if (prevCnt > (i + 1) / 2 && postCnt > (N - i - 1) / 2) {
                return i;
            }
        }
        return -1;
    }
};


int main() {
    auto f = [](vector<int>&& nums, int expect) {
        auto output = Solution().minimumIndex(nums);
        leetcode_assert(output == expect, "minimum_index_of_a_valid_split nums={} expect={} output={}", nums, expect, output);
    };
    f();
}
