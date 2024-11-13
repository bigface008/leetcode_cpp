//
// https://leetcode.cn/problems/design-neighbor-sum-service/?envType=daily-question&envId=2024-11-09
//

#include "leetcode_utils.hpp"

using namespace std;

class NeighborSum {
private:
    unordered_map<int, pair<int, int>> posMap;
    vector<vector<int>> &grid;
    int M;
    int N;

    int sum(int value, const vector<pair<int, int>> &ds) {
        auto [x, y] = posMap[value];
        int ans = 0;
        for (auto [dx, dy] : ds) {
            int r = x + dx, c = y + dy;
            if (0 <= r && r < N && 0 <= c && c < M) {
                ans += grid[r][c];
            }
        }
        return ans;
    }

public:
    static const vector<pair<int, int>> adjacent;
    static const vector<pair<int, int>> diagonal;

    NeighborSum(vector<vector<int>>& _grid) : grid(_grid) {
        N = grid.size();
        M = grid[0].size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int x = grid[i][j];
                posMap[x] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        return sum(value, adjacent);
    }

    int diagonalSum(int value) {
        return sum(value, diagonal);
    }
};

const vector<pair<int, int>> NeighborSum::adjacent = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const vector<pair<int, int>> NeighborSum::diagonal = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

//static const vector<pair<int, int>> adjacent{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//static const vector<pair<int, int>> diagonal{{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int main() {
//    auto f = [](vector<vector<int>> &&grid, NeighborSum(vector<vector<int>>& expect) {
//        auto output = Solution().(grid);
//        leetcode_assert(output == expect, "design_neighbor_sum_service grid={} expect={} output={}", grid, expect, output);
//    };
//    f();
}
