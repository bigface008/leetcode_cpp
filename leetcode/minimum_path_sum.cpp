//
// https://leetcode.com/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }
    const int M = grid.size(), N = grid[0].size();
    vector<vector<int>> dp(M, vector<int>(N, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < N; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < M; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            int v1 = dp[i][j - 1];
            int v2 = dp[i - 1][j];
            dp[i][j] = grid[i][j] + min(v1, v2);
        }
    }
    return dp[M - 1][N - 1];
}

int main() {
    auto f = [](vector<vector<int>> &&grid, int expect) {
        auto output = minPathSum(grid);
        leetcode_assert(output == expect, "minimum_path_sum grid={} expect={} output={}", grid, expect, output);
    };
    f({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7);
    f({{1, 2, 3}, {4, 5, 6}}, 12);
}
