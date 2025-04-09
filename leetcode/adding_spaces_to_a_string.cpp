//
// https://leetcode.cn/problems/adding-spaces-to-a-string/?envType=daily-question&envId=2025-03-30
//

#include "leetcode_utils.hpp"
#include <sstream>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int N = s.size();
        int i = 0, j = 0;
        stringstream ss;
        for (; i < N; i++) {
            if (j < spaces.size() && i == spaces[j]) {
                ss << ' ';
                j++;
            }
            ss << s[i];
        }
        return ss.str();
    }
};


int main() {
    auto f = [](string s, vector<int>&& spaces, string expect) {
        auto output = Solution().addSpaces(s, spaces);
        leetcode_assert(output == expect, "adding_spaces_to_a_string s={} spaces={} expect={} output={}", s, spaces, expect, output);
    };
    f();
}
