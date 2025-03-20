//
// https://leetcode.cn/problems/maximum-consecutive-floors-without-special-floors/?envType=daily-question&envId=2025-01-06
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        const int N = special.size();
        sort(special.begin(), special.end());
        int ans = special.front() - bottom;
        for (int i = 1; i < N; i++) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        ans = max(ans, top - special.back());
        return ans;
    }
};


int main() {
    auto f = [](int bottom, int top, vector<int>&& special, int expect) {
        auto output = Solution().maxConsecutive(bottom, top, special);
        leetcode_assert(output == expect, "maximum_consecutive_floors_without_special_floors bottom={} top={} special={} expect={} output={}", bottom, top, special, expect, output);
    };
    f();
}
