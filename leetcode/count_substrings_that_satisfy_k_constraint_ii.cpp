//
// https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii/?envType=daily-question&envId=2024-11-13
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        const int N = s.size(), M = queries.size();
        int left = 0;
        int oneCnt = 0, zeroCnt = 0;
        vector<int> memo(N);
        vector<long long> preSum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            if (s[i] == '1') {
                oneCnt++;
            } else {
                zeroCnt++;
            }
            while (oneCnt > k && zeroCnt > k) {
                if (s[left] == '1') {
                    oneCnt--;
                } else {
                    zeroCnt--;
                }
                left++;
            }
            memo[i] = left;
            preSum[i + 1] = preSum[i] + i - left + 1;
        }
        vector<long long> ans(M);
        for (int i = 0; i < M; i++) {
            int l = queries[i][0], r = queries[i][1];

            // Find last idx makes memo[idx] <= l, or first idx makes memo[idx] > l
            int idx = lower_bound(memo.begin() + l, memo.begin() + r + 1, l) - memo.begin();
            ans[i] = preSum[r + 1] - preSum[idx] + (long long) (idx - l + 1) * (idx - l) / 2;
        }
        return ans;
    }
};

int main() {
    auto f = [](string &&s, int k, vector<vector<int>> &&queries, vector<long long> &&expect) {
        auto output = Solution().countKConstraintSubstrings(s, k, queries);
        leetcode_assert(output == expect, "count_substrings_that_satisfy_k_constraint_ii s={} k={} queries={} expect={} output={}", s, k, queries, expect, output);
    };
    f();
}
