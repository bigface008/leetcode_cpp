//
// https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

string mergeAlternately(string word1, string word2) {
    string res(word1.size() + word2.size(), 0);
    int cnt = 0;
    int i = 0, j = 0;
    while (i < word1.size() && j < word2.size()) {
        res[cnt] = word1[i];
        cnt++;
        res[cnt] = word2[j];
        cnt++;
        i++;
        j++;
    }
    while (i < word1.size()) {
        res[cnt] = word1[i];
        cnt++;
        i++;
    }
    while (j < word2.size()) {
        res[cnt] = word2[j];
        cnt++;
        j++;
    }
    return res;
}

int main() {
    auto f = [](string &&word1, string &&word2, string &&expect) {
        auto output = mergeAlternately(word1, word2);
        leetcode_assert(output == expect, "merge_strings_alternately word1={} word2={} expect={} output={}", word1, word2, expect, output);
    };
    f("abc", "pqr", "apbqcr");
    f("ab", "pqrs", "apbqrs");
    f("abcd", "pq", "apbqcd");
}
