//
// https://leetcode.com/problems/sudoku-solver/
//

#include <iostream>
#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int emptyCnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') {
                    emptyCnt++;
                    continue;
                }
                int temp = 1 << (board[i][j] - '1');
                rows[i] |= temp;
                cols[j] |= temp;
                cells[i / 3][j / 3] |= temp;
            }
        }
        dfs(board, emptyCnt);
    }

private:
    static const int N = 9;
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;

    bitset<9> getPossibleStatus(int x, int y) { return ~(rows[x] | cols[y] | cells[x / 3][y / 3]); }

    tuple<int, int> getNext(vector<vector<char>> &board) {
        tuple<int, int> ret;
        int minEmptyCnt = INT_MAX;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                auto bits = getPossibleStatus(i, j);
                int cnt = bits.count();
                if (cnt < minEmptyCnt) {
                    minEmptyCnt = cnt;
                    ret = {i, j};
                }
            }
        }
        return ret;
    }

    void fillNum(int x, int y, int n, bool fill) {
        int temp = fill ? 1 : 0;
        rows[x][n] = temp;
        cols[y][n] = temp;
        cells[x / 3][y / 3][n] = temp;
    }

    bool dfs(vector<vector<char>> &board, int emptyCnt) {
        if (emptyCnt == 0) {
            return true;
        }
        auto next = getNext(board);
        auto [next_x, next_y] = next;
        auto status = getPossibleStatus(next_x, next_y);
        for (int n = 0; n < N; n++) {
            if (!status.test(n)) {
                continue;
            }
            fillNum(next_x, next_y, n, true);
            board[next_x][next_y] = n + '1';
            if (dfs(board, emptyCnt - 1)) {
                return true;
            }
            fillNum(next_x, next_y, n, false);
            board[next_x][next_y] = '.';
        }
        return false;
    }
};

// class Solution {
// public:
//     bitset<9> getPossibleStatus(int x, int y) {
//         return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
//     }
//
//     tuple<int, int> getNext(vector<vector<char>> &board) {
//         tuple<int, int> ret;
//         int minCnt = 10;
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] != '.') {
//                     continue;
//                 }
//                 auto cur = getPossibleStatus(i, j);
//                 if (cur.count() >= minCnt) {
//                     continue;
//                 }
//                 ret = {i, j};
//                 minCnt = cur.count();
//             }
//         }
//         return ret;
//     }
//
//     void fillNum(int x, int y, int n, bool fillFlag) {
//         int temp = (fillFlag) ? 1 : 0;
//         rows[x][n] = temp;
//         cols[y][n] = temp;
//         cells[x / 3][y / 3][n] = temp;
//     }
//
//     bool dfs(vector<vector<char>> &board, int cnt) {
//         if (cnt == 0) {
//             return true;
//         }
//         auto next = getNext(board);
//         auto [next_x, next_y] = next;
//         auto bits = getPossibleStatus(next_x, next_y);
//         for (int n = 0; n < bits.size(); n++) {
//             if (!bits.test(n)) {
//                 continue;
//             }
//             fillNum(next_x, next_y, n, true);
//             board[next_x][next_y] = n + '1';
//             if (dfs(board, cnt - 1)) return true;
//             board[next_x][next_y] = '.';
//             fillNum(next_x, next_y, n, false);
//         }
//         return false;
//     }
//
//     void solveSudoku(vector<vector<char>> &board) {
//         rows = vector<bitset<9>>(9, bitset<9>());
//         cols = vector<bitset<9>>(9, bitset<9>());
//         cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));
//
//         int cnt = 0; // blocks need to be filled
//         const int N = 9;
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 int x = board[i][j];
//                 if (x == '.') {
//                     cnt++;
//                     continue;
//                 }
//                 int n = 1 << (x - '1');
//                 rows[i] |= n;
//                 cols[j] |= n;
//                 cells[i / 3][j / 3] |= n;
//             }
//         }
//         dfs(board, cnt);
//     }
//
// private:
//     vector<bitset<9>> rows;
//     vector<bitset<9>> cols;
//     vector<vector<bitset<9>>> cells;
// };

class Object {
public:
    int a;
    string b;
    Object(int _a, const char *_b) : a(_a), b(_b) {}

//    bool operator<(const Object &o2) const {
//        return a < o2.a;
//    }
};

bool cmp(const Object &o1, const Object &o2) {
    return o1.a < o2.a;
}

auto format_as(const Object &obj) {
    return fmt::format("[a:{}, b:{}]", obj.a, obj.b);
}

int main() {
    vector<Object> vec;
    vec.emplace_back(31, "31");
    vec.emplace_back(3, "3");
    vec.emplace_back(-1, "-1");
    vec.emplace_back(9, "9");
    vec.emplace_back(80, "80");
    vec.emplace_back(5, "5");
    fmt::println("{}", vec);
    std::sort(vec.begin(), vec.end());
    fmt::println("{}", vec);
}
