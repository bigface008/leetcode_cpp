//
// https://leetcode.cn/problems/sum-of-subarray-minimums/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        const int N = arr.size();
        vector<int> prefix(N, -1);
        vector<int> suffix(N, N);
        stack<int> stk;
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                suffix[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) {
                prefix[i] = stk.top();
            }
            stk.push(i);
        }

//        vector<int> ids(N, 0);
//        iota(ids.begin(), ids.end(), 0);
//        sort(ids.begin(), ids.end());

        long long ans = 0;
        for (int i = 0; i < N; i++) {
            int x = arr[i];
//            int cnt = (i - prefix[i]) * (suffix[i] - i);
            int prev_idx = prefix[i];
            int prev_cnt = 1;
            if (prev_idx == -1) {
                prev_cnt = i + 1;
            } else {
                prev_cnt = i - prefix[i];
            }
            int post_idx = suffix[i];
            int post_cnt = 1;
            if (post_idx == N) {
                post_cnt = N - i;
            } else {
                if (arr[suffix[i]] == x) {
                    post_cnt = suffix[i] - i;
                } else {
                    post_cnt = suffix[i] - i;
                }
            }
            long long cnt = prev_cnt * post_cnt;
            fmt::println("i={} x={} cnt={} prefix[i]={} suffix[i]={} prev_cnt={} post_cnt={}", i, x, cnt, prefix[i], suffix[i], prev_cnt, post_cnt);
            ans += (long long) x * cnt;
        }
        return ans % MOD;
    }

private:
    const int MOD = 1e9 + 7;
};


int main() {
    auto f = [](vector<int> &&arr, int expect) {
        auto output = Solution().sumSubarrayMins(arr);
        leetcode_assert(output == expect, "sum_of_subarray_minimums arr={} expect={} output={}", arr, expect, output);
    };
    f({3, 1, 2, 4}, 17);
}
