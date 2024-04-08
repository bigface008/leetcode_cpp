//
// https://leetcode.com/problems/snakes-and-ladders/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

pair<int, int> get_pos(const int N, int seq) {
    int r_seq = N * N - seq;
    if (r_seq < 0) {
        return {-1, -1};
    }
    int row = r_seq / N;
    int col = r_seq % N;
    bool forward = (seq - 1) / N % 2 == 0;
    if (forward) {
        return {row, N - col - 1};
    } else {
        return {row, col};
    }
}

int snakesAndLadders(vector<vector<int>> &board) {
    if (board.empty() || board[0].empty()) {
        return 0;
    }
    const int N = board.size();
    const int TARGET = N * N;
    queue<int> q;
    vector<bool> visited(TARGET, false);
    q.push(1);
    int step = 0;
    while (!q.empty()) {
        int level_size = q.size();
        for (int k = 0; k < level_size; k++) {
            int curr = q.front();
            if (curr == TARGET) {
                return step;
            }
            q.pop();
            if (visited[curr]) {
                continue;
            }
            visited[curr] = true;
            for (int i = 0; i < 6; i++) {
                int elem = curr + 1 + i;
                auto [row, col] = get_pos(N, elem);
                if (row == -1 || col == -1) {
                    break;
                }
                if (board[row][col] == -1) {
                    q.push(elem);
                } else {
                    q.push(board[row][col]);
                }
            }
        }
        step++;
    }
    return -1;
}

int main() {
    auto f = [](vector<vector<int>> &&board, int expect) {
        auto output = snakesAndLadders(board);
        leetcode_assert(output == expect, "snakes_and_ladders board={} expect={} output={}", board, expect, output);
    };
    f({{-1, -1, -1, -1, -1, -1},
       {-1, -1, -1, -1, -1, -1},
       {-1, -1, -1, -1, -1, -1},
       {-1, 35, -1, -1, 13, -1},
       {-1, -1, -1, -1, -1, -1},
       {-1, 15, -1, -1, -1, -1}},
      4);
    f({{-1, -1}, {-1, 3}}, 1);
    f({{1, 1, -1}, {1, 1, 1}, {-1, 1, 1}}, -1);
    f({{-1, -1, -1, -1, 48, 5, -1},
       {12, 29, 13, 9, -1, 2, 32},
       {-1, -1, 21, 7, -1, 12, 49},
       {42, 37, 21, 40, -1, 22, 12},
       {42, -1, 2, -1, -1, -1, 6},
       {39, -1, 35, -1, -1, 39, -1},
       {-1, 36, -1, -1, -1, -1, 5}},
      3);
}
