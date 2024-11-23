//
// https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/?envType=daily-question&envId=2024-11-15
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        const int M = grid.size(), N = grid[0].size();
        // row
        int rowCnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N / 2; j++) {
                if (grid[i][j] != grid[i][N - 1 - j]) {
                    rowCnt++;
                }
            }
        }
        int colCnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M / 2; j++) {
                if (grid[j][i] != grid[M - 1 - j][i]) {
                    colCnt++;
                }
            }
        }
        return min(rowCnt, colCnt);
    }
};


int main() {
    auto f = [](vector<vector<int>>&& grid, int expect) {
        auto output = Solution().minFlips(grid);
        leetcode_assert(output == expect, "minimum_number_of_flips_to_make_binary_grid_palindromic_i grid={} expect={} output={}", grid, expect, output);
    };
    f();
}
