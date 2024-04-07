//
// https://leetcode.com/problems/maximal-square/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    const int M = matrix.size(), N = matrix[0].size();
    vector<vector<int>> dp(M, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        dp[0][i] = matrix[0][i] == '1';
    }
    for (int i = 0; i < M; i++) {
        dp[i][0] = matrix[i][0] == '1';
    }
    int len = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                len = max(len, dp[i][j]);
            }
        }
    }
    return len * len;
}

int main() {
    auto f = [](vector<vector<char>> &&matrix, int expect) {
        auto output = maximalSquare(matrix);
        leetcode_assert(output == expect, "maximal_square matrix={} expect={} output={}", matrix, expect, output);
    };
    f({{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}}, 4);
    f({{'0', '1'}, {'1', '0'}}, 1);
    f({{'0'}}, 0);
}
