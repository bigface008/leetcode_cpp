//
// https://leetcode.cn/problems/find-the-number-of-winning-players/?envType=daily-question&envId=2024-11-23
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<unordered_map<int, int>> cnt(n, unordered_map<int, int>());
        unordered_set<int> winners;
        for (auto& p : pick) {
            int x = p[0], y = p[1];
            cnt[x][y]++;
            if (cnt[x][y] >= x + 1) {
                winners.insert(x);
            }
        }
        return winners.size();
    }
};


int main() {
    auto f = [](int n, vector<vector<int>>&& pick, int expect) {
        auto output = Solution().winningPlayerCount(n, pick);
        leetcode_assert(output == expect, "find_the_number_of_winning_players n={} pick={} expect={} output={}", n, pick, expect, output);
    };
    f();
}
