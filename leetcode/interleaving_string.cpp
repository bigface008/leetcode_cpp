//
// https://leetcode.com/problems/interleaving-string/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    const int M = s1.size(), N = s2.size();
    if (M + N != s3.size()) {
        return false;
    }
    vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        dp[0][i] = dp[0][i - 1] && (s3[i - 1] == s2[i - 1]);
    }
    for (int i = 1; i <= M; i++) {
        dp[i][0] = dp[i - 1][0] && (s3[i - 1] == s1[i - 1]);
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            bool v1 = dp[i - 1][j];
            bool v2 = dp[i][j - 1];
            if (v1 && s3[i + j - 1] == s1[i - 1]) {
                dp[i][j] = true;
            }
            if (v2 && s3[i + j - 1] == s2[j - 1]) {
                dp[i][j] = true;
            }
        }
    }
    return dp[M][N];
}

int main() {
    auto f = [](string &&s1, string &&s2, string &&s3, bool expect) {
        auto output = isInterleave(s1, s2, s3);
        leetcode_assert(output == expect, "interleaving_string s1={} s2={} s3={} expect={} output={}", s1, s2, s3, expect, output);
    };
    f("aabcc", "dbbca", "aadbbcbcac", true);
    f("aabcc", "dbbca", "aadbbbaccc", false);
    f("", "", "", true);
}
