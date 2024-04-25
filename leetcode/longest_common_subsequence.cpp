//
// https://leetcode.com/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

void backtrack(int &ans, int i, int curr_len, int j_min, const string &s1, const string &s2,
               map<char, vector<int>> &s2mp, vector<bool> &visited) {
    const int M = s1.size(), N = s2.size();
    if (i >= M) {
        return;
    }
    char c = s1[i];
    auto &vec = s2mp[c];
    if (vec.empty()) {
        backtrack(ans, i + 1, curr_len, j_min, s1, s2, s2mp, visited);
        return;
    }
    for (int pos : vec) {
        if (pos >= j_min) {
            visited[i] = true;
            ans = max(ans, curr_len + 1);
            backtrack(ans, i + 1, curr_len + 1, pos + 1, s1, s2, s2mp, visited);
            visited[i] = false;
        }
    }
}

int longestCommonSubsequence_v2(string text1, string text2) {
    const int M = text1.size(), N = text2.size();
    if (M == 0 || N == 0) {
        return 0;
    }
    if (M > N) {
        return longestCommonSubsequence_v2(text2, text1);
    }

    map<char, vector<int>> txt2mp;
    for (int i = 0; i < N; i++) {
        txt2mp[text2[i]].push_back(i);
    }
    vector<bool> visited(M, false);
    int ans = 0;
    backtrack(ans, 0, 0, 0, text1, text2, txt2mp, visited);
    return ans;
}

// map<char, vector<int>> txt2mp;
// for (int i = 0; i < N; i++) {
//     txt2mp[text2[i]].push_back(i);
// }
//
// vector<vector<int>> dp(M, vector<int>(N, 0));
// auto &vec_1st = txt2mp[text1[0]];
// if (vec_1st.empty()) {
//     return 0;
// }
// int ans = 0;
// for (int i = 0; i < N; i++) {
//     if (vec_1st[0] > i) {
//         dp[0][i] = 0;
//     } else {
//         dp[0][i] = 1;
//         ans = 1;
//     }
// }
// bool used = false;
// for (int i = 0; i < M; i++) {
//     if (used) {
//         dp[i][0] = 1;
//     } else {
//         if (text1[i] == text2[0]) {
//             used = true;
//             dp[i][0] = 1;
//             ans = 1;
//         }
//     }
// }

int longestCommonSubsequence(string text1, string text2) {
    const int M = text1.size(), N = text2.size();
    if (M == 0 || N == 0) {
        return 0;
    }
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[M][N];
}

int main() {
    auto f = [](string &&text1, string &&text2, int expect) {
        auto output = longestCommonSubsequence(text1, text2);
        leetcode_assert(output == expect, "longest_common_subsequence text1={} text2={} expect={} output={}", text1,
                        text2, expect, output);
    };
    f("abcde", "ace", 3);
    f("abc", "abc", 3);
    f("abc", "def", 0);
    f("psnw", "vozsh", 1);
    f("oxcpqrsvwf", "shmtulqrypy", 2);
}
