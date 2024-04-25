//
// https://leetcode.com/problems/non-overlapping-intervals/description/
//

#include "leetcode_utils.hpp"

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }
    int res = 0;
    int previous = 0;
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[previous][1] > intervals[i][0]) {
            res++;
            if (intervals[previous][1] >= intervals[i][1]) {
                previous = i;
            }
        } else {
            previous = i;
        }
    }
    return res;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first;
}

int main() {
    auto f = [](vector<vector<int>> &&intervals, int expect) {
        auto output = eraseOverlapIntervals(intervals);
        leetcode_assert(output == expect, "non_overlapping_intervals intervals={} expect={} output={}", intervals, expect, output);
    };
    f(make2DIntVecByStr("[[1,2],[2,3],[3,4],[1,3]]"), 1);
    f(make2DIntVecByStr("[[1,2],[1,2],[1,2]]"), 2);
    f(make2DIntVecByStr("[[1,2],[2,3]]"), 0);

//    vector<int> a{12, 2, 24, -12, 0, 25, 9, 8, 14};
//    sort(a.begin(), a.end(), greater<>());
//    fmt::println("a {}", a);
//    vector<pair<int, int>> pv;
//    for (int n : a) {
//        pv.emplace_back(n, -n);
//    }
//    fmt::println("pv before sort {}", pv);
//    sort(pv.begin(), pv.end(), cmp);
//    fmt::println("pv after sort {}", pv);
}
