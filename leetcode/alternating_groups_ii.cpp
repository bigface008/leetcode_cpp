//
// https://leetcode.cn/problems/alternating-groups-ii/?envType=daily-question&envId=2024-11-27
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k) {
        const int N = colors.size();
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < N + k - 1; i++) {
            if (i == 0 || colors[(i - 1) % N] != colors[i % N]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt >= k) {
                ans++;
            }
        }
        return ans;
    }
};

//class Solution {
//public:
//    int numberOfAlternatingGroups(vector<int> &colors, int k) {
//        const int N = colors.size();
//        int left = 0, right = 0;
//        int ans = 0;
//        for (; right < N + k - 1; right++) {
//            if (right == 0 || colors[(right - 1) % N] != colors[right % N]) {
//                if (right - left + 1 >= k) {
//                    ans++;
//                }
//                continue;
//            } else {
//                left = right;
//            }
//        }
//        return ans;
//    }
//};


int main() {
    auto f = [](vector<int> &&colors, int k, int expect) {
        auto output = Solution().numberOfAlternatingGroups(colors, k);
        leetcode_assert(output == expect, "alternating_groups_ii colors={} k={} expect={} output={}", colors, k, expect,
                        output);
    };
    f({0, 1, 0, 1, 0}, 3, 3);
}
