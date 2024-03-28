//
// Created by 汪喆昊 on 2024/3/27.
//

#include "leetcode_utils.hpp"

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/?envType=study-plan-v2&envId=top-interview-150
int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<>> pq(nums.begin(), nums.begin() + k);
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > pq.top()) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main() {
    auto f = [](vector<int> &&nums, int k, int expect) {
        int output = findKthLargest(nums, k);
        leetcode_assert(expect == output, "find kth largest nums={} k={} expect={} output={}", nums, k, expect, output);
    };

    f({3, 2, 1, 5, 6, 4}, 2, 5);
    f({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4);
}
