//
// https://leetcode.cn/problems/shopping-offers/solutions/1064231/wei-rao-li-lun-kan-qi-lai-xiang-bei-bao-l4trt/?envType=daily-question&envId=2024-11-03
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        N = needs.size();
        return dfs(needs, price, special);
    }

private:
    map<vector<int>, int> memo;
    int N;

    int dfs(vector<int> needs, vector<int> &price, vector<vector<int>> &special) {
        auto it = memo.find(needs);
        if (it != memo.end()) {
            return it->second;
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += price[i] * needs[i];
        }
        for (int i = 0; i < special.size(); i++) {
            bool valid = true;
            for (int item = 0; item < N; item++) {
                if (needs[item] < special[i][item]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                continue;
            }
            vector<int> temp = needs;
            for (int item = 0; item < N; item++) {
                temp[item] -= special[i][item];
            }
            ans = min(ans, dfs(temp, price, special) + special[i].back());
        }
        memo[needs] = ans;
        return ans;
    }
};

//class Solution {
//public:
//    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
//        return dfs(needs, price, special);
//    }
//
//private:
//    map<vector<int>, int> cache;
//
//    int dfs(vector<int> needs, vector<int> &price, vector<vector<int>> &special) {
//        auto it = cache.find(needs);
//        if (it != cache.end()) {
//            return it->second;
//        }
//        int ans = 0;
//        const int N = needs.size();
//        for (int i = 0; i < N; i++) {
//            ans += price[i] * needs[i];
//        }
//        for (int i = 0; i < special.size(); i++) {
//            vector<int> next = needs;
//            bool valid = true;
//            for (int item = 0; item < N; item++) {
//                if (needs[item] < special[i][item]) {
//                    valid = false;
//                    break;
//                }
//            }
//            if (!valid) {
//                continue;
//            }
//            for (int item = 0; item < N; item++) {
//                next[item] -= special[i][item];
//            }
//            ans = min(ans, dfs(next, price, special) + special[i].back());
//        }
//        cache[needs] = ans;
//        return ans;
//    }
//};

int main() {
    auto f = [](vector<int> &&price, vector<vector<int>> &&special, vector<int> &&needs, int expect) {
        auto output = Solution().shoppingOffers(price, special, needs);
        leetcode_assert(output == expect, "shopping_offers price={} special={} needs={} expect={} output={}", price, special, needs, expect, output);
    };
    f();
}
