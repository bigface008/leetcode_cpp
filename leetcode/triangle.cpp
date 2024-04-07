//
// https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
        return -1;
    }
    vector<vector<int>> dp;
    for (auto &row : triangle) {
        vector<int> new_row(row.size(), 0);
        if (dp.empty()) {
            copy(row.begin(), row.end(), new_row.begin());
        } else {
            auto &last_row = dp.back();
            for (int i = 0; i < row.size(); i++) {
                int val = 0;
                if (i == 0) {
                    val = last_row[i];
                } else if (i == row.size() - 1) {
                    val = last_row[i - 1];
                } else {
                    val = min(last_row[i], last_row[i - 1]);
                }
                new_row[i] = val + row[i];
            }
        }
        dp.push_back(new_row);
    }
    int res = INT_MAX;
    for (auto sum : dp[dp.size() - 1]) {
        res = min(res, sum);
    }
    return res;
}

int main() {
    auto f = [](vector<vector<int>> &&triangle, int expect) {
        auto output = minimumTotal(triangle);
        leetcode_assert(output == expect, "triangle={} expect={} output={}", triangle, expect, output);
    };
    f({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, 11);
    f({{-10}}, -10);
}
