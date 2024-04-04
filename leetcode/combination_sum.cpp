//
// Created by 汪喆昊 on 2024/3/28.
// https://leetcode.com/problems/combination-sum/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

void backtrack(vector<int> &candidates, int target, int curr_sum, int curr_index, vector<int> &curr_comb, vector<vector<int>> &res) {
    if (curr_sum > target) {
        return;
    }
    if (curr_sum == target) {
        res.push_back(curr_comb);
        return;
    }
    for (int i = curr_index; i < candidates.size(); i++) {
        int candidate = candidates[i];
        curr_comb.push_back(candidate);
        curr_sum += candidate;
        backtrack(candidates, target, curr_sum, i, curr_comb, res);
        curr_sum -= candidate;
        curr_comb.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(candidates, target, 0, 0, temp, res);
    return res;
}

int main() {
    auto f = [](vector<int> &&candidates, int target, vector<vector<int>> &&expect) {
        auto output = combinationSum(candidates, target);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "combination sum candidates={} target={} expect={} output={}", candidates, target, expect,
                        output);
    };
    f({2, 3, 6, 7}, 7, {{2, 2, 3}, {7}});
    f({2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}});
    f({2}, 1, {});
}
