//
// https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/?envType=daily-question&envId=2025-03-27
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        const int N = s.size();
        if (N == 1) {
            return 0;
        }
        vector<vector<long long>> prefix(N, vector<long long>(2));
        vector<vector<long long>> suffix(N, vector<long long>(2));
        prefix[0][1] = s[0] == '0';
        prefix[0][0] = s[0] == '1';
        suffix[N - 1][1] = s[N - 1] == '0';
        suffix[N - 1][0] = s[N - 1] == '1';
        for (int i = 1; i <= N - 2; i++) {
            if (s[i] == '1') {
                prefix[i][1] = min(prefix[i - 1][1], prefix[i - 1][0] + i);
                prefix[i][0] = min(prefix[i - 1][0] + i + i + 1, prefix[i - 1][1] + i + 1);
            } else {
                prefix[i][0] = min(prefix[i - 1][0], prefix[i - 1][1] + i);
                prefix[i][1] = min(prefix[i - 1][1] + i + i + 1, prefix[i - 1][0] + i + 1);
            }
        }
        for (int i = N - 2; i >= 0; i--) {
            if (s[i] == '1') {
                suffix[i][1] = min(suffix[i + 1][1], suffix[i + 1][0] + N - i - 1);
                suffix[i][0] = min(suffix[i + 1][0] + N - i + N - i - 1, suffix[i + 1][1] + N - i);
            } else {
                suffix[i][0] = min(suffix[i + 1][0], suffix[i + 1][1] + N - i - 1);
                suffix[i][1] = min(suffix[i + 1][1] + N - i + N - i - 1, suffix[i + 1][0] + N - i);
            }
        }
        long long ans = LONG_LONG_MAX;
        for (int i = 0; i <= N - 2; i++) {
            long long a = prefix[i][0] + suffix[i + 1][0];
            long long b = prefix[i][1] + suffix[i + 1][1];
            ans = min(ans, a);
            ans = min(ans, b);
        }
        return ans;
    }
};


int main() {
    auto f = [](string s, long long expect) {
        auto output = Solution().minimumCost(s);
        leetcode_assert(output == expect, "minimum_cost_to_make_all_characters_equal s={} expect={} output={}", s,
                        expect, output);
    };
//    f("0011", 2);
    f("0", 0);
}
