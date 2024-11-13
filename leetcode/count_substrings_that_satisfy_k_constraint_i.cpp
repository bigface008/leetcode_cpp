//
// https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/description/?envType=daily-question&envId=2024-11-12
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        const int N = s.size();
        int zeroCnt = 0, oneCnt = 0;
        int ans = 0;
        int left = 0;
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
            ans += i - left + 1;
        }
        return ans;
    }
};

class Solution2 {
public:
    int countKConstraintSubstrings(string s, int k) {
        const int N = s.size();
        vector<int> preSum(N + 1, 0);
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '1') {
                sum++;
            }
            preSum[i + 1] = sum;
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                int len = j - i + 1;
                int oneCnt = preSum[j + 1] - preSum[i];
                int zeroCnt = len - oneCnt;
                if (zeroCnt <= k || oneCnt <= k) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    auto f = [](string &&s, int k, int expect) {
        auto output = Solution().countKConstraintSubstrings(s, k);
        leetcode_assert(output == expect, "count_substrings_that_satisfy_k_constraint_i s={} k={} expect={} output={}", s, k, expect, output);
    };
    f("10101", 1, 12);
}
