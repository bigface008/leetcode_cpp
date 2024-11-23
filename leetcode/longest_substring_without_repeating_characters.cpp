//
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.size();
        unordered_set<char> letters;
        int left = 0, right = 0;
        for (; right < N; right++) {
            char ch = s[right];
            if (letters.contains(ch)) {
                break;
            }
            letters.insert(ch);
        }
        int ans = right;
        for (; right < N; right++) {
            char ch = s[right];
            while (letters.contains(ch)) {
                letters.erase(s[left]);
                left++;
            }
            letters.insert(ch);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


int main() {
    auto f = [](string s, int expect) {
        auto output = Solution().lengthOfLongestSubstring(s);
        leetcode_assert(output == expect, "longest_substring_without_repeating_characters s={} expect={} output={}", s, expect, output);
    };
//    f("abcabcbb", 3);
    f("aab", 2);
}
