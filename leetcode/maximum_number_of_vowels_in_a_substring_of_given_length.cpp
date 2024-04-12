//
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int maxVowels(string s, int k) {
    vector<char> v{'a', 'e', 'i', 'o', 'u'};
    set<char> vowel(v.begin(), v.end());
    vector<int> vowel_indices;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (vowel.contains(s[i])) {
            vowel_indices.push_back(i);
            if (i - vowel_indices[0] + 1 > k) {
                vowel_indices.erase(vowel_indices.begin());
            }
            ans = max(ans, (int)vowel_indices.size());
        }
    }
    return ans;
}

int main() {
    auto f = [](string &&s, int k, int expect) {
        auto output = maxVowels(s, k);
        leetcode_assert(output == expect, "maximum_number_of_vowels_in_a_substring_of_given_length s={} k={} expect={} output={}", s, k, expect, output);
    };
    f("abciiidef", 3, 3);
    f("aeiou", 2, 2);
    f("leetcode", 3, 2);
}
