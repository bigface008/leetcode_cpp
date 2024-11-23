//
// https://leetcode.cn/problems/k-concatenation-maximum-sum/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int N = arr.size();
        const long LIMIT = (long) N * (long) k;
        const long MOD = 1000000007L;
        long dp = arr[0];
        long ans = max(arr[0], 0);
        long singelSum = arr[0];
        for (long i = 1; i < min(k, 2) * N; i++) {
            if (dp >= 0) {
                dp += arr[i % N];
            } else {
                dp = arr[i % N];
            }
            ans = max(ans, dp);
            if (i < N) {
                singelSum += arr[i];
            }
        }
        if (singelSum > 0 && k > 2) {
            ans += ((k - 2) * singelSum) % MOD;
        }
        ans %= MOD;
        return (int) ans;
    }
};


int main() {
    auto f = [](vector<int>&& arr, int k, int expect) {
        auto output = Solution().kConcatenationMaxSum(arr, k);
        leetcode_assert(output == expect, "k_concatenation_maximum_sum arr={} k={} expect={} output={}", arr, k, expect, output);
    };
    f();
}
