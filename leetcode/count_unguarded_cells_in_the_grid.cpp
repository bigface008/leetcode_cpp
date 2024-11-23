//
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2024-11-21
//

#include "leetcode_utils.hpp"

using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) { return p1.first < p2.first; }

class Solution2 {
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 1 guard 2 wall
        for (vector<int> &pos : walls) {
            grid[pos[0]][pos[1]] = 2;
        }
        for (vector<int> &pos : guards) {
            grid[pos[0]][pos[1]] = 1;
        }
        vector<vector<pair<int, int>>> rowInfo(m, vector<pair<int, int>>(n));
        vector<vector<pair<int, int>>> colInfo(n, vector<pair<int, int>>(m));
        for (int i = 0; i < m; i++) {
            vector<pair<int, int>> &row = rowInfo[i];
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    row[j].first = grid[i][j];
                } else {
                    row[j].first = j > 0 ? row[j - 1].first : 0;
                }
                if (grid[i][n - 1 - j] != 0) {
                    row[n - 1 - j].second = grid[i][n - 1 - j];
                } else {
                    row[n - 1 - j].second = (n - j < n) ? row[n - j].second : 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            vector<pair<int, int>> &col = colInfo[j];
            for (int i = 0; i < m; i++) {
                if (grid[i][j] != 0) {
                    col[i].first = grid[i][j];
                } else {
                    col[i].first = i > 0 ? col[i - 1].first : 0;
                }
                if (grid[m - 1 - i][j] != 0) {
                    col[m - 1 - i].second = grid[m - 1 - i][j];
                } else {
                    col[m - 1 - i].second = (m - i < m) ? col[m - i].second : 0;
                }
            }
        }
//        fmt::println("rowInfo={}", rowInfo);
//        fmt::println("colInfo={}", colInfo);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    continue;
                }
                auto &p1 = rowInfo[i][j];
                auto &p2 = colInfo[j][i];
//                fmt::println("i={} j={} p1={} p2={}", i, j, p1, p2);
                if (!(p1.first == 1 || p1.second == 1 || p2.first == 1 || p2.second == 1)) {
//                    fmt::println("  adding i={} j={}", i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (vector<int>& pos : guards) {
            grid[pos[0]][pos[1]] = 1;
        }
        for (vector<int>& pos : walls) {
            grid[pos[0]][pos[1]] = 2;
        }
        for (vector<int>& pos : guards) {
            for (auto [dx, dy] : directions) {
                int x = pos[0] + dx, y = pos[1] + dy;
                while (0 <= x && x < m && 0 <= y && y < n) {
                    if (grid[x][y] == 2 || grid[x][y] == 1) {
                        break;
                    }
                    grid[x][y] = 3;
                    x += dx;
                    y += dy;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](int m, int n, vector<vector<int>> &&guards, vector<vector<int>> &&walls, int expect) {
        auto output = Solution().countUnguarded(m, n, guards, walls);
        leetcode_assert(output == expect,
                        "count_unguarded_cells_in_the_grid m={} n={} guards={} walls={} expect={} output={}", m, n,
                        guards, walls, expect, output);
    };
    f(4, 6, make2DIntVecByStr("[[0,0],[1,1],[2,3]]"), make2DIntVecByStr("[[0,1],[2,2],[1,4]]"), 7);
}
