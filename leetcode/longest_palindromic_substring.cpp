//
// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

string longestPalindrome(string s) {
    if (s.size() < 2) {
        return s;
    }
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    const int M = s.size();
    for (int i = 0; i < M; i++) {
        dp[i][i] = true;
    }
    string ans;
    int max_len = 1, start = 0, end = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                dp[j][i] = true;
                if (i - j + 1 > max_len) {
                    max_len = i - j + 1;
                    start = j;
                    end = i;
                }
            }
        }
    }
    return s.substr(start, end - start + 1);
}

int main() {
    auto f = [](string &&s, string expect) {
        auto output = longestPalindrome(s);
        leetcode_assert(output == expect, "longest_palindromic_substring s={} expect={} output={}", s, expect, output);
    };
    f("babad", "bab");
    f("cbbd", "bb");
}
