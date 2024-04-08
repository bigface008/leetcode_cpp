//
// Created by 汪喆昊 on 2024/3/30.
// https://leetcode.com/problems/n-queens-ii/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

void backtrack(int col, int &count, const int N, vector<bool> &row, vector<bool> &upper_diagonal, vector<bool> &lower_diagonal) {
    if (col == N) {
        count++;
        return;
    }
    for (int i = 0; i < N; i++) {
        int upper_index = i + col;
        int lower_index = N + col - i - 1;
        if (!row[i] && !upper_diagonal[upper_index] && !lower_diagonal[lower_index]) {
            row[i] = true;
            upper_diagonal[upper_index] = true;
            lower_diagonal[lower_index] = true;
            backtrack(col + 1, count, N, row, upper_diagonal, lower_diagonal);
            row[i] = false;
            upper_diagonal[upper_index] = false;
            lower_diagonal[lower_index] = false;
        }
    }
}

int totalNQueens(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    vector<bool> row(n, false);
    vector<bool> upper_diagonal(2 * n - 1, false);
    vector<bool> lower_diagonal(2 * n - 1, false);
    int ans = 0;
    backtrack(0, ans, n, row, upper_diagonal, lower_diagonal);
    return ans;
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
        int output = totalNQueens(n);
        leetcode_assert(output == expect, "n queens n={} expect={} output={}", n, expect, output);
    };
    f(4, 2);
    f(1, 1);
}
