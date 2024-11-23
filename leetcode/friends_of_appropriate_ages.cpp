//
// https://leetcode.cn/problems/friends-of-appropriate-ages/description/?envType=daily-question&envId=2024-11-17
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int> &ages) {
        map<int, int> ageMap;
        vector<int> distinct;
        for (int x : ages) {
            ageMap[x]++;
        }
        for (auto &&[k, v] : ageMap) {
            distinct.push_back(k);
        }
        int yi = 0;
        int ans = 0;
        const int N = distinct.size();
//        fmt::println("ages={}", distinct);
        for (int i = 0; i < N; i++) {
            int ageX = distinct[i];
            int cntX = ageMap[ageX];
            int target = ageX / 2 + 7;
            yi = upper_bound(distinct.begin() + yi, distinct.begin() + i, target) - distinct.begin();
            int oldAns = ans;
//            ans += cntX * ageMap[distinct[yi]] * (i - yi);
            for (int j = yi; j < i; j++) {
                ans += cntX * ageMap[distinct[j]];
            }
            if (ageX > target) {
                ans += cntX * (cntX - 1);
            }
//            fmt::println("ageX={} target={} yi={} add={} ans={}", ageX, target, yi, ans - oldAns, ans);
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int> &&ages, int expect) {
        auto output = Solution().numFriendRequests(ages);
        leetcode_assert(output == expect, "friends_of_appropriate_ages ages={} expect={} output={}", ages, expect,
                        output);
    };
    //    f({16, 16}, 2);
    f({54, 23, 102, 90, 40, 74, 112, 74, 76, 21}, 22);
}
