//
// https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
        return 0;
    }
    const int M = obstacleGrid.size(), N = obstacleGrid[0].size();
    vector<vector<int>> dp(M, vector<int>(N, 0));
    dp[0][0] = obstacleGrid[0][0] == 0;
    for (int i = 1; i < N; i++) {
        if (obstacleGrid[0][i] == 1) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i < M; i++) {
        if (obstacleGrid[i][0] == 1) {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                int cnt1 = dp[i - 1][j];
                int cnt2 = dp[i][j - 1];
                dp[i][j] = cnt1 + cnt2;
            }
        }
    }
    return dp[M - 1][N - 1];
}

int main() {
    auto f = [](vector<vector<int>> &&obstacleGrid, int expect) {
        auto output = uniquePathsWithObstacles(obstacleGrid);
        leetcode_assert(output == expect, "unique_paths_ii obstacleGrid={} expect={} output={}", obstacleGrid, expect,
                        output);
    };
    f({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2);
    f({{0, 1}, {0, 0}}, 1);
}
