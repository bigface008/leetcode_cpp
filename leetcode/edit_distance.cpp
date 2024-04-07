//
// https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int minDistance(string word1, string word2) {
    const int M = word1.size(), N = word2.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= M; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    return dp[M][N];
}

int main() {
    auto f = [](string &&word1, string &&word2, int expect) {
        auto output = minDistance(word1, word2);
        leetcode_assert(output == expect, "edit_distance word1={} word2={} expect={} output={}", word1, word2, expect, output);
    };
    f("horse", "ros", 3);
    f("intention", "execution", 5);
}
