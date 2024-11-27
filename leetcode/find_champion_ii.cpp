//
// https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            inDegree[v]++;
        }
        int cnt = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                cnt++;
                ans = i;
            }
        }
        if (cnt == 1) {
            return ans;
        } else {
            return -1;
        }
    }
};


int main() {
    auto f = [](int n, vector<vector<int>>&& edges, int expect) {
        auto output = Solution().findChampion(n, edges);
        leetcode_assert(output == expect, "find_champion_ii n={} edges={} expect={} output={}", n, edges, expect, output);
    };
    f();
}
