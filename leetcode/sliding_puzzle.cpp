//
// https://leetcode.com/problems/sliding-puzzle/description/?envType=daily-question&envId=2024-11-25
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
private:
    struct Node {
        string grid;
        int pos;

        Node(string &grid_, int pos_) : grid(grid_), pos(pos_) {}
    };

    static string to_string(vector<vector<int>> &grid) {
        string ans(6, 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                ans[i * 3 + j] = '0' + grid[i][j];
            }
        }
        return ans;
    }

public:
    int slidingPuzzle(vector<vector<int>> &board) {
        const int M = 2, N = 3;
        unordered_set<string> visited;
        vector<pair<int, int>> dpos{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        deque<Node> dq;
        string grid = to_string(board);
        if (grid == "123450") {
            return 0;
        }
        int pos = 0;
        for (int i = 0; i < 6; i++) {
            if (grid[i] == '0') {
                pos = i;
                break;
            }
        }
        dq.emplace_back(grid, pos);
        int stepCnt = 0;
        while (!dq.empty()) {
            int layerSize = dq.size();
            stepCnt++;
            for (int i = 0; i < layerSize; i++) {
                Node node = dq.front();
                dq.pop_front();
                visited.insert(node.grid);

                int ox = node.pos / 3, oy = node.pos % 3;
                for (auto [dx, dy] : dpos) {
                    int x = ox + dx, y = oy + dy;
                    int pos = x * 3 + y;
                    if (0 <= x && x < M && 0 <= y && y < N) {
                        string newGrid(node.grid);
                        newGrid[pos] = '0';
                        newGrid[node.pos] = node.grid[pos];
                        if (visited.contains(newGrid)) {
                            continue;
                        }

                        if (newGrid == "123450") {
                            return stepCnt;
                        }
                        dq.emplace_back(newGrid, pos);
                    }
                }
            }
        }
        return -1;
    }
};


// class Solution {
// private:
//     struct Node {
//         vector<vector<int>> grid;
//         pair<int, int> zeroPos;
//         Node *parent;
//
//         Node(vector<vector<int>> &grid_, pair<int, int> &pos_, Node *parent_) :
//             grid(grid_), zeroPos(pos_), parent(parent_) {}
//     };
//
// public:
//     int slidingPuzzle(vector<vector<int>> &board) {
//         const int M = 2, N = 3;
//         vector<pair<int, int>> dpos{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
////        vector<pair<int, int>> dpos{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
//        deque<Node> dq;
//        unordered_set<string> visited;
//
//        pair<int, int> zeroPos;
//        for (int i = 0; i < M; i++) {
//            for (int j = 0; j < N; j++) {
//                if (board[i][j] == 0) {
//                    zeroPos.first = i;
//                    zeroPos.second = j;
//                    break;
//                }
//            }
//        }
//        if (to_string(board) == "123450") {
//            return 0;
//        }
//
//        int stepCnt = 0;
//        dq.emplace_back(board, zeroPos, nullptr);
//        while (!dq.empty()) {
//            int layerSize = dq.size();
//            stepCnt++;
//            for (int i = 0; i < layerSize; i++) {
//                Node node = dq.front();
//                dq.pop_front();
//                visited.insert(to_string(node.grid));
////                fmt::println("{}", node.grid);
//
//                for (auto [dx, dy] : dpos) {
//                    int x = node.zeroPos.first + dx, y = node.zeroPos.second + dy;
//                    if (0 <= x && x < M && 0 <= y && y < N) {
//                        vector<vector<int>> newGrid(node.grid);
//                        newGrid[x][y] = 0;
//                        newGrid[node.zeroPos.first][node.zeroPos.second] = node.grid[x][y];
//                        if (visited.contains(to_string(newGrid))) {
//                            continue;
//                        }
//
//                        bool valid = true;
//                        for (int i = 0; i < M; i++) {
//                            for (int j = 0; j < N; j++) {
//                                if (newGrid[i][j] != i * N + j + 1 && !(i == 1 && j == 2)) {
//                                    valid = false;
//                                    break;
//                                }
//                            }
//                        }
//                        if (valid) {
//                            return stepCnt;
//                        }
//
//                        pair<int, int> p{x, y};
////                        fmt::println("  -> {}", newGrid);
//                        dq.emplace_back(newGrid, p, &node);
//                    }
//                }
//            }
//        }
//        return -1;
//    }
//
//    static string to_string(vector<vector<int>> &grid) {
//        string ans(6, 0);
//        for (int i = 0; i < 2; i++) {
//            for (int j = 0; j < 3; j++) {
//                ans[i * 3 + j] = '0' + grid[i][j];
//            }
//        }
//        return ans;
//    }
//};

int main() {
    auto f = [](vector<vector<int>> &&board, int expect) {
        auto output = Solution().slidingPuzzle(board);
        leetcode_assert(output == expect, "sliding_puzzle board={} expect={} output={}", board, expect, output);
    };
    f(make2DIntVecByStr("[[1,2,3],[4,0,5]]"), 1);
    f(make2DIntVecByStr("[[1,2,3],[5,4,0]]"), -1);
    f(make2DIntVecByStr("[[4,1,2],[5,0,3]]"), 5);
}
