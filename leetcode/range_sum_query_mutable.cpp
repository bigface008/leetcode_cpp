//
// Created by 汪喆昊 on 2025/4/14.
//

#include <leetcode_utils.hpp>

using namespace std;

// https://leetcode.cn/problems/range-sum-query-mutable/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        const int N = nums.size();
        this->nums.resize(N, 0);
        tree.resize(N + 1, 0);
        for (int i = 0; i < N; i++) {
            update(i, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        int i = index + 1;
        while (i < tree.size()) {
            tree[i] += delta;
            i += i & -i;
        }
    }

    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }

private:
    vector<int> nums;
    vector<int> tree;

    int prefixSum(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};