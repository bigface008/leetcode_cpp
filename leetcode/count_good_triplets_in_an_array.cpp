//
// https://leetcode.cn/problems/count-good-triplets-in-an-array/?envType=daily-question&envId=2025-04-15
//

#include "leetcode_utils.hpp"

using namespace std;


// dp[k1][k2] -> set()  dp[j1][j2] + (k1, k2)
// ans = sum(dp
class TreeArray {
public:
    TreeArray(int n) : tree(n + 1) {}

    void update(int i, int val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    int pre(int i) const {
        int res = 0;
        for (; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }

private:
    vector<int> tree;
};

class Solution {
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
        const int N = nums1.size();
        vector<int> pos(N, 0);
        for (int i = 0; i < N; i++) {
            pos[nums1[i]] = i;
        }

        long long ans = 0;
        TreeArray ta(N);
        for (int i = 0; i < N - 1; i++) {
            int y = pos[nums2[i]];
            int less = ta.pre(y);
            ans += (long long) less * (N - 1 - y - (i - less));
            ta.update(y + 1, 1);
        }
        return ans;
    }
};

//class Solution {
//public:
//    long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
//        const int N = nums1.size();
//        prev1.reserve(N);
//        prev2.reserve(N);
//        for (int k = 0; k < N; k++) {
//            prev1.emplace_back(st1);
//            prev2.emplace_back(st2);
//            int z1 = nums1[k];
//            int z2 = nums2[k];
//            pos1[z1] = k;
//            pos2[z2] = k;
//            st1.insert(z1);
//            st2.insert(z2);
//
//            if (z1 == z2) {
//                calc(k, k);
//            } else {
//                if (st2.contains(z1)) {
//                    calc(k, pos2[z1]);
//                }
//                if (st1.contains(z2)) {
//                    calc(pos1[z2], k);
//                }
//            }
//        }
//        return ans;
//    }
//
//private:
//    long long ans = 0;
//    map<int, int> pos1, pos2;
//    set<int> st1, st2;
//    vector<set<int>> prev1, prev2;
//
//    void calc(int k1, int k2) {
//        set<int> &y_values1 = prev1[k1], &y_values2 = prev2[k2];
//        vector<int> common_y;
//        std::set_intersection(y_values1.begin(), y_values1.end(), y_values2.begin(), y_values2.end(),
//                              back_inserter(common_y));
//        for (int y : common_y) {
//            int y_pos1 = pos1[y], y_pos2 = pos2[y];
//            if (y_pos1 == 0 || y_pos2 == 0) {
//                continue;
//            }
//            set<int> &x_values1 = prev1[y_pos1], &x_values2 = prev2[y_pos2];
//            vector<int> common_x;
//            std::set_intersection(x_values1.begin(), x_values1.end(), x_values2.begin(), x_values2.end(),
//                                  back_inserter(common_x));
//            ans += (long long)common_x.size();
//        }
//    }
//};


int main() {
    auto f = [](vector<int> &&nums1, vector<int> &&nums2, long long expect) {
        auto output = Solution().goodTriplets(nums1, nums2);
        leetcode_assert(output == expect, "count_good_triplets_in_an_array nums1={} nums2={} expect={} output={}",
                        nums1, nums2, expect, output);
    };
    f({4, 0, 1, 3, 2}, {4, 1, 0, 2, 3}, 4);
    //    f({13, 14, 10, 2, 12, 3, 9, 11, 15, 8, 4, 7, 0, 6, 5, 1}, {8, 7, 9, 5, 6, 14, 15, 10, 2, 11, 4, 13, 3, 12, 1,
    //    0},
    //      77);
}
