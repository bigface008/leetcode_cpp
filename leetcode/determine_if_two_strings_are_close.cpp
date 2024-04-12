//
// https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) {
        return false;
    }
    const int LEN = 26;
    vector<int> v1(LEN, 0), v2(LEN, 0);
    for (int i = 0; i < word1.size(); i++) {
        v1[word1[i] - 'a']++;
        v2[word2[i] - 'a']++;
    }
    for (int i = 0; i < LEN; i++) {
        if (v1[i] > 0 && v2[i] == 0) {
            return false;
        }
        if (v2[i] > 0 && v1[i] == 0) {
            return false;
        }
    }
    sort(v1.begin(), v1.end(), greater<>());
    sort(v2.begin(), v2.end(), greater<>());
    for (int i = 0; i < LEN; i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

bool closeStringsV2(string word1, string word2) {
    vector<int> freq1(26), freq2(26);
    for (auto chr : word1) {
        freq1[chr - 'a']++;
    }
    for (auto chr : word2) {
        freq2[chr - 'a']++;
    }
    for (int indx = 0; indx < 26; indx++) {
        if (freq1[indx] > 0 && freq2[indx] == 0)
            return false;
        else if (freq2[indx] > 0 && freq1[indx] == 0)
            return false;
    }
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());
    for (int indx = 0; indx < 26; indx++) {
        if (freq1[indx] != freq2[indx]) {
            return false;
        }
    }
    return true;
}

int main() {
    auto f = [](string &&word1, string &&word2, bool expect) {
        auto output = closeStringsV2(word1, word2);
        leetcode_assert(output == expect, "determine_if_two_strings_are_close word1={} word2={} expect={} output={}",
                        word1, word2, expect, output);
    };
    //    f("abc", "bca", true);
    //    f("a", "aa", false);
    //    f("cabbba", "abbccc", true);
//    f("aaabbbbccddeeeeefffff", "aaaaabbcccdddeeeeffff", false);
    f("cabbba", "aabbss", false);
}
