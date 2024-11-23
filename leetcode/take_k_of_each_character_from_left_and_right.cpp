//
// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/?envType=daily-question&envId=2024-11-20
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        const int N = s.size();
        vector<int> counter(3, 0);
        for (char ch : s) {
            counter[ch - 'a']++;
        }
        if (any_of(counter.begin(), counter.end(), [=](int cnt) { return cnt < k; })) {
            return -1;
        }
        int left = 0;
        int ans = N;
        vector<int> windowCounter(3, 0);
        for (int right = 0; right < N; right++) {
            char ch = s[right];
            windowCounter[ch - 'a']++;
            while (true) {
                int c0 = counter[0] - windowCounter[0];
                int c1 = counter[1] - windowCounter[1];
                int c2 = counter[2] - windowCounter[2];
                if (c0 >= k && c1 >= k && c2 >= k) {
                    break;
                }
                char lch = s[left];
                windowCounter[lch - 'a']--;
                left++;
            }
            ans = min(ans, N - (right - left + 1));
        }
        return ans;
    }
};

class Solution2 {
public:
    int takeCharacters(string s, int k) {
        const int N = s.size();
        if (3 * k > N) {
            return -1;
        }
        vector<int> remain{k, k, k};
        backtrack(s, 0, N - 1, remain);
        return ans == INT_MAX ? -1 : ans;
    }

private:
    int ans = INT_MAX;

    void backtrack(string &s, int start, int end, vector<int> &remain) {
        if (remain[0] == 0 && remain[1] == 0 && remain[2] == 0) {
            ans = min(ans, (int)s.size() - end - 1 + start);
            return;
        }
        if (end - start + 1 < remain[0] + remain[1] + remain[2]) {
            return;
        }
        int i1 = s[start] - 'a';
        int i2 = s[end] - 'a';
        bool recover1 = false;
        bool recover2 = false;
        if (remain[i1] > 0) {
            remain[i1]--;
            recover1 = true;
        }
        backtrack(s, start + 1, end, remain);
        if (recover1) {
            remain[i1]++;
        }
        if (remain[i2] > 0) {
            remain[i2]--;
            recover2 = true;
        }
        backtrack(s, start, end - 1, remain);
        if (recover2) {
            remain[i2]++;
        }
    }

    //    int dfs(string s, int start, int end, vector<int> &remain, int cnt) {
    //        if (end - start + 1 < remain[0] + remain[1] + remain[2]) {
    //            return INT_MAX;
    //        }
    //        int i1 = s[start] - 'a';
    //        int ans = INT_MAX;
    //        if (remain[i1] > 0) {
    //            remain[i1]--;
    //            ans = dfs(s, start + 1, end, remain);
    //            remain[i1]++;
    //        }
    //        int i2 = s[end] - 'a';
    //        if (remain[i2] > 0) {
    //            remain[i2]--;
    //            ans = min(ans, dfs(s, start, end - 1, remain));
    //            remain[i2]++;
    //        }
    //
    //        return ans;
    //    }
};


int main() {
    auto f = [](string s, int k, int expect) {
        auto output = Solution().takeCharacters(s, k);
        leetcode_assert(output == expect, "take_k_of_each_character_from_left_and_right s={} k={} expect={} output={}",
                        s, k, expect, output);
    };
    f("caaa", 1, -1);
}
