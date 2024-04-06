//
// Created by 汪喆昊 on 2024/3/30.
// https://leetcode.com/problems/n-queens-ii/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

void backtrack(vector<pair<int, int>> &selection, vector<bool> &row_visited, vector<bool> &col_visited, int row_beg,
               int col_beg, int n, vector<vector<pair<int, int>>> &res) {
    if (selection.size() == n) {
        res.push_back(selection);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (row_visited[i]) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (col_visited[j]) {
                continue;
            }
            selection.emplace_back(i, j);
            row_visited[i] = true;
            col_visited[j] = true;
            backtrack(selection, row_visited, col_visited, i, j, n, res);
            row_visited[i] = false;
            col_visited[j] = false;
            selection.pop_back();
        }
    }
}

int totalNQueens(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    vector<vector<pair<int, int>>> res;
    vector<pair<int, int>> selection;
    vector<bool> row_visited(n, false);
    vector<bool> col_visited(n, false);
    backtrack(selection, row_visited, col_visited, 0, 0, n, res);
    return res.size();
}

void helper(int col, int n, int &counter, vector<string> &temp, vector<int> &left, vector<int> &lower,
            vector<int> &upper) {
    if (col == n) {
        counter++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (left[i] == 0 and lower[i + col] == 0 and upper[n - 1 + col - i] == 0) {
            left[i] = 1;
            lower[i + col] = 1;
            upper[n - 1 + col - i] = 1;
            temp[i][col] = 'Q';

            helper(col + 1, n, counter, temp, left, lower, upper);

            left[i] = 0;
            lower[i + col] = 0;
            upper[n - 1 + col - i] = 0;
            temp[i][col] = '.';
        }
    }
}

int totalNQueensV2(int n) {
    int counter = 0;
    string s(n, '.');
    vector<string> temp(n, s);
    vector<int> leftRow(n, 0), lowerDiagnol(2 * n - 1, 0), upperDiagnol(2 * n - 1, 0);
    helper(0, n, counter, temp, leftRow, lowerDiagnol, upperDiagnol);
    return counter;
}

int main() {
    auto f = [](int n, int expect) {
        int output = totalNQueensV2(n);
        leetcode_assert(output == expect, "n queens n={} expect={} output={}", n, expect, output);
    };
    f(4, 2);
    f(1, 1);
}
