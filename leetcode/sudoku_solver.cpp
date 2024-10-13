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

int main() {
    bitset<8> foo("10011011");
    foo[0]; // 1
    foo[1]; // 0
    foo[2]; // 0
    foo.count(); // 5 （count函数用来求bitset中1的位数，foo中共有５个１
    foo.size(); // 8 （size函数用来求bitset的大小，一共有８位
    foo.test(0); // true （test函数用来查下标处的元素是０还是１，并返回false或true，此处foo[0]为１，返回true
    foo.test(2); // false （同理，foo[2]为０，返回false
    foo.any(); // true （any函数检查bitset中是否有１
    foo.none(); // false （none函数检查bitset中是否没有１
    foo.all(); // false （all函数检查bitset中是全部为１
    foo.flip(2); // 10011111 （flip函数传参数时，用于将参数位取反，本行代码将foo下标２处"反转"，即０变１，１变０
    foo.flip(); // 01100000 （flip函数不指定参数时，将bitset每一位全部取反
    foo.set(); // 11111111 （set函数不指定参数时，将bitset的每一位全部置为１
    foo.set(3, 0); // 11110111 （set函数指定两位参数时，将第一参数位的元素置为第二参数的值，本行对foo的操作相当于foo[3]=0
    foo.set(3); // 11111111 （set函数只有一个参数时，将参数下标处置为１
    foo.reset(4); // 11101111 （reset函数传一个参数时将参数下标处置为０
    foo.reset(); // 00000000 （reset函数不传参数时将bitset的每一位全部置为０

    string s = foo.to_string(); // 将bitset转换成string类型
};
