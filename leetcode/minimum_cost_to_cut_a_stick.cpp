//
// https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/description/?envType=daily-question&envId=2024-11-11
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int> &cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> newCuts(cuts.size() + 2, 0);
        copy(cuts.begin(), cuts.end(), newCuts.begin() + 1);
        newCuts.back() = n;

        const int M = newCuts.size();
        vector<vector<int>> dp(M, vector<int>(M, INT_MAX));
        for (int i = M - 1; i >= 0; i--) {
            for (int j = i + 1; j < M; j++) {
                if (j == i + 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int len = newCuts[j] - newCuts[i];
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int r1 = dp[i][k];
                    int r2 = dp[k][j];
                    if (r1 == INT_MAX || r2 == INT_MAX) {
                        continue;
                    }
                    ans = min(ans, r1 + r2 + len);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][M - 1];
    }
};

class Solution3 {
public:
    int minCost(int n, vector<int> &cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> newCuts(cuts.size() + 2, 0);
        copy(cuts.begin(), cuts.end(), newCuts.begin() + 1);
        newCuts.back() = n;
        return dfs(0, newCuts.size() - 1, newCuts);
    }

private:
    unordered_map<string, int> memo;

    static string getKey(int start, int end) {
        return to_string(start) + to_string(end);
    }

    int dfs(int start, int end, vector<int> &cuts) {
        if (start + 1 == end) {
            return 0;
        }
        string key = getKey(start, end);
        auto it = memo.find(key);
        if (it != memo.end()) {
            return it->second;
        }
        int ans = INT_MAX;
        int len = cuts[end] - cuts[start];
        for (int i = start + 1; i < end; i++) {
            int r1 = dfs(start, i, cuts);
            int r2 = dfs(i, end, cuts);
            if (r1 == INT_MAX || r2 == INT_MAX) {
                continue;
            }
            ans = min(ans, r1 + r2 + len);
        }
        memo[key] = ans;
        return ans;
    }
};

class Solution2 {
public:
    int minCost(int n, vector<int> &cuts) {
        sort(cuts.begin(), cuts.end());
        return dfs(0, n, cuts, 0, cuts.size() - 1);
    }

private:
    unordered_map<string, int> memo;

    static string key(int start, int end, int cutStart, int cutEnd) {
        string res;
        res.append(to_string(start))
            .append(".")
            .append(to_string(end))
            .append(".")
            .append(to_string(cutStart))
            .append(".")
            .append(to_string(cutEnd));
        return res;
    }

    int dfs(int start, int end, vector<int> &cuts, int cutStart, int cutEnd) {
        if (cutStart > cutEnd) {
            return 0;
        }
        if (cutStart == cutEnd) {
            return end - start;
        }
        if (cutStart + 1 == cutEnd) {
            int c1 = cuts[cutStart];
            int c2 = cuts[cutEnd];
            int ans = min(end - c1, c2 - start) + end - start;
            return ans;
        }
        if (start + 1 == end) {
            return 0;
        }
        string k = key(start, end, cutStart, cutEnd);
        auto it = memo.find(k);
        if (it != memo.end()) {
            return it->second;
        }
        int ans = INT_MAX;
        bool findCut = false;
        for (int i = cutStart; i <= cutEnd; i++) {
            int cut = cuts[i];
            if (start < cut && cut < end) {
                findCut = true;

                int r1 = dfs(start, cut, cuts, cutStart, i - 1);
                int r2 = dfs(cut, end, cuts, i + 1, cutEnd);
                if (r1 == INT_MAX || r2 == INT_MAX) {
                    continue;
                }
                ans = min(ans, r1 + r2);
            }
        }
        if (!findCut) {
            memo[k] = 0;
            return 0;
        }
        if (ans == INT_MAX) {
            memo[k] = INT_MAX;
            return ans;
        }
        memo[k] = ans + end - start;
        return ans + end - start;
    }
};

int main() {
    auto f = [](int n, vector<int> &&cuts, int expect) {
        auto output = Solution().minCost(n, cuts);
        leetcode_assert(output == expect, "minimum_cost_to_cut_a_stick n={} cuts={} expect={} output={}", n, cuts,
                        expect, output);
    };
    f(7, {1, 3, 4, 5}, 16);
    //    f(30, {13, 25, 16, 20, 26, 5, 27, 8, 23, 14, 6, 15, 21, 24, 29, 1, 19, 9, 3}, 0);
    //    f(9, {8, 6, 7}, 0);
}
