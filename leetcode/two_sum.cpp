//
// Created by 汪喆昊 on 2024/3/27.
// https://leetcode.com/problems/two-sum/
//

#include "leetcode_utils.hpp"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> indice_map;
    for (int i = 0; i < nums.size(); ++i) {
        auto elem = nums[i];
        auto it = indice_map.find(target - elem);
        if (it != indice_map.end() && it->second != i) {
            return {it->second, i};
        }
        indice_map[elem] = i;
    }
    return {0, 0};
}

int main() {
    auto f = [](vector<int> &&nums, int target, vector<int> &&expect) {
        auto output = twoSum(nums, target);
        bool is_same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(is_same, "two sum nums {} target {} expect {} output {}", nums, target, expect, output);
    };
    f({2, 7, 11, 15}, 9, {0, 1});
}
