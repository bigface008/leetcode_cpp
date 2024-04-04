//
// Created by 汪喆昊 on 2024/3/31.
//

#include "leetcode_utils.hpp"

using namespace std;

// 腾讯的笔试题。给定一个数组，要求把数组分为K组，将各组的数字异或之后求和，要求其和最大，返回最大的和。
// 记不得测试用例了。
// 如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0。

// 解题思路是枚举所有的分组可能，然后求异或的和。

void backtrack(int step, int k, int size, vector<int> &indices, vector<vector<int>> &res) {
    if (k == 1) {
        res.emplace_back();
        return;
    }
    if (step == k - 1) {
        res.push_back(indices);
        return;
    }
    int start = 1;
    if (step != 0) {
        start = indices.back() + 1;
    }
    int end = size - (k - step) + 1;
    for (int i = start; i <= end; i++) {
        indices.push_back(i);
        backtrack(step + 1, k, size, indices, res);
        indices.pop_back();
    }
}

int solution(vector<int> &input, int k) {
    vector<vector<int>> res;
    vector<int> indices;
    backtrack(0, k, input.size(), indices, res);
    fmt::println("split indices groups {}", res);

    int ans = 0;
    for (auto &split_indices : res) {
        int start = 0;
        int xor_sum = 0;
        int curr = -1;
        fmt::println("group start");
        for (int split_idx : split_indices) {
            fmt::print("{{");
            for (int i = start; i < split_idx; i++) {
                fmt::print("{}, ", input[i]);
                if (curr == -1) {
                    curr = input[i];
                } else {
                    curr ^= input[i];
                }
            }
            fmt::println("}}");
            start = split_idx;
            xor_sum += curr;
            curr = -1;
        }
        fmt::print("{{");
        for (int i = start; i < input.size(); i++) {
            fmt::print("{}, ", input[i]);
            if (curr == -1) {
                curr = input[i];
            } else {
                curr ^= input[i];
            }
        }
        xor_sum += curr;
        fmt::println("}}");
        fmt::println("group end res={}", xor_sum);
        if (xor_sum > ans) {
            ans = xor_sum;
        }
    }
    return ans;
}

int main() {
//    auto f = [](vector<int> &&input, int k) {
//        int output = solution(input, k);
//        fmt::println("biggest xor sum input={} k={} output={}", input, k, output);
//    };
//    f({1, 1, 1, 2, 3, 4}, 2);
    string s1 = "you are a pig";
    string s2 = "dude";
    if (s1.find(s2) == string::npos) {
        fmt::println("Noo!!!");
    }
}
