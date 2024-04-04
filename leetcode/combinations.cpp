//
// Created by 汪喆昊 on 2024/3/28.
// https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

void backtrack(int idx, int n, int k, vector<int> &temp, vector<vector<int>> &res) {
    if (temp.size() == k) {
        res.push_back(temp);
        return;
    }
    for (int i = idx; i < n; i++) {
        temp.push_back(i + 1);
        backtrack(i + 1, n, k, temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(0, n, k, temp, res);
    return res;
}

int main() {
    auto f = [](int n, int k, vector<vector<int>> &&expect) {
        auto output = combine(n, k);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "combine n={} k={} expect={} output={}", n, k, expect, output);
    };
    f(4, 2, {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}});
    f(1, 1, {{1}});
}
