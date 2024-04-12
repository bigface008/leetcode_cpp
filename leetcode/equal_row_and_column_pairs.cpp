//
// https://leetcode.com/problems/equal-row-and-column-pairs/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int equalPairs(vector<vector<int>> &grid) {
    const int N = grid.size();
    if (N == 0) {
        return 0;
    }
    int cnt = 0;
    map<vector<int>, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        vector<int> col(N, 0);
        for (int j = 0; j < N; j++) {
            col[j] = grid[j][i];
        }
        mp[col].push_back(i);
    }
    for (auto &row : grid) {
        auto it = mp.find(row);
        if (it != mp.end() && !it->second.empty()) {
            cnt += it->second.size();
        }
    }
    return cnt;
}

int main() {
    auto f = [](vector<vector<int>> &&grid, int expect) {
        auto output = equalPairs(grid);
        leetcode_assert(output == expect, "equal_row_and_column_pairs grid={} expect={} output={}", grid, expect,
                        output);
    };
    f({{3, 2, 1}, {1, 7, 6}, {2, 7, 7}}, 1);
    f({{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}}, 3);
    f({{3, 1, 2, 2}, {1, 4, 4, 4}, {2, 4, 2, 2}, {2, 5, 2, 2}}, 3);
}
