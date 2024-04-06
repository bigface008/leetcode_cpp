//
// Created by 汪喆昊 on 2024/4/3.
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    if (k == 0 || nums1.empty() || nums2.empty()) {
        return {};
    }
    vector<vector<int>> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
    for (int n : nums1) {
        min_heap.push({n + nums2[0], 0});
    }
    while (k > 0 && !min_heap.empty()) {
        auto [sum, pos] = min_heap.top();
        int n2 = nums2[pos];
        int n1 = sum - n2;
        res.push_back({n1, n2});
        min_heap.pop();
        if (pos + 1 < nums2.size()) {
            min_heap.push({n1 + nums2[pos + 1], pos + 1});
        }
        k--;
    }
    return res;
}

int main() {
    auto f = [](vector<int> &&nums1, vector<int> &&nums2, int k, vector<vector<int>> &&expect) {
        auto output = kSmallestPairs(nums1, nums2, k);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "k smallest pairs \n  nums1={} nums2={} k={} \n  expect={}\n  output={}", nums1, nums2, k,
                        expect, output);
    };
    f({1, 7, 11}, {2, 4, 6}, 3, {{1, 2}, {1, 4}, {1, 6}});
    f({1, 1, 2}, {1, 2, 3}, 2, {{1, 1}, {1, 1}});
    f({1, 2, 4, 5, 6}, {3, 5, 7, 9}, 3, {{{1, 3}, {2, 3}, {1, 5}}});
}
