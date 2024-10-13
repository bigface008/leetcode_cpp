//
// https://leetcode.com/problems/interleaving-string/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int M, N;
    string s1;
    string s2;
    string s3;
    vector<vector<int>> memo;

    bool dfs(int i, int j) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (i == 0 && j == 0) {
            memo[i][j] = true;
            return true;
        }
        if (i == 0) {
            int res = s3[j - 1] == s2[j - 1] && dfs(0, j - 1);
            memo[i][j] = res;
            return res;
        }
        if (j == 0) {
            int res = s3[i - 1] == s1[i - 1] && dfs(i - 1, 0);
            memo[i][j] = res;
            return res;
        }
        if (s3[i + j - 1] == s1[i - 1] && dfs(i - 1, j)) {
            memo[i][j] = true;
            return true;
        }
        if (s3[i + j - 1] == s2[j - 1] && dfs(i, j - 1)) {
            memo[i][j] = true;
            return true;
        }
        memo[i][j] = false;
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        M = s1.size();
        N = s2.size();
        if (M + N != s3.size()) {
            return false;
        }
        this->memo = vector<vector<int>>(M + 1, vector<int>(N + 1, -1));
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        return dfs(M, N);
    }
};


bool isInterleave2(string s1, string s2, string s3) {
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
