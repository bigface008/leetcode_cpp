//
// Created by 汪喆昊 on 2024/4/3.
// https://leetcode.com/problems/max-points-on-a-line/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int maxPoints(vector<vector<int>> &points) {
    const int N = points.size();
    if (N <= 2) {
        return N;
    }

    int ans = 0;
    for (auto &p1 : points) {
        unordered_map<double, int> mp;
        double x1 = p1[0], y1 = p1[1];
        for (auto &p2 : points) {
            if (p1 == p2) {
                continue;
            }
            double x2 = p2[0], y2 = p2[1];
            double slope = 0;
            if (x1 == x2) {
                slope = INT_MAX;
            } else {
                slope = (y2 - y1) / (x2 - x1);
            }
            mp[slope]++;
            ans = max(ans, mp[slope]);
        }
    }
    return ans + 1;
}

int lisp_test() {
}

int main() {
    auto f = [](vector<vector<int>> &&points, int expect) {
        int output = maxPoints(points);
        leetcode_assert(output, "max points on a line points={} expect={} output={}", points, expect, output);
    };
    f({{1, 1}, {2, 2}, {3, 3}}, 3);
    f({{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}, 4);
}
