//
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/?envType=daily-question&envId=2025-03-28
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        const int Q = queries.size();
        const int M = grid.size(), N = grid[0].size(), MN = M * N;
        vector<int> ans(Q);
        vector<int> q_indices(Q);
        iota(q_indices.begin(), q_indices.end(), 0);
        sort(q_indices.begin(), q_indices.end(), [&](int i, int j) { return queries[i] < queries[j]; });

        vector<int> parents(MN);
        iota(parents.begin(), parents.end(), 0);
        vector<int> sizes(MN, 1);
        vector<int> ids(MN);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return grid[i / N][i % N] < grid[j / N][j % N];
        });

        auto findParent = [&](int u) {
            while (u != parents[u]) {
                parents[u] = parents[parents[u]];
                u = parents[u];
            }
            return u;
        };

        auto merge = [&](int from, int to) {
            int p_from = findParent(from);
            int p_to = findParent(to);
            if (p_from == p_to) {
                return;
            }
            parents[p_from] = p_to;
            sizes[p_to] += sizes[p_from];
        };

        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int j = 0;
        for (int i = 0; i < Q; i++) {
            int qi = q_indices[i];
            int query = queries[qi];
            for (; j < MN && grid[ids[j] / N][ids[j] % N] < query; j++) {
                int r = ids[j] / N, c = ids[j] % N;
                for (auto [dx, dy] : directions) {
                    int x = r + dx, y = c + dy;
                    if (0 <= x && x < M && 0 <= y && y < N && grid[x][y] < query) {
                        merge(x * N + y, ids[j]);
                    }
                }
            }
            if (grid[0][0] < query) {
                ans[qi] = sizes[findParent(0)];
            }
        }
        return ans;
    }
};

//class Solution {
//public:
//    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
//        const int Q = queries.size();
//        const int M = grid.size();
//        const int N = grid[0].size();
//        vector<int> ans(Q);
//        vector<int> q_indices(Q);
//        iota(q_indices.begin(), q_indices.end(), 0);
//        sort(q_indices.begin(), q_indices.end(), [&](int i, int j) { return queries[i] < queries[j]; });
//        vector<pair<int, int>> start_points{{0, 0}};
//        vector<vector<bool>> visited(M, vector<bool>(N, false));
//        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//        for (int i = 0; i < Q; i++) {
//            int qi = q_indices[i];
//            int query = queries[qi];
//            int res = i > 0 ? ans[q_indices[i - 1]] : 0;
//            if (i > 0 && queries[q_indices[i]] == queries[q_indices[i - 1]]) {
//                ans[qi] = res;
//                continue;
//            }
//            deque<pair<int, int>> dq(start_points.begin(), start_points.end());
//            start_points.clear();
//            while (!dq.empty()) {
//                auto [r, c] = dq.front();
//                dq.pop_front();
//                if (grid[r][c] >= query) {
//                    start_points.emplace_back(r, c);
//                    continue;
//                }
//                visited[r][c] = true;
//                res++;
//                for (auto [dx, dy] : directions) {
//                    int x = r + dx, y = c + dy;
//                    if (0 <= x && x < M && 0 <= y && y < N && !visited[x][y]) {
//                        visited[x][y] = true;
//                        dq.emplace_back(x, y);
//                    }
//                }
//            }
//            ans[qi] = res;
//        }
//        return ans;
//    }
//};

// class Solution {
// public:
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         M = grid.size();
//         N = grid[0].size();
//         visited.resize(M, vector<bool>(N, false));
//         vector<int> ans;
//         ans.reserve(queries.size());
//         for (int q : queries) {
//             int cnt = 0;
//             for (auto &row : visited) {
//                 fill(row.begin(), row.end(), false);
//             }
//             if (q > grid[0][0]) {
//                 dfs(0, 0, q, cnt, grid);
//             }
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
//
// private:
//     int M, N;
//     vector<vector<bool>> visited;
//     vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//
//     void dfs(int r, int c, int val, int &cnt, vector<vector<int>>& grid) {
//         cnt++;
//         visited[r][c] = true;
//         for (auto [dx, dy] : directions) {
//             int x = r + dx, y = c + dy;
//             if (0 <= x && x < M && 0 <= y && y < N && !visited[x][y] && grid[x][y] < val) {
//                 dfs(x, y, val, cnt, grid);
//             }
//         }
//     }
// };


int main() {
    auto f = [](vector<vector<int>> &&grid, vector<int> &&queries, vector<int> expect) {
        auto output = Solution().maxPoints(grid, queries);
        leetcode_assert(output == expect,
                        "maximum_number_of_points_from_grid_queries grid={} queries={} expect={} output={}", grid,
                        queries, expect, output);
    };
    f(make2DIntVecByStr("[[1,2,3],[2,5,7],[3,5,1]]"), {5, 6, 2}, {5, 8, 1});
}
