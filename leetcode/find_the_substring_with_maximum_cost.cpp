//
// https://leetcode.cn/problems/find-the-substring-with-maximum-cost/description/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        const int N = s.size();
        vector<int> arr(N, 0);
//        unordered_set<char> dict(chars.begin(), chars.end());
        unordered_map<char, int> dict;
        for (int i = 0; i < chars.size(); i++) {
            dict[chars[i]] = i;
        }
        for (int i = 0; i < N; i++) {
            char ch = s[i];
            if (dict.contains(ch)) {
                arr[i] = vals[dict[ch]];
            } else {
                arr[i] = ch - 'a' + 1;
            }
        }

        vector<int> dp(N);
        dp[0] = arr[0];
        int ans = max(0, arr[0]);
        for (int i = 1; i < N; i++) {
            if (dp[i - 1] >= 0) {
                dp[i] = dp[i - 1] + arr[i];
            } else {
                dp[i] = arr[i];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


int main() {
    auto f = [](string s, string chars, vector<int>&& vals, int expect) {
        auto output = Solution().maximumCostSubstring(s, chars, vals);
        leetcode_assert(output == expect, "find_the_substring_with_maximum_cost s={} chars={} vals={} expect={} output={}", s, chars, vals, expect, output);
    };
    f();
}
