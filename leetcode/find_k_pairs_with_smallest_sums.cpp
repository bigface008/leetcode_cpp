//
// Created by 汪喆昊 on 2024/4/3.
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    priority_queue<int> pq;
    return {};
}

int main() {
    auto f = [](vector<int> &&nums1, vector<int> &&nums2, int k, vector<vector<int>> &&expect) {
        auto output = kSmallestPairs(nums1, nums2, k);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "k smallest pairs nums1={} nums2={} k={} expect={}", nums1, nums2, k, expect);
    };
    f({1, 7, 11}, {2, 4, 6}, 3, {{1, 2}, {1, 4}, {1, 6}, {7, 2}, {7, 4}, {11, 2}, {7, 6}, {11, 4}, {11, 6}});
    f({1, 1, 2}, {1, 2, 3}, 2, {{1, 1}, {1, 1}, {1, 2}, {2, 1}, {1, 2}, {2, 2}, {1, 3}, {1, 3}, {2, 3}});
}
