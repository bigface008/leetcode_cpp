//
// Created by 汪喆昊 on 2024/3/28.
// https://leetcode.com/problems/permutations/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

void backtrack(int idx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res) {
    if (idx == nums.size()) {
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    if (nums.size() == 1) {
        vector<int> temp(nums);
        return {temp};
    }
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
        int picked = nums[i];
        vector<int> remain_nums;
        for (int j = 0; j < nums.size(); j++) {
            if (j != i) {
                remain_nums.push_back(nums[j]);
            }
        }
        auto groups = permute(remain_nums);
        for (auto &group : groups) {
            vector<int> origin(group);
            origin.insert(origin.begin(), picked);
            res.push_back(origin);
        }
    }
    return res;
}

int main() {
    auto f = [](vector<int> &&nums, vector<vector<int>> &&expect) {
        auto output = permute(nums);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "permute nums={} expect={} output={}", nums, expect, output);
    };
    f({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    f({0, 1}, {{0, 1}, {1, 0}});
    f({1}, {{1}});
}
