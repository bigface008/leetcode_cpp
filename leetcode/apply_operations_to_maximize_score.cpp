//
// https://leetcode.com/problems/apply-operations-to-maximize-score/?envType=daily-question&envId=2025-03-29
//

#include "leetcode_utils.hpp"

using namespace std;

const int MX = 1e5 + 1;
int omega[MX];
int init = []() {
    for (int i = 2; i < MX; i++) {
        if (omega[i] == 0) {
            for (int j = i; j < MX; j += i) {
                omega[j]++;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int N = nums.size();
        vector<int> left(N, -1);
        vector<int> right(N, N);
        stack<int> stk;
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && omega[nums[stk.top()]] < omega[nums[i]]) {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        vector<int> ids(N, 0);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](const int a, const int b) {
            return nums[a] > nums[b];
        });
        long long ans = 1;
        for (int i : ids) {
            long long total = (long long) (i - left[i]) * (right[i] - i);
            if (total >= k) {
                ans = ans * pow(nums[i], k) % MOD;
                break;
            }
            ans = ans * pow(nums[i], total) % MOD;
            k -= total;
        }
        return ans;
    }

private:
    const int MOD = 1e9 + 7;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }
};


int main() {
    auto f = [](vector<int> &&nums, int k, int expect) {
        auto output = Solution().maximumScore(nums, k);
        leetcode_assert(output == expect, "apply_operations_to_maximize_score nums={} k={} expect={} output={}", nums,
                        k, expect, output);
    };
    f();
}
