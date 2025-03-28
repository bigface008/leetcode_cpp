//
// https://leetcode.cn/problems/minimize-string-length/?envType=daily-question&envId=2025-03-28
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> st;
        for (char ch : s) {
            st.insert(ch);
        }
        return st.size();
    }
};


int main() {
    auto f = [](string s, int expect) {
        auto output = Solution().minimizedStringLength(s);
        leetcode_assert(output == expect, "minimize_string_length s={} expect={} output={}", s, expect, output);
    };
    f("baadccab", 4);
}
