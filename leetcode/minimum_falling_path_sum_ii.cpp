//
// https://leetcode.cn/problems/minimum-falling-path-sum-ii/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        N = grid.size();

    }

private:
    vector<vector<int>> memo;
    int N;

    void backtrack(vector<int> &path, int sum, vector<vector<int>> &grid) {
        if (path.empty()) {
            for (int i = 0; i < N; i++) {
                path.push_back(i);
                backtrack(path, grid[0][i], grid);
                path.pop_back();
            }
            return;
        }
    }

    int dfs(int rowIdx, int colIdx, vector<vector<int>>& grid) {
        int curr = grid[rowIdx][colIdx];
        if (rowIdx == 0) {
            return curr;
        }
//        for (int i = 0; i < )
    }
};


int main() {
    auto f = [](vector<vector<int>>&& grid, int expect) {
        auto output = Solution().minFallingPathSum(grid);
        leetcode_assert(output == expect, "minimum_falling_path_sum_ii grid={} expect={} output={}", grid, expect, output);
    };
    f();
}
