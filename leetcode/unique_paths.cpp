//
// https://leetcode.com/problems/unique-paths/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    auto f = [](int m, int n, int expect) {
        auto output = uniquePaths(m, n);
        leetcode_assert(output == expect, "unique_paths m={} n={} expect={} output={}", m, n, expect, output);
    };
    f(3, 7, 28);
    f(3, 2, 3);
}
