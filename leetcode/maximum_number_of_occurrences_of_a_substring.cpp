//
// https://leetcode.cn/problems/maximum-number-of-occurrences-of-a-substring/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        const int N = s.size();
        unordered_map<char, int> freq;
        unordered_map<string, int> subStrFreq;
        int left = 0;
        for (int right = 0; right < N; right++) {
            char ch = s[right];
            freq[ch]++;
            int windowSize = right - left + 1;
            while ((freq.size() > maxLetters || windowSize > minSize) && left <= right) {
                char lch = s[left];
                if (freq[lch] == 1) {
                    freq.erase(lch);
                } else {
                    freq[lch]--;
                }
                left++;
                windowSize--;
            }
            if (windowSize >= minSize) {
                subStrFreq[s.substr(left, windowSize)]++;
            }
        }
        int ans = 0;
        for (auto &&[k, v] : subStrFreq) {
            ans = max(ans, v);
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        fmt::println("s={}", s);
        const int N = s.size();
        int ans = 0;
        unordered_map<char, int> freq;
        int left = 0;
        for (int right = 0; right < N; right++) {
            char ch = s[right];
            freq[ch]++;
            int windowSize = right - left + 1;
            fmt::println("left={} right={} ch={} freq={}", left, right, ch, freq);
            while ((freq.size() > maxLetters || windowSize > maxSize) && left <= right) {
                char lch = s[left];
                if (freq[lch] == 1) {
                    freq.erase(lch);
                } else {
                    freq[lch]--;
                }
                windowSize--;
            }
            fmt::println("  windowSize={} left={} freq={}", windowSize, left, freq);
            if (windowSize >= minSize) {
                ans += windowSize - minSize + 1;
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](string s, int maxLetters, int minSize, int maxSize, int expect) {
        auto output = Solution().maxFreq(s, maxLetters, minSize, maxSize);
        leetcode_assert(
            output == expect,
            "maximum_number_of_occurrences_of_a_substring s={} maxLetters={} minSize={} maxSize={} expect={} output={}",
            s, maxLetters, minSize, maxSize, expect, output);
    };
//    f("aababcaab", 2, 3, 4, 2);
    f("aaaa", 1, 3, 3, 2);
}
