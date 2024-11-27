//
// https://leetcode.cn/problems/alternating-groups-i/description/?envType=daily-question&envId=2024-11-26
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        const int N = colors.size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int i1 = (i + 1) % N;
            int i2 = (i + 2) % N;
            if ((colors[i] == 0 && colors[i1] == 1 && colors[i2] == 0)
                || (colors[i] == 1 && colors[i1] == 0 && colors[i2] == 1)) {
                ans++;
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& colors, int expect) {
        auto output = Solution().numberOfAlternatingGroups(colors);
        leetcode_assert(output == expect, "alternating_groups_i colors={} expect={} output={}", colors, expect, output);
    };
    f();
}
