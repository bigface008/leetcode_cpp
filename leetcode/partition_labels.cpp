//
// https://leetcode.com/problems/partition-labels/?envType=daily-question&envId=2025-03-30
//

#include "iostream"
#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int N = s.size();
        const int M = 26;
        vector<int> last(M, 0);
        for (int i = 0; i < N; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < N; i++) {
            end = max(end, last[s[i] - 'a']);
            if (end == i) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};


//class Solution {
//public:
//    vector<int> partitionLabels(string s) {
//        N = s.size();
//        this->s = s;
//        ch_pre_sum.resize(26, vector<int>(N + 1, 0));
//        for (int i = 0; i < N; i++) {
//            char ch = s[i];
//            if (pos_mp.contains(ch)) {
//                pos_mp[ch].second = i;
//            } else {
//                pos_mp[ch] = {i, i};
//            }
//            for (int j = 0; j < 26; j++) {
//                ch_pre_sum[j][i + 1] = ch_pre_sum[j][i] + (j + 'a' == ch ? 1 : 0);
//            }
//        }
//        int i = 0;
//        vector<int> ans;
//        while (i < N) {
//            auto [l, r] = dfs(s[i]);
//            ans.push_back(r - l + 1);
//            if (i == r + 1) {
//                i++;
//            } else {
//                i = r + 1;
//            }
//        }
//        return ans;
//    }
//
//private:
//    unordered_map<char, pair<int, int>> pos_mp;
//    vector<vector<int>> ch_pre_sum;
//    string s;
//    int N;
//
//    pair<int, int> dfs(char ch) {
////        fmt::println("ch={}", ch);
//        auto [l, r] = pos_mp[ch];
//        if (r == N - 1) {
//            return {l, r};
//        }
//        int right_most = r;
//        for (int chi = 0; chi < 26; chi++) {
//            if (chi != ch - 'a' && ch_pre_sum[chi][r + 1] != ch_pre_sum[chi][l]) {
//                char nch = 'a' + chi;
//                auto [nl, nr] = pos_mp[nch];
//                if (nr <= r) {
//                    continue;
//                }
//                if (nr == N - 1) {
//                    right_most = N - 1;
//                    continue;
//                }
//                auto res = dfs(nch);
//                right_most = max(right_most, res.second);
//                if (right_most == N - 1) {
//                    break;
//                }
//            }
//        }
//        return {l, right_most};
//    }
//};


int main() {
    auto f = [](string s, vector<int> expect) {
        auto output = Solution().partitionLabels(s);
        leetcode_assert(output == expect, "partition_labels s={} expect={} output={}", s, expect, output);
    };
//    f("ababcbacadefegdehijhklij", {9, 7, 8});
    f("caedbdedda", {1, 9});
}
