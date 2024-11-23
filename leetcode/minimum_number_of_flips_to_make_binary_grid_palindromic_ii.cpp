//
// https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii/?envType=daily-question&envId=2024-11-16
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        const int M = grid.size(), N = grid[0].size();
        int ans = 0;
        for (int i = 0; i < M / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                int temp = grid[i][j] + grid[i][N - 1 - j] + grid[M - 1 - i][j] + grid[M - 1 - i][N - 1 - j];
                if (temp != 0 && temp != 4) {
                    if (temp == 2) {
                        ans += 2;
                    } else if (temp == 1) {
                        ans++;
                    } else { // 3
                        ans++;
                    }
                }
            }
        }
        if (M % 2 == 1 && N % 2 == 1) {
            if (grid[M / 2][N / 2] == 1) {
                ans++;
            }
        }
        int diffPairsCnt = 0, samePairSum = 0;
        if (M % 2 == 1) {
            for (int j = 0; j < N / 2; j++) {
                if (grid[M / 2][j] != grid[M / 2][N - 1 - j]) {
                    diffPairsCnt++;
                } else {
                    samePairSum += 2 * grid[M / 2][j];
                }
            }
        }
        if (N % 2 == 1) {
            for (int i = 0; i < M / 2; i++) {
                if (grid[i][N / 2] != grid[M - 1 - i][N / 2]) {
                    diffPairsCnt++;
                } else {
                    samePairSum += 2 * grid[i][N / 2];
                }
            }
        }
        if (diffPairsCnt == 0) {
            ans += samePairSum % 4;
        } else {
            ans += diffPairsCnt;
        }
        return ans;
    }
};

class Solution2 {
public:
    int minFlips(vector<vector<int>>& grid) {
        const int M = grid.size(), N = grid[0].size();
        int oneSum = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    oneSum++;
                }
            }
        }
        int remain = oneSum % 4;
        int ans = 0;
        for (int i = 0; i < M / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                int temp = grid[i][j] + grid[i][N - 1 - j] + grid[M - 1 - i][j] + grid[M - 1 - i][N - 1 - j];
                if (temp != 0 && temp != 4) {
                    // info.push_back({4, temp});
                    if (temp == 2) {
                        ans += 2;
                        remain = (remain + 2) % 4;
                    } else if (temp == 1) {
                        ans++;
                        remain = (remain + 3) % 4;
                    } else { // 3
                        ans++;
                        remain = (remain + 1) % 4;
                    }
                }
            }
        }
        int middles = 0;
        if (M % 2 != 0) {
            for (int j = 0; j < N / 2; j++) {
                int temp = grid[M / 2][j] + grid[M / 2][N - 1 - j];
                if (temp != 2) {
                    ans++;
                    middles++;
                }
            }
        }
        if (N % 2 != 0) {
            for (int i = 0; i < M / 2; i++) {
                int temp = grid[i][N / 2] + grid[M - 1 - i][N / 2];
                if (temp != 2) {
                    ans++;
                    middles++;
                }
            }
        }
        int center = 0;
        if (M % 2 != 0 && N % 2 != 0) {
            center = 1;
        }
        if (middles == 0 && center == 0) {
            return ans;
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<vector<int>>&& grid, int expect) {
        auto output = Solution().minFlips(grid);
        leetcode_assert(output == expect, "minimum_number_of_flips_to_make_binary_grid_palindromic_ii grid={} expect={} output={}", grid, expect, output);
    };
    f();
}
