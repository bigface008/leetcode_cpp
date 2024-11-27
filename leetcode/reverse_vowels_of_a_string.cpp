//
// https://leetcode.com/problems/reverse-vowels-of-a-string/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        const int N = s.size();
        vector<int> vowels;
        for (int i = 0; i < N; i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u'
                || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels.push_back(i);
            }
        }
        string ans(s);
        for (int i = 0; i < vowels.size() / 2; i++) {
//            char tmp = ans[vowels[i]];
//            ans[vowels[i]] = ans[vowels[vowels.size() - 1 - i]];
//            ans[vowels[vowels.size() - 1 - i]] = tmp;
            swap(ans[vowels[i]], ans[vowels[vowels.size() - 1 - i]]);
        }
        return ans;
    }
};


int main() {
//    auto f = [](string s, string expect) {
//        auto output = Solution().reverseVowels(s);
//        leetcode_assert(output == expect, "reverse_vowels_of_a_string s={} expect={} output={}", s, expect, output);
//    };
//    f("IceCreAm", "AceCreIm");

    vector<int> v1{1, 2, 3, 4, 5};
    swap(v1[0], v1[3]);
    fmt::println("{}", v1);
}
