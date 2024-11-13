//
// https://leetcode.com/problems/count-square-submatrices-with-all-ones
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int ans = 0;
        for (int i = 0; i < M; i++) {
            dp[i][0] = matrix[i][0] == 1;
            ans += dp[i][0];
        }
        for (int j = 1; j < N; j++) {
            dp[0][j] = matrix[0][j] == 1;
            ans += dp[0][j];
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][j] == 1) {
                    int cnt1 = dp[i - 1][j - 1];
                    int cnt2 = dp[i][j - 1];
                    int cnt3 = dp[i - 1][j];
                    dp[i][j] = min({cnt1, cnt2, cnt3}) + 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> preSum(M + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                preSum[i + 1][j + 1] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i][j] + matrix[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 1) {
                    int r = i, c = j;
                    while (r < M && c < N) {
                        int edgeLen = r - i + 1;
                        int full = edgeLen * edgeLen;
                        int real = preSum[r + 1][c + 1] - preSum[i][c + 1] - preSum[r + 1][j] + preSum[i][j];
                        if (real == full) {
                            ans++;
                        } else {
                            break;
                        }
                        r++;
                        c++;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    auto f = [](vector<vector<int>> &&matrix, int expect) {
        auto output = Solution().countSquares(matrix);
        leetcode_assert(output == expect, "count_square_submatrices_with_all_ones matrix={} expect={} output={}", matrix, expect, output);
    };
//    f(make2DIntVecByStr("[[0,1,1,1],[1,1,1,1],[0,1,1,1]]"), 15);
    f(make2DIntVecByStr("[[1,0,1],[1,1,0],[1,1,0]]"), 7);
}
