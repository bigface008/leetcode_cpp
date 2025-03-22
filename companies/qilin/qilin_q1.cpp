//
// Created by 汪喆昊 on 2025/3/21.
//

#include "leetcode_utils.hpp"

using namespace std;

// https://leetcode.cn/problems/boolean-evaluation-lcci?envType=company&envId=70capital&favoriteSlug=70capital-more-than-six-months
class Solution {
public:
    int countEval(string s, int result) {
        int i = 0;
        const int N = s.size();
        while (i < N) {
            int val = 0;
            while (i < N && isalnum(s[i])) {
                val = val * 10 + s[i] - '0';
                i++;
            }
            values.push_back(val);
            if (i < N) {
                ops.push_back(s[i]);
            }
            i++;
        }

        const int M = values.size();
        vector<vector<vector<int>>> dp(M, vector<vector<int>>(M, vector<int>(2, 0)));
        for (int start = M - 1; start >= 0; start--) {
            for (int end = start; end < M; end++) {
                for (int res = 0; res <= 1; res++) {
                    if (start == end) {
                        dp[start][end][res] = values[start] == res ? 1 : 0;
                        continue;
                    }
                    int ans = 0;
                    for (int opIdx = start; opIdx < end; opIdx++) {
                        char op = ops[opIdx];
                        if (op == '|') {
                            if (res == 0) {
                                ans += dp[start][opIdx][0] * dp[opIdx + 1][end][0];
                            } else {
                                ans += dp[start][opIdx][1] * dp[opIdx + 1][end][0] +
                                    + dp[start][opIdx][0] * dp[opIdx + 1][end][1] +
                                    + dp[start][opIdx][1] * dp[opIdx + 1][end][1];
                            }
                        } else if (op == '&') {
                            if (res == 0) {
                                ans += dp[start][opIdx][1] * dp[opIdx + 1][end][0] +
                                    + dp[start][opIdx][0] * dp[opIdx + 1][end][1] +
                                    + dp[start][opIdx][0] * dp[opIdx + 1][end][0];
                            } else {
                                ans += dp[start][opIdx][1] * dp[opIdx + 1][end][1];
                            }
                        } else {
                            if (res == 0) {
                                ans += dp[start][opIdx][0] * dp[opIdx + 1][end][0] +
                                    + dp[start][opIdx][1] * dp[opIdx + 1][end][1];
                            } else {
                                ans += dp[start][opIdx][1] * dp[opIdx + 1][end][0] +
                                    + dp[start][opIdx][0] * dp[opIdx + 1][end][1];
                            }
                        }
                    }
                    dp[start][end][res] = ans;
                }
            }
        }
        return dp[0][M - 1][result];
    }

private:
    vector<int> values;
    vector<char> ops;
};

void check(string s, int result, int expect) {
    int output = Solution().countEval(s, result);
    leetcode_assert(output == expect, "s={} result={} output={} expect={}", s, result, output, expect);
}

int main() {
//    check("0", 0, 1);
    check("1", 1, 1);
//    check("1&0", 1, 0);
//    check("0^1^1|0^1^0|0&1^0|1^1&1|1", 0, 0);
}