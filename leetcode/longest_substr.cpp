//
// Created by 汪喆昊 on 2024/3/27.
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//

#include "leetcode_utils.hpp"

using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char, int> charIdxMap;
    int len = 0;
    int maxLen = 0;
    int start = 0, end = 0;
    while (end < s.size()) {
        auto c = s[end];
        if (charIdxMap.find(c) == charIdxMap.end()) {
            charIdxMap[c] = end;
            len += 1;
            maxLen = max(maxLen, len);
            ++end;
        } else {
            // find the idx of duplicated char.
            int dupIdx = charIdxMap[c];
            len -= dupIdx - start;
            for (int i = start; i <= dupIdx; ++i) {
                charIdxMap.erase(s[i]);
            }
            start = dupIdx + 1;
            charIdxMap[c] = end;
            ++end;
        }
    }
    return maxLen;
}

int main() {
    auto f = [&](string &&s, int expect) {
        int output = lengthOfLongestSubstring(s);
        leetcode_assert(output == expect, "length of longest substring s {} expect {} output {}", s, expect, output);
    };

    f("abcabcbb", 3);
    f("bbbbb", 1);
    f("pwwkew", 3);
    f("dvdf", 3);
    f("tmmzuxt", 5);
    f("bbtablud", 6);
}
